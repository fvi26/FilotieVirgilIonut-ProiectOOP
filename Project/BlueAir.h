#ifndef BLUEAIR_H
#define BLUEAIR_H

#include "Airline.h"

class BlueAir : public Airline {
public:
    BlueAir();

    void makeReservation(const Reservation& r, int quantity) override;
};

#endif // BLUEAIR_H
