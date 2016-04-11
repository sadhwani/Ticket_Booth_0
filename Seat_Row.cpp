#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Seat_Row.h"

using namespace std;

Seat_Row::Seat_Row(const string& Row_Name,
                   int Number_of_Seats, const string& Section_Name) :
                   row_name(Row_Name), number_of_seats(Number_of_Seats), section_name(Section_Name)
{
    // commenting out so I can set the seats array from the XML file
//    seats = new Seat*[number_of_seats];
//    for (int i = 0; i < number_of_seats; ++i)
//    {
//        seats[i] = new Seat(Row_Name, i+1, Section_Name);
//    }
}

const Seat* Seat_Row::Get_Seat(int idx) const
{
    if ((idx < 0) || (idx >= number_of_seats))
    {
        throw "Invalid idx argument passed to Get_Seat";
    }
    return seats[idx];
}

void Seat_Row::Set_Seats(Seat** seatsArray) {
    seats = seatsArray;
}

void Seat_Row::Display() const
{
    cout << "Row " << row_name << " Seats  1 - " 
         << number_of_seats << " Section: " << section_name << endl;
}

