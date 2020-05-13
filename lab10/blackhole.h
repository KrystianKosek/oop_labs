// Tutaj należy pisać program
#pragma once
#include <iostream>
#include <string>

// czynnik służący do obliczania promienia Schwarzschilda
const float factor = 2 * 6.67 * 2 / 9.0;

class BlackHole{
    public:
        // przeciążony operator <<
        friend std::ostream & operator << (std::ostream &out, const BlackHole &tmp);
        
        // konstruktory
        BlackHole() {}
        BlackHole(std::string name, double mass, double dist) : name(name), mass(mass), dist(dist) {
            rad = mass * factor;
        }
        
        // gettery
        std::string get_name() const{
            return name;
        }
        
        double get_mass() const {
            return mass;
        }
        
        double get_Rh() const {
            return rad;
        }
        
        double get_dist() const {
            return dist;
        }
        
        // operator < porównujący masy dwóch czarnych dziur
        bool operator < (const BlackHole &tmp){
            return mass < tmp.mass;
        }
    
    private:
        // parametry czarnej dziury
        std::string name;
        double mass;
        double rad;
        double dist;
};


std::ostream & operator << (std::ostream &out, const BlackHole &tmp){
    return out << tmp.name << " : M=" << tmp.mass << " solar mass, Rh=" << tmp.rad << " km, dist=" << tmp.dist << " pc\n";
}
