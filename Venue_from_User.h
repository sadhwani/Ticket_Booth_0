#pragma once
#include "Venue.h"

static class Venue_from_User
{
public:
    static Venue* Get_Venue_from_User();

private:
    static void Add_Seat_Rows(Venue* venue);
    static void Add_Seating_Sections(Venue* venue);
};


