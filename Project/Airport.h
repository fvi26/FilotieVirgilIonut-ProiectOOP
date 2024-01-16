#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <iostream>

class Airport {
private:
    std::string name;

public:
    explicit Airport(const std::string& n);

    const std::string& getName() const;

    friend std::ostream& operator<<(std::ostream& out, const Airport& airport);
};

#endif // AIRPORT_H
