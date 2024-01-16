#ifndef WIZZAIR_H
#define WIZZAIR_H

#include "Airline.h"

class WizzAir : public Airline {
public:
    WizzAir();

    void makeReservation(const Reservation& r, int quantity) override;
};

#endif // WIZZAIR_H
