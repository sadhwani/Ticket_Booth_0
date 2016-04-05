#pragma once
#include <string>
using std::string;

const int MAX_SEATING_SECTION_ELEMENTS = 1000;

class Seating_Section
{
private:
    struct Seating_Section_Element
    {
        string row_name;
        int first_seat_number;
        int last_seat_number;
    };

public:
    Seating_Section(string name);
    void Add_Element(string row_name, int first_seat_number, int last_seat_number);

    string Get_Name() const {return name;};
    int Get_Number_of_Elements() const {return number_of_elements;};

    void get_element(int i, 
                      string& name, 
                      int& first_seat_number, 
                      int& last_seat_number) const;

    void Display() const;

private:
    string name;
    Seating_Section_Element elements[MAX_SEATING_SECTION_ELEMENTS];
    int number_of_elements;
};
