#include <iostream>
#include <vector>
#include <memory>
#include "Airport.h"
#include "Airline.h"
#include "AirlineError.h"
#include "BlueAir.h"
#include "WizzAir.h"
#include "QatarAirlines.h"
#include "RyanAir.h"
#include "Flight.h"
#include "Reservation.h"
#include "Ticket.h"

int main() {
    std::vector<Airport> airports = {Airport("Bucuresti"), Airport("Roma"), Airport("Paris")};
    std::vector<std::unique_ptr<Airline>> airlines;
    std::vector<Flight> flights;
    std::vector<Ticket> tickets;

    airlines.push_back(std::make_unique<BlueAir>());
    airlines.push_back(std::make_unique<WizzAir>());
    airlines.push_back(std::make_unique<QatarAirlines>());
    airlines.push_back(std::make_unique<RyanAir>());

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Buy Ticket" << std::endl;
        std::cout << "2. Show Info" << std::endl;
        std::cout << "3. Add Flight and Display Info" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: // Buy Ticket
                std::cout << "Choose Airline:" << std::endl;
                for (size_t i = 0; i < airlines.size(); ++i) {
                    std::cout << i + 1 << ". " << airlines[i]->getName() << std::endl;
                }
                int airlineChoice;
                std::cin >> airlineChoice;

                if (airlineChoice > 0 && airlineChoice <= airlines.size()) {
                    std::string passengerName;
                    std::cout << "Enter passenger name: ";
                    std::cin >> passengerName;

                    std::cout << "Choose Departure Airport:" << std::endl;
                    for (size_t i = 0; i < airports.size(); ++i) {
                        std::cout << i + 1 << ". " << airports[i].getName() << std::endl;
                    }
                    int departureChoice;
                    std::cin >> departureChoice;

                    std::cout << "Choose Arrival Airport:" << std::endl;
                    for (size_t i = 0; i < airports.size(); ++i) {
                        if (i != departureChoice - 1) {
                            std::cout << i + 1 << ". " << airports[i].getName() << std::endl;
                        }
                    }
                    int arrivalChoice;
                    std::cin >> arrivalChoice;

                    std::cout << "Choose Departure Time:" << std::endl;
                    std::cout << "1. 09:00 AM" << std::endl;
                    std::cout << "2. 12:00 PM" << std::endl;

                    int departureTimeChoice;
                    std::cin >> departureTimeChoice;

                    if (departureChoice > 0 && departureChoice <= airports.size() &&
                        arrivalChoice > 0 && arrivalChoice <= airports.size() &&
                        departureChoice != arrivalChoice &&
                        departureTimeChoice > 0 && departureTimeChoice <= 2) {

                        std::string depTime = (departureTimeChoice == 1) ? "09:00 AM" : "12:00 PM";
                        Flight newFlight(airports[departureChoice - 1], airports[arrivalChoice - 1], depTime, "Arrival Time Not Set", *airlines[airlineChoice - 1]);
                        newFlight.displayInfo();
                        flights.push_back(newFlight);

                        Ticket newTicket(airports[departureChoice - 1], airports[arrivalChoice - 1], passengerName);
                        Reservation newReservation(newTicket);
                        airlines[airlineChoice - 1]->makeReservation(newReservation, 1);
                        tickets.push_back(newTicket);

                        std::cout << "Reservation successful." << std::endl;
                    } else {
                        std::cout << "Invalid input. Please try again." << std::endl;
                    }
                } else {
                    std::cout << "Invalid airline choice. Please choose an airline first." << std::endl;
                }
                break;

            case 2: // Show Info
                std::cout << "1. Display Reservations" << std::endl;
                std::cout << "2. Display Airport Info" << std::endl;
                std::cout << "3. Display Ticket Info" << std::endl;
                std::cout << "4. Show Airlines" << std::endl;
                std::cout << "5. Display Flights Info" << std::endl;

                int infoChoice;
                std::cin >> infoChoice;

                switch (infoChoice) {
                    case 1: // Display Reservations
                        std::cout << "Choose Airline:" << std::endl;
                        for (size_t i = 0; i < airlines.size(); ++i) {
                            std::cout << i + 1 << ". " << airlines[i]->getName() << std::endl;
                        }
                        int airlineChoiceForReservations;
                        std::cin >> airlineChoiceForReservations;

                        if (airlineChoiceForReservations > 0 && airlineChoiceForReservations <= airlines.size()) {
                            airlines[airlineChoiceForReservations - 1]->displayReservations();
                        } else {
                            std::cout << "Invalid airline choice. Please choose an airline first." << std::endl;
                        }
                        break;

                    case 2: // Display Airport Info
                        std::cout << "Available Airports:" << std::endl;
                        for (size_t i = 0; i < airports.size(); ++i) {
                            std::cout << i + 1 << ". " << airports[i].getName() << std::endl;
                        }
                        break;

                    case 3: // Display Ticket Info
                        if (!tickets.empty()) {
                            std::cout << "Choose Ticket to Display:" << std::endl;
                            for (size_t i = 0; i < tickets.size(); ++i) {
                                std::cout << i + 1 << ". Ticket " << i + 1 << std::endl;
                            }
                            int ticketChoice;
                            std::cin >> ticketChoice;
                            if (ticketChoice > 0 && ticketChoice <= tickets.size()) {
                                tickets[ticketChoice - 1].displayInfo();
                            } else {
                                std::cout << "Invalid choice. Please try again." << std::endl;
                            }
                        } else {
                            std::cout << "No tickets available." << std::endl;
                        }
                        break;

                    case 4: // Show Airlines
                        if (!airlines.empty()) {
                            for (size_t i = 0; i < airlines.size(); i++) {
                                std::cout << i + 1 << ". " << airlines[i]->getName() << std::endl;
                            }
                        }
                        break;

                    case 5: // Display Flights Info
                        if (!flights.empty()) {
                            std::cout << "Available Flights:" << std::endl;
                            for (size_t i = 0; i < flights.size(); ++i) {
                                std::cout << i + 1 << ". Flight " << i + 1 << std::endl;
                            }
                            int flightChoice;
                            std::cin >> flightChoice;
                            if (flightChoice > 0 && flightChoice <= flights.size()) {
                                flights[flightChoice - 1].displayInfo();
                            } else {
                                std::cout << "Invalid choice. Please try again." << std::endl;
                            }
                        } else {
                            std::cout << "No flights available." << std::endl;
                        }
                        break;

                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                        break;
                }
                break;

            case 3: // Add Flight and Display Info
                std::cout << "Choose Departure Airport:" << std::endl;
                for (size_t i = 0; i < airports.size(); ++i) {
                    std::cout << i + 1 << ". " << airports[i].getName() << std::endl;
                }
                int departureChoice;
                std::cin >> departureChoice;

                std::cout << "Choose Arrival Airport:" << std::endl;
                for (size_t i = 0; i < airports.size(); ++i) {
                    if (i != departureChoice - 1) {
                        std::cout << i + 1 << ". " << airports[i].getName() << std::endl;
                    }
                }
                int arrivalChoice;
                std::cin >> arrivalChoice;

                std::cout << "Choose Departure Time:" << std::endl;
                std::cout << "1. 09:00 AM" << std::endl;
                std::cout << "2. 12:00 PM" << std::endl;

                int departureTimeChoice;
                std::cin >> departureTimeChoice;

                if (departureChoice > 0 && departureChoice <= airports.size() &&
                    arrivalChoice > 0 && arrivalChoice <= airports.size() &&
                    departureChoice != arrivalChoice &&
                    departureTimeChoice > 0 && departureTimeChoice <= 2) {

                    std::string depTime = (departureTimeChoice == 1) ? "09:00 AM" : "12:00 PM";

                    std::cout << "Choose Airline for the Flight:" << std::endl;
                    for (size_t i = 0; i < airlines.size(); ++i) {
                        std::cout << i + 1 << ". " << airlines[i]->getName() << std::endl;
                    }
                    int airlineChoiceForFlight;
                    std::cin >> airlineChoiceForFlight;

                    if (airlineChoiceForFlight > 0 && airlineChoiceForFlight <= airlines.size()) {
                        // Adăugarea unui zbor cu linia aeriană selectată
                        Flight newFlight(airports[departureChoice - 1], airports[arrivalChoice - 1], depTime, "Arrival Time Not Set", *airlines[airlineChoiceForFlight - 1]);
                        flights.push_back(newFlight);
                        std::cout << "Flight added successfully." << std::endl;
                    } else {
                        std::cout << "Invalid airline choice for the flight. Please try again." << std::endl;
                    }
                } else {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                break;

            case 4: // Exit
                std::cout << "Thank you for choosing our airline services!" << std::endl;

                // Nu mai este nevoie să ștergeți obiectele, deoarece folosim smart pointers (std::unique_ptr)

                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}