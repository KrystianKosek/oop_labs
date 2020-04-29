// Tutaj proszę napisać klasę Rover
#pragma once
#include "utils.h"

class Rover {
    // Klasa RoverIface jako friend, żeby miała dostęp do prywatnych zmiennych
    friend class RoverIface;
    public:
        // Konstruktory Rover
        Rover(){}
        Rover(std::string name) : name(name), coordinates(Coordinates()), online(false) {}
        
        // Funkcja zwracająca name
        virtual std::string get_name() const {
            return name;
        }
        // Funkcja zwracająca coordinates
        virtual Coordinates get_coordinates() const {
            return coordinates;
        }
        
        // Funkcja execute, jeśli obiekt jest online to wykonuje się action, 
        // w przeciwnym przypadku wypisuje się "ERROR"
        // przed action dopisałem & zarówno tutaj jak i w rover_iface tak jak Pan prosił
        virtual void execute(const std::function< void() > &action_) {
            if(!online){
                std::cout << "ERROR: Rover not linked to an interface.\n";
                return;
            }
            action_();
        }
        
        // Funkcja drive, jesli obiekt jest online to dopisuje wartości w vectorze
        // do naszych coordinates, w przeciwnym przypadku wypisuje "ERROR"
        virtual void drive(const Program& progr_){
            if(!online){
                std::cout << "ERROR: Rover not linked to an interface.\n";
                return;
            }
            for(auto &x : progr_){
                coordinates.set_lat(x()[0]);
                coordinates.set_lng(x()[1]);
                std::cout << "Arriving at " << coordinates;
            }
        }

    private:
        std::string name;
        Coordinates coordinates;
        bool online;
};