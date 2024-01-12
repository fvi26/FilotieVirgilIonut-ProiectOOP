#ifndef RESERVATION_H
#define RESERVATION_H

#include "Ticket.h"

class Reservation {
private:
    Ticket ticket;

public:
    Reservation(const Ticket& t);

    friend std::ostream& operator<<(std::ostream& out, const Reservation& reservation);
};

#endif // RESERVATION_H
