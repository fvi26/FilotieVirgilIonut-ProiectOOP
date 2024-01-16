#include "Reservation.h"

Reservation::Reservation(const Ticket& t) : ticket(t) {}

std::ostream& operator<<(std::ostream& out, const Reservation& reservation) {
    out << reservation.ticket;
    return out;
}
