#include <iostream>
#include <cassert>
#include "Seating_Section.h"

using namespace std;
Seating_Section::Seating_Section(string Name) : 
  name(Name), number_of_elements(0)
{}

void Seating_Section::Add_Element(string row_name, 
                                  int first_seat_number, 
                                  int last_seat_number) 
{
    assert(number_of_elements < MAX_SEATING_SECTION_ELEMENTS);
    Seating_Section_Element el =  {row_name, first_seat_number, last_seat_number};
    elements[number_of_elements++] = el;
}

void Seating_Section::get_element(int i, 
                                  string& name_, 
                                  int& first_seat_number_, 
                                  int& last_seat_number_) const
{
    assert(i >= 0);
    assert(i < number_of_elements);
    name_ = elements[i].row_name;
    first_seat_number_ = elements[i].first_seat_number;
    last_seat_number_ = elements[i].last_seat_number;
}

void Seating_Section::Display() const
{
    cout << "Section " << name << endl;
    for (int i = 0; i < number_of_elements; ++i)
    {
        cout << "Row " << elements[i].row_name
             << "  Seats " << elements[i].first_seat_number << " - " 
             << elements[i].last_seat_number  << endl;
    }
    cout << endl;
}
