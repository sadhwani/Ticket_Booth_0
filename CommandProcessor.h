/*#pragma once
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
*/

#pragma once
#include <string>
#include "Menu.h"
#include "Venue.h"
enum Command_States { Initial, Venue_Option, Venue_Selected,  Done };
using namespace std;

class CommandProcessor
{
public:
	static void Process_Commands(Venue **venues, int num_venues);

private:
	static const int NR_CMD_STATES = (int)Done + 1;
	static Command_States command_state;
	static Menu* menus[NR_CMD_STATES];

	static void Create_Menus(Venue **venues, int num_venues);
	static void Process_Initial_Cmd(const string& cmd);
	static void Process_Venue_Selected_Cmd(const string& cmd);

	static void Select_Venue();
	static Venue** venues;
	static int nr_venues;
	static Venue* selected_venue;



	CommandProcessor(void) {};
};
