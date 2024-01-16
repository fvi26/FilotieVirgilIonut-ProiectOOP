#ifndef RYANAIR_H
#define RYANAIR_H

#include "Airline.h"

class RyanAir : public Airline {
public:
    RyanAir();

    void makeReservation(const Reservation& r, int quantity) override;
};

#endif // RYANAIR_H
