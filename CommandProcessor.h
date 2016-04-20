#pragma once
#include <iostream>
#include "Venue_from_Xml.h"

class CommandProcessor {
private:
    TiXmlNode* venue_file_node;
public:
    CommandProcessor(TiXmlNode* venue_file_node);
    void firstLevel(TiXmlNode* venue_file_node, Venue** venues);
    void secondLevel(Venue** venues, int numOfVenues);
    void venueOptions(Venue** venues, int venueNumber);
    int quit();

};