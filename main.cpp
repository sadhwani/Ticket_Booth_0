#include <iostream>
#include <string>
#include <cassert>
#include "tinyxml.h"
#include "Venue_from_Xml.h"
#include "Venue.h"
#include "CommandProcessor.h"
#include "Menu.h"
using namespace std;


int main(void)
{

	//Venue* venue;
	Venue* venues[1000];
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
	
	 TiXmlNode* venue_node = venue_file_node->FirstChild();
	  assert(venue_node != 0);
	
	//initializes venue array
	int i = 0;

	while (venue_node != 0) {
		venues[i] = Venue_from_Xml::Get_Venue(venue_node);
		venue_node = venue_node->NextSibling();
		i++;
	}
	int num_venues = i;

	
	CommandProcessor::Process_Commands(venues,num_venues);
	cout << "Normal Termination\n";
	cin.get();
	cin.get();
	return 0;
	
}

