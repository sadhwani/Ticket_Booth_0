#pragma once
#include "tinyxml.h"
#include "Seat_Row.h"
#include "Seat.h"
#include "Address.h"
#include "Venue.h"

static class Venue_From_xml
{
public:

	static void Get_Venue(TiXmlNode* venue_node);
	
private:
	static Address* Get_Address(TiXmlNode* address_node);
	static Seat_Row* Get_Seat_Row(TiXmlNode* seat_row_node, Venue *venue);
	static void Get_Seats(TiXmlNode* seat_row_node, Venue* venue);
	static Seat* Get_Seat(TiXmlNode* seat_node, Venue *venue);
	Venue_From_xml();
	~Venue_From_xml();
};

