#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Seat.h"
#include "Seat_Row.h"

using namespace std;

Seat::Seat (const string& Row_Name,
            int Seat_Number, const string& Seat_Section) :
        seat_row_name(Row_Name),
        seat_number(Seat_Number),
        seat_section(Seat_Section)
{}



void Seat::Display() const
{
    cout << "Row " << seat_row_name << " ";
    cout << "Seat " << seat_number << " ";
    cout << "Section " << seat_section << endl;
}

