#include <iostream>
#include <string>
#include <cassert>
#include "tinyxml.h"
#include "Venue_from_Xml.h"
#include "Venue.h"
#include "CommandProcessor.h"

using namespace std;

int main(void)
{
    //Venue* venue;
    Venue* venues[1000];

    //cout << "This is Ticket_Booth_0\n\n";
    //string filename = "Venue.xml";
    string filename = "Venues.xml";
    TiXmlDocument doc(filename);

    bool loadOkay = doc.LoadFile();
    if (!loadOkay)
    {
        cout << "Could not load file " << filename << endl;
        cout << "Error='" << doc.ErrorDesc() <<"'. Exiting.\n";
        cin.get();
        exit( 1 );
    }

    TiXmlNode* venue_file_node = doc.FirstChild("venue_file");
    assert(venue_file_node != 0);
    //cout << venue_file_node->Value() << endl;
    
    //Activate Command Processor
    CommandProcessor *processor = new CommandProcessor(venue_file_node);
    processor->firstLevel(venue_file_node, venues);
    
    
//    TiXmlNode* venue_node = venue_file_node->FirstChild();
//    assert(venue_node != 0);
//    //cout << venue_node->Value() << endl;
//    int i = 0;
//    while(venue_node!= 0) {
//        venues[i] = Venue_from_Xml::Get_Venue(venue_node);
//        venue_node = venue_node->NextSibling();
//        venues[i]->Display_All();
//    }
    //venue = Venue_from_Xml::Get_Venue(venue_node);

    //venue->Display_All();
    cin.get();
    return 0;
}
