#include <iostream>
#include "CommandProcessor.h"
#include "Venue.h"
using namespace std;

Command_States CommandProcessor:: command_state = Initial;

Menu* CommandProcessor::menus[NR_CMD_STATES];
Venue** CommandProcessor::venues = 0;
int CommandProcessor::nr_venues = 0;
Venue* CommandProcessor::selected_venue = 0;


void CommandProcessor::Process_Commands(Venue **venues_, int num_venues_)
{
	cout << "Process commands starting\n";

	venues  = venues_;
	nr_venues = num_venues_;

	Create_Menus(venues,num_venues_);
	
	while (command_state != Done)
	{
		if (command_state == Venue_Option)
		{
			cout << "Selected venue is "
				<< selected_venue->Name() << endl;
		}
		const string* cmd = menus[command_state]->Get_Command();

		switch (command_state)
		{
		case Initial:   Process_Initial_Cmd(*cmd);
			break;

		case Venue_Selected:    Process_Venue_Selected_Cmd(*cmd);
			break;

		case Venue_Option: Process_Venue_Selected_Cmd(*cmd);

		case Done:  break;      // Can't happen
		}
	}

	cout << "Command_Processor exiting\n";
	// Process command in Initial command state

}
	void CommandProcessor::Process_Initial_Cmd(const string& cmd)
	{
		if (cmd == "Select Venue")
		{
			Select_Venue();
			//command_state = Venue_Option;
			command_state = Venue_Selected;
		}
		
		else
		{
			cout << "Quit command\n";
			command_state = Done;
		}
	}

	// Process command in State Selected command state
	void CommandProcessor::Process_Venue_Selected_Cmd(const string& cmd)
	{
		if (cmd == "Display Venue")
		{
			selected_venue->Display_All();
		}
		else if (cmd == "Change Venue")
		{
			
			command_state = Initial;
		}

		else if (cmd == "Select Show")
		{
			cout << "Select_Show called\n";
		}
		else
		{
			cout << "Quit command\n";
			command_state = Done;
		}
	}

	 void CommandProcessor::Select_Venue()
	{
		Menu* menu = new Menu("Select Venue");
		
		for (int i = 0; i < nr_venues; ++i)
		{
			menu->Add_Command(venues[i]->Name());
			
		}

		const string* venue_name = menu->Get_Command();

		// Find Venue with this name
		for (int i = 0; i < nr_venues; ++i)
		{
			if (venues[i]->Name() == *venue_name)
			{
				selected_venue = venues[i];
				//command_state = Venue_Selected; 
				command_state = Venue_Option;
				return;
			}
		}
		// Should never reach this point.
		cout << "Error in Command_Processor::Select_State()\n";
	}


void CommandProcessor::Create_Menus(Venue **venues, int num_venues)
{
	// Menu for Initial command state
	Menu* menu = new Menu("Enter command number");
	menu->Add_Command("Select Venue");
	menu->Add_Command("Quit");
	menus[Initial] = menu;

	// Menu for Venue Selected
	menu = new Menu("Select Venue");
	
	for (int i = 0; i < num_venues; i++)
	{
		menu->Add_Command(venues[i]->Name());
	}
	menu->Add_Command("Cancel");
	menus[Venue_Option] = menu;

	menu = new Menu("Enter command number");
	menu->Add_Command("Display Venue");
	menu->Add_Command("Select Show");
	menu->Add_Command("Change Venue");
	menu->Add_Command("Quit");
	menus[Venue_Selected] = menu;
}
