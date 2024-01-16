#ifndef AIRLINE_ERROR_H
#define AIRLINE_ERROR_H

#include <stdexcept>
#include <string>

class AirlineError : public std::exception {
public:
    AirlineError(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif // AIRLINE_ERROR_H
