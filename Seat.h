#pragma once
#include <string>

using std::string;

class Seat
{
private:
    string seat_row_name;
    int seat_number;

public:
    Seat (const string& Row_Name,
          int Seat_Number);

    Seat() { };

    void Display() const;
};
