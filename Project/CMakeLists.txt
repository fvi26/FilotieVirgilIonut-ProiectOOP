cmake_minimum_required(VERSION 3.26)
project(PROIECT)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROIECT main.cpp
        Airport.h
        Airport.cpp
        Ticket.cpp
        Ticket.h
        Reservation.h
        Reservation.cpp
        Airline.h
        Airline.cpp
        Flight.cpp
        Flight.h
        AirlineError.cpp
        AirlineError.h
        RyanAir.h
        QatarAirlines.h
        BlueAir.h
        WizzAir.h
        RyanAir.cpp
        QatarAirlines.cpp
        BlueAir.cpp
        WizzAir.cpp
)
