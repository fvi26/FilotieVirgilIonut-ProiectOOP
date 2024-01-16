#include "WizzAir.h"

WizzAir::WizzAir() : Airline("WizzAir") {}

void WizzAir::makeReservation(const Reservation& r, int quantity) {

    for (int i = 0; i < quantity; ++i) {
        reservations.push_back(r);
    }
}
