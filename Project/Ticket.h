
#ifndef TICKET_H
#define TICKET_H

#include "Airport.h"
#include <string>
#include <iostream>

class Ticket {
private:
    Airport departure;
    Airport arrival;
    std::string passengerName;

public:
    explicit Ticket(const Airport& dep, const Airport& arr, const std::string& name);

    void displayInfo() const;

    friend std::ostream& operator<<(std::ostream& out, const Ticket& ticket);
};

#endif // TICKET_H
