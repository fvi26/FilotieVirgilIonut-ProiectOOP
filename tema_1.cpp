#include <iostream>
#include <string>
#include <vector>

class Airport {
private:
    std::string name;

public:
    explicit Airport(const std::string& n) : name(n) {}

    const std::string& getName() const {
        return name;
    }

    friend std::ostream& operator<<(std::ostream& out, const Airport& airport) {
        out << "Airport Name: " << airport.name;
        return out;
    }
};

class Ticket {
private:
    Airport departure;
    Airport arrival;
    std::string passengerName;

public:
    explicit Ticket(const Airport& dep, const Airport& arr, const std::string& name)
            : departure(dep), arrival(arr), passengerName(name) {}


    Ticket(const Ticket& other)
            : departure(other.departure), arrival(other.arrival), passengerName(other.passengerName) {}


    void displayInfo() const {
        std::cout << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Ticket& ticket) {
        out << "Passenger Name: " << ticket.passengerName << std::endl;
        out << "Departure Airport: " << ticket.departure.getName() << std::endl;
        out << "Arrival Airport: " << ticket.arrival.getName();
        return out;
    }
    Ticket& operator=(const Ticket& other) {
        if (this == &other) {
            return *this;
        }

        this->departure = other.departure;
        this->arrival = other.arrival;
        this->passengerName = other.passengerName;

        return *this;
    }
};

class Reservation {
private:
    Ticket ticket;

public:
    explicit Reservation(const Ticket& t) : ticket(t) {}


    Reservation(const Reservation& other)
            : ticket(other.ticket) {}


    friend std::ostream& operator<<(std::ostream& out, const Reservation& reservation) {
        out << reservation.ticket;
        return out;
    }
};

class Airline {
private:
    std::string name;
    std::vector<Reservation> reservations;

public:
    explicit Airline(const std::string& n) : name(n) {}

    ~Airline() {
        reservations.clear();
    }

    void makeReservation(const Reservation& r, int quantity) {
        for (int i = 0; i < quantity; ++i) {
            reservations.push_back(r);
        }
    }

    void displayReservations() const {
        for (const Reservation& r : reservations) {
            std::cout << r << "---------------------------------" << std::endl;
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Airline& airline){
        out << airline.name;
        return out;
    }
};

int main() {
    std::vector<Airport> airports = {Airport("Bucuresti"), Airport("Roma"), Airport("Paris")};
    std::vector<Airline> airlines = {Airline("BlueAir"), Airline("WizzAir"), Airline("QatarAirlines")};
    std::vector<Ticket> tickets;

    int airlineChoice, departureChoice, arrivalChoice, quantity;
    std::string passengerName;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Choose Airline" << std::endl;
        std::cout << "2. Display Airport Info" << std::endl;
        std::cout << "3. Display Ticket Info" << std::endl;
        std::cout << "4. Make Reservation" << std::endl;
        std::cout << "5. Display Reservations" << std::endl;
        std::cout << "6. Show Airlines" << std::endl;
        std::cout << "7. Duplicate Reservations" << std::endl;
        std::cout << "8. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Choose Airline:" << std::endl;
                for (size_t i = 0; i < airlines.size(); ++i) {
                    std::cout << i + 1 << ". " << airlines[i]<< std::endl;
                }
                std::cin >> airlineChoice;

                if (airlineChoice > 0 && airlineChoice <= airlines.size()) {
                    std::cout << "Enter passenger name: ";
                    std::cin >> passengerName;
                }
                break;
            case 2:
                std::cout << "Available Airports:" << std::endl;
                for (size_t i = 0; i < airports.size(); ++i) {
                    std::cout << i + 1 << ". " << airports[i]<< std::endl;
                }
                break;
            case 3:
                if (!tickets.empty()) {
                    std::cout << "Choose Ticket to Display:" << std::endl;
                    for (size_t i = 0; i < tickets.size(); ++i) {
                        std::cout << i + 1 << ". Ticket " << i + 1 << std::endl;
                    }
                    std::cin >> departureChoice;
                    if (departureChoice > 0 && departureChoice <= tickets.size()) {
                        tickets[departureChoice - 1].displayInfo();
                    }
                } else {
                    std::cout << "No tickets available." << std::endl;
                }
                break;
            case 4:
                if (airlineChoice > 0 && airlineChoice <= airlines.size()) {
                    std::cout << "Choose Departure Airport:" << std::endl;
                    for (size_t i = 0; i < airports.size(); ++i) {
                        std::cout << i + 1 << ". " << airports[i]<< std::endl;
                    }
                    std::cin >> departureChoice;

                    std::cout << "Choose Arrival Airport:" << std::endl;
                    for (size_t i = 0; i < airports.size(); ++i) {
                        if (i != departureChoice - 1) {
                            std::cout << i + 1 << ". " << airports[i]<< std::endl;
                        }
                    }
                    std::cin >> arrivalChoice;

                    std::cout << "Enter quantity of tickets to buy: ";
                    std::cin >> quantity;

                    if (departureChoice > 0 && departureChoice <= airports.size() &&
                        arrivalChoice > 0 && arrivalChoice <= airports.size() &&
                        departureChoice != arrivalChoice && quantity > 0) {

                        Ticket newTicket(airports[departureChoice - 1], airports[arrivalChoice - 1], passengerName);
                        Reservation newReservation(newTicket);
                        airlines[airlineChoice - 1].makeReservation(newReservation, quantity);

                        for (int i = 0; i < quantity; ++i) {
                            tickets.push_back(newTicket);
                        }

                        std::cout << "Reservation successful." << std::endl;

                    }
                } else {
                    std::cout << "Invalid airline choice. Please choose an airline first." << std::endl;
                }
                break;
            case 5:
                if (airlineChoice > 0 && airlineChoice <= airlines.size()) {
                    airlines[airlineChoice - 1].displayReservations();
                } else {
                    std::cout << "Invalid airline choice. Please choose an airline first." << std::endl;
                }
                break;
            case 6:
                if(!airlines.empty()){
                    for (size_t i = 0; i < airlines.size(); i++) {
                        std::cout << airlines[i]<<std::endl;
                    }
                }
                break;
            case 8:
                std::cout<<"Thank you for choosing our airline services!";
                return 0;
            case 7:
                if (departureChoice > 0 && departureChoice <= airports.size() &&
                    arrivalChoice > 0 && arrivalChoice <= airports.size() &&
                    departureChoice != arrivalChoice && quantity > 0) {

                    Ticket newTicket(airports[departureChoice - 1], airports[arrivalChoice - 1], passengerName);

                    for (int i = 0; i < quantity; ++i) {
                        Ticket copy = newTicket; // Create a copy of the new ticket
                        Reservation newReservation(copy); // Create a new reservation using the copy
                        airlines[airlineChoice - 1].makeReservation(newReservation, 1);

                        tickets.push_back(copy);
                    }

                    std::cout << "Reservation successful." << std::endl;
                } else {
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}