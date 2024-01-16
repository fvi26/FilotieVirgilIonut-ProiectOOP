#include "RyanAir.h"

RyanAir::RyanAir() : Airline("RyanAir") {}

void RyanAir::makeReservation(const Reservation& r, int quantity) {


    for (int i = 0; i < quantity; ++i) {
        reservations.push_back(r);
    }
}
