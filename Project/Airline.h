#ifndef AIRLINE_H
#define AIRLINE_H

#include "Reservation.h"
#include <string>
#include <vector>
#include <memory>

class Airline {
protected:
    std::string name;
    std::vector<Reservation> reservations;

public:
    explicit Airline(const std::string& n);

    const std::string& getName() const;

    virtual void makeReservation(const Reservation& r, int quantity);

    virtual void displayReservations() const;

    virtual void displayInfo() const;

    virtual ~Airline();

    friend std::ostream& operator<<(std::ostream& out, const Airline& airline);
};

#endif // AIRLINE_H
