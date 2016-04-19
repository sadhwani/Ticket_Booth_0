#include <iostream>
#include <cstdlib>
#include "Venue_from_Xml.h"
#include "tinyxml.h"
using namespace std;

Address* Venue_from_Xml::Get_Address(TiXmlNode* address_node)
{
    Address* address;
    TiXmlNode* street_node = address_node->FirstChild();
    assert(street_node != 0);
    //cout << street_node->FirstChild()->Value() << endl;
    string street(street_node->FirstChild()->Value());

    TiXmlNode* city_node = street_node->NextSibling();
    assert(city_node != 0);
    //cout << city_node->FirstChild()->Value() << endl;
    string city(city_node->FirstChild()->Value() );

    TiXmlNode* state_node = city_node->NextSibling();
    assert(state_node != 0);
    //cout << state_node->FirstChild()->Value() << endl;
    string state(state_node->FirstChild()->Value());

    TiXmlNode* zip_code_node = state_node->NextSibling();
    assert(zip_code_node != 0);
    //cout << zip_code_node->FirstChild()->Value() << endl;

    int zip_code;
    zip_code = atoi( (char*) (zip_code_node->FirstChild()->Value()));

    address = new Address(street, city, state, zip_code);
    return address;
}


Seat* Venue_from_Xml::Get_Seat(TiXmlNode* seat_node, const string& row_name)
{
    TiXmlNode* number_node = seat_node->FirstChild("number");
    //cout << number_node->Value() << ": ";
    //cout << number_node->FirstChild()->Value() << " ";
    int seat_number = atoi(number_node->FirstChild()->Value());

    TiXmlNode* section_node = seat_node->FirstChild("section");
    //cout << section_node->Value() << ": ";
    //cout << section_node->FirstChild()->Value() << endl;
    string section_name = section_node->FirstChild()->Value();

    Seat* seat = new Seat(row_name, seat_number, section_name);
    return seat;
}

Seat_Row* Venue_from_Xml::Get_Seat_Row(TiXmlNode* seat_row_node)
{
    Seat* seat;
    Seat_Row* seat_row;
    string row_name;

    TiXmlNode* name_node = seat_row_node->FirstChild("name");
    assert(name_node != 0);
    //cout << name_node->Value() << ": ";
    //cout << name_node->FirstChild()->Value() << endl;
    row_name = name_node->FirstChild()->Value();
    seat_row = new Seat_Row(row_name);

    TiXmlNode* seat_node = seat_row_node->FirstChild("seat");
    while (seat_node != 0)
    {
        //cout << seat_node->Value() << " ";
        seat = Get_Seat(seat_node, row_name);
        seat_row->Add_Seat(seat);
        seat_node = seat_node->NextSibling();
    }
    return seat_row;
}

void Venue_from_Xml::Get_Seats(TiXmlNode* seat_row_node, Venue* venue)
{
    Seat_Row* seat_row;
    while (seat_row_node != 0)
    {
        //cout << seat_row_node->Value() << ": ";
        seat_row = Get_Seat_Row(seat_row_node);
        venue->Add_Row(seat_row);
        seat_row_node = seat_row_node->NextSibling();
    }
}

Venue* Venue_from_Xml::Get_Venue(TiXmlNode* venue_node)
{
    Venue* venue;
    Address* venue_address;
    string venue_name;

    TiXmlNode* name_node = venue_node->FirstChild();  
    assert(name_node != 0);
    //cout << name_node->Value() << endl;
    
    TiXmlNode* name_text_node = name_node->FirstChild();    
    assert(name_text_node != 0);
    //cout << name_text_node->Value() << endl;
    venue_name = name_text_node->Value();

    TiXmlNode* address_node = name_node->NextSibling();
    assert(address_node != 0);
    //cout << address_node->Value() << endl;

    venue_address = Get_Address(address_node);
    venue = new Venue(venue_name, *venue_address);

    TiXmlNode* seat_row_node = venue_node->FirstChild("seat_row");
    assert(seat_row_node != 0);
    //cout << seat_row_node->Value() << endl;
    Venue_from_Xml::Get_Seats(seat_row_node, venue);

    return venue;
}
