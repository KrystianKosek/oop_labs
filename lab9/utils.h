// Tutaj proszę napisać pozostały kod
#pragma once
#include <iostream>
#include <vector>
#include <functional>

// Zadeklarowany alias pt "Program"
// (Tutaj zmarnowałem najwięcej czasu, bo wpadnięcie na to zajeło mi około 30minut)
typedef std::vector<std::function<std::vector<double>()>> Program;

class Coordinates {
    public:
        // Operatory << oraz - zadeklarowane jako friend
        friend std::ostream &operator << (std::ostream &out, const Coordinates &vec);
        friend std::vector<double> operator - (const Coordinates & vec1, const Coordinates & vec2);
        
        // Konstruktory
        Coordinates() : Coordinates(0.0, 0.0) {}
        Coordinates(double lat, double lng) : lat(lat), lng(lng) {}
        Coordinates(std::vector<double> vec) : lat(vec[0]), lng(vec[1]) {}
        
        // Operator += oraz -= ( Nigdzie nie używane ale zakładam, że działają tak jak trzeba :) )
        Coordinates & operator += (double val){
            lat += val;
            lng += val;
            return *this;
        }
        Coordinates & operator -= (double val){
            lat -= val;
            lng -= val;
            return *this;
        }
        
        // gettery
        double get_lat() const {
            return lat;
        }
        double get_lng() const {
            return lng;
        }
        
        // settery
        void set_lat(const double val){
            lat += val;
        }
        void set_lng(const double val){
            lng += val;
        }
        
    private:
        double lat,lng;
    
};


// Przeciążony operator <<
std::ostream &operator << (std::ostream &out, const Coordinates &vec){
    return out << "(" << vec.get_lat() << ", " << vec.get_lng() << ")\n";
}

// Przeciążony operator -
std::vector<double> operator - (const Coordinates & vec1, const Coordinates & vec2){
    std::vector<double> vec;
    vec.push_back(vec1.get_lat() - vec2.get_lat());
    vec.push_back(vec1.get_lng() - vec2.get_lng());
    return vec;
}

// Przestrzeń nazw MarsRouter,
// zawierająca dwie funkcje, które zwracają nasz alias pt "Program" 
// (stosunkowo proste, tylko w mainie nie było ani slowa wytłumaczone jak to ma działać)
namespace MarsRoutes{
    // zwraca vector trzech wyrażeń lambda
    Program route1(){
        return {[]() { return std::vector<double>{1.0, -1.0}; },
            []() { return std::vector<double>{1.0, 0.0}; },
            []() { return std::vector<double>{1.0, -1.0}; }
        };
    }
    
    // zwraca wyrażenie lambda zwracające vector odjętych od siebie dwóch współrzędnych
    Program go_to(const Coordinates &vec1, const Coordinates &vec2){
        return { [vec1, vec2] () { return (vec2 - vec1); }};
    }
};