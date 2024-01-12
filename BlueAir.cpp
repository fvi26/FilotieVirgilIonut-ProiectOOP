#include "BlueAir.h"

BlueAir::BlueAir() : Airline("BlueAir") {}

void BlueAir::makeReservation(const Reservation& r, int quantity) {
    // Adăugați logica specifică pentru BlueAir aici, dacă este necesar.

    for (int i = 0; i < quantity; ++i) {
        reservations.push_back(r);
    }
}
