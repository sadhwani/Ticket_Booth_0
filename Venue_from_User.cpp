#include <iostream>
#include <string>
#include "Venue.h"
#include "Venue_from_User.h"
#include "Seating_Section.h"

using namespace std;

Venue* Venue_from_User::Get_Venue_from_User()
{
    string name;
    string street_address;
    string city;
    string state;
    int zip_code;

    // Get venue information from user
    cout << "Please enter venue information\n";
    cout << "Name: ";
    getline(cin, name);
    cout << "Street Address: ";
    getline(cin, street_address);
    cout << "City: ";
    getline(cin, city);
    cout << "State: ";
    getline(cin,state);
    cout << "Zip Code: ";
    cin >> zip_code;
    cin.ignore();


    Address adr(street_address, city, state, zip_code);
    Venue* new_venue = new Venue(name, adr);

    Add_Seat_Rows(new_venue);
    Add_Seating_Sections(new_venue);
    return new_venue;
}


void Venue_from_User::Add_Seat_Rows(Venue* venue)
{
    cout << "\nEnter seat row information\n";
    cout << "Enter blank line for name when finished\n";
    while (true)
    {
        string seat_row_name;
        string junk;
        int number_of_seats;
        string section_name;
        cout << "Seat row name: ";
        getline(cin, seat_row_name);
        if (seat_row_name.length() == 0)
        {
            break;
        }
        cout << "Number of seats: ";
        cin >> number_of_seats;
        getline(cin, junk);
        cout << "Section name: ";
        getline(cin, seat_row_name);

        venue->Add_Row(seat_row_name, number_of_seats, section_name);
    }
}


void Venue_from_User::Add_Seating_Sections(Venue* venue)
{
    cout << "\nEnter seating section information\n";
    cout << "Enter blank line for seating section name when finished\n";
    while (true)
    {
        string seating_section_name;
        string junk;
        cout << "Seating Section name: ";
        getline(cin, seating_section_name);
        if (seating_section_name.length() == 0)
        {
            break;
        }
        
        Seating_Section* new_seating_section = 
            new Seating_Section(seating_section_name);

        cout << "Enter Row names and seat number ranges\n";
        cout << "Enter a blank line for row name when finished with this section\n";

        while (true)
        {
            string row_name;
            int first_seat_number, last_seat_number;
            cout << "Row name: ";
            getline(cin, row_name);
            if (row_name.length() == 0)
            {
                break;
            }
            cout << "First seat number: ";
            cin >> first_seat_number;
            getline(cin, junk);
            cout << "Last seat number: ";
            cin >> last_seat_number;

            getline(cin, junk);

            new_seating_section->Add_Element(row_name, first_seat_number, last_seat_number);
            if (new_seating_section->Get_Number_of_Elements() == MAX_SEATING_SECTION_ELEMENTS)
            {
                break;
            }
        }
        venue->Add_Seating_Section(new_seating_section);
        if (venue->Get_Number_of_Seating_Sections() == Venue::MAX_SEATING_SECTIONS)
        {
            break;
        }
    }
}

