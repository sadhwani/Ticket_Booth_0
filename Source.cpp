#include <iostream>
#include <string>
#include <cassert>
#include "tinyxml.h"
#include "Venue_From_xml.h"

using namespace std;
int main()
{
	cout << "This is venue_test\n";
	string filename = "Venue.xml";
	TiXmlDocument doc(filename);

	bool loadOkay = doc.LoadFile();
	if (!loadOkay)
	{
		cout << "Could not load file " << filename << endl;
		cout << "Error='" << doc.ErrorDesc() << "'. Exiting.\n";
		cin.get();
		exit(1);
	}
	cout << filename << " read from disk " << endl;
	cout << "Printing via doc.Print \n";
	//doc.Print(stdout);


	TiXmlNode* venue_file_node = doc.FirstChild("venue_file");
	assert(venue_file_node != 0);
	cout << venue_file_node->Value() << endl;

	TiXmlNode* venue_node = venue_file_node->FirstChild(); //navigates DOM
	assert(venue_node != 0);
	cout << venue_node->Value() << endl;

	Venue_From_xml::Get_Venue(venue_node);


	cin.get();
	cin.get();
	return 0;
}
