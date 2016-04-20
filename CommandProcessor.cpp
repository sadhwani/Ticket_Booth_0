#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(TiXmlNode* venue_file_node) : venue_file_node(venue_file_node)
{}

using namespace std;

void CommandProcessor::firstLevel(TiXmlNode* venue_file_node, Venue** venues) {
    int level;
    cout << "Enter command number" << endl;
    cout << "1: Select Venue" << endl;
    cout << "2: Quit" << endl;
    cin >> level;
    if(level == 1) {
        TiXmlNode* venue_node = venue_file_node->FirstChild();
        assert(venue_node != 0);
        //cout << venue_node->Value() << endl;
        int i = 0;
        while(venue_node!= 0) {
            venues[i] = Venue_from_Xml::Get_Venue(venue_node);
            venue_node = venue_node->NextSibling();
            //venues[i]->Display();
            i++;
        }
        secondLevel(venues, i);
    } else if(level == 2) {
        quit();
    } else {
        cout << "Integer not recognized as a command. Quitting" << endl;
    }
}

void CommandProcessor::secondLevel(Venue** venues, int numOfVenues) {
    cout << "Second level" << endl;
    cout << "Select Venue: " << endl;
    int choice;
    
    int i;
    for(i = 0; i < numOfVenues; i++) {
        cout << (i+1) << ": ";
        venues[i]->Display();
    }
    //cout << "i is: " << i << " after for loop in secondLevel" << endl;
    cout << (i+1) << ": Cancel" << endl;
    cin >> choice;
    if(choice == (numOfVenues+1)) {
        // Implement cancel feature here
    } else {
        venueOptions(venues, choice);
    }
}

void CommandProcessor::venueOptions(Venue** venues, int venueNumber) {
    int choice;
    
    cout << "Selected venue is ";
    venues[venueNumber-1]->Display();
    cout << endl;
    
    cout << "Enter command number: " << endl;
    cout << "1: Display Venue" << endl;
    cout << "2: Select Show" << endl;
    cout << "3: Change Venue" << endl;
    cout << "4: Quit" << endl;
    
    cin >> choice;
    switch(choice) {
        case 1:
            // Display 1 Venue
            venues[venueNumber-1]->Display_All();
            break;
        case 2:
            // Supposed to select show here, add implementation later
            cout << "Selecting Show..." << endl;
            break;
        case 3:
            // Change Venue
            secondLevel(venues, venueNumber);
            break;
        case 4:
            // Quit
            quit();
            break;
        default:
            cout << "Wrong number picked. Quitting.";
            quit();
    }
}

int CommandProcessor::quit() {
    cout << "Quitting " << endl;
    // returning random number to terminate the program
    return 3;
    
    // Add program termination feature here
}