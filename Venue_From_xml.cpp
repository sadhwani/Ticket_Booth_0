#include <iostream>
#include "Venue_from_Xml.h"
#include "tinyxml.h"
#include <sstream>
#define MAX_SEATS 1000

using namespace std;

void Venue_From_xml::Get_Venue(TiXmlNode* venue_node)
{

	TiXmlNode* name_node = venue_node->FirstChild();
	assert(name_node != 0);
	//cout << name_node->Value() << endl;

	TiXmlNode* name_text_node = name_node->FirstChild();
	assert(name_text_node != 0);
	//cout << name_text_node->Value() << endl;

	TiXmlNode* address_node = name_node->NextSibling();
	assert(address_node != 0);
	//cout << address_node->Value() << endl;
	Address* address = Get_Address(address_node);

	Venue *venue = new Venue(name_node->FirstChild()->Value(), *address);

	TiXmlNode* seat_row_node = address_node->NextSibling();
	assert(seat_row_node != 0);
	Get_Seats(seat_row_node,venue);
    
   
	venue->Display();
    
  
	
	/* Still need to add collection of Seat_Rows and Sections to Venue
        Give Seat_Row Add_Seat method
        Implement Section
        Give Section Add_Seat method
     */

}

Address* Venue_From_xml::Get_Address(TiXmlNode* address_node)
{
	TiXmlNode* street_node = address_node->FirstChild();
	assert(street_node != 0);
	//cout << street_node->FirstChild()->Value() << endl;

	TiXmlNode* city_node = street_node->NextSibling();
	assert(city_node != 0);
	//cout << city_node->FirstChild()->Value() << endl;

	TiXmlNode* state_node = city_node->NextSibling();
	assert(state_node != 0);
	//cout << state_node->FirstChild()->Value() << endl;

	TiXmlNode* zip_code = state_node->NextSibling();
	assert(zip_code != 0);
	//cout << zip_code->FirstChild()->Value() << endl;
    
    // Converting zip code to integer
    stringstream strValue;
    strValue << zip_code->FirstChild()->Value();
    int zipCode;
    strValue >> zipCode;
    
    Address *address = new Address(street_node->FirstChild()->Value(), city_node->FirstChild()->Value(), state_node->FirstChild()->Value(), zipCode);
    //address->Display(); //fefjdhgfjdshfjkhdkfjsdf
    return address;
}

Seat_Row* Venue_From_xml::Get_Seat_Row(TiXmlNode* seat_row_node)
{
	
	TiXmlNode* name_node = seat_row_node->FirstChild("name");
	assert(name_node != 0);
	

    TiXmlNode* seat_node = seat_row_node->FirstChild("seat");
	int numberOfSeats = 0;
	
	Seat_Row *seatRow = new Seat_Row(name_node->FirstChild()->Value(), numberOfSeats);  // creates seat_row object to be added to venue later
	
	while (seat_node != 0)
	{

		Seat *seat = Get_Seat(seat_node);
		
		seatRow->Add_Seat(seat); //adds seat objects created in Get_Seat to the current seat row object
		
		seat_node = seat_node->NextSibling();
		
	}
    return seatRow;

}

void Venue_From_xml::Get_Seats(TiXmlNode* seat_row_node, Venue* venue)
{
	while (seat_row_node != 0)
	{
		
		venue->Add_Row(Get_Seat_Row(seat_row_node));   // Adds the seat row created in Get_Seat_Row to venue's array of seat rows
		seat_row_node = seat_row_node->NextSibling();


	}
}


// This method  still needs some work with the whole section thing
Seat* Venue_From_xml::Get_Seat(TiXmlNode* seat_node)
{
	TiXmlNode* number_node = seat_node->FirstChild("number");
//	cout << number_node->Value() << ": ";
//	cout << number_node->FirstChild()->Value() << " ";
    
	TiXmlNode* section_node = seat_node->FirstChild("section");
//	cout << section_node->Value() << ": ";
//	cout << section_node->FirstChild()->Value() << endl;
    
    // Grabbing Seat Row Name
    TiXmlNode* seat_row_node = seat_node->Parent()->FirstChild("name");

    // Converting value of seat number to int from const char *
    stringstream strValue;
    strValue << number_node->FirstChild()->Value();
    int rowNumber;
    strValue >> rowNumber;

    Seat *seat = new Seat(seat_row_node->FirstChild()->Value(), rowNumber, section_node->FirstChild()->Value());
   
	//seat->Display(); for now
   
	return seat;
}


