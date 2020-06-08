// Tutaj należy wpisać kod
#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <functional>
#include <string>

// stałe
const unsigned long long minutesInSec = 60;
const unsigned long long hoursInSec = minutesInSec * 30;
const unsigned long long daysInSec = hoursInSec * 24;
const unsigned long long yearInSec = daysInSec * 365;

// definicja czasu
typedef std::tuple<int,int,int,int,int> l_time;

// operator wypisywania
std::ostream & operator << (std::ostream &out, const l_time & l){
    return out << std::get<0>(l) << "y:" << std::get<1>(l) << "d:"  << std::get<2>(l) << "h:"<< std::get<3>(l) << "m:" << std::get<4>(l) << "s";
}

// operator dodawania
l_time operator + (const l_time first, const l_time second){
    l_time tmp {std::get<0> (first) + std::get<0> (second), std::get<1> (first) + std::get<1> (second), std::get<2> (first) + std::get<2> (second), std::get<3> (first) + std::get<3> (second), std::get<4> (first) + std::get<4> (second)};
    return tmp;
}

// operator konwertujący sekundy na czas l_time
l_time from_sec(unsigned long long x){
    unsigned long long sec = x;
    unsigned long long years = x / yearInSec;
    sec -= years * yearInSec;
    unsigned long long days = sec / daysInSec;
    sec -= days * daysInSec;
    unsigned long long hours = sec / hoursInSec;
    sec -= hours * hoursInSec;
    unsigned long long minutes = sec / minutesInSec;
    sec -= minutes * minutesInSec;
    
    return l_time  {years, days, hours, minutes, sec};
}

// operator konwertujący _sec
l_time operator "" _sec (unsigned long long x){
    return from_sec(x);
}

// operator konwertujący _yrs
l_time operator "" _yrs (unsigned long long  x){
    return l_time {x, 0, 0, 0, 0};
}

// operator konwertujący czas l_time na sekundy
unsigned long long to_sec(const l_time l){
        unsigned long long sec = 0;
        sec += std::get<0>(l) * yearInSec;
        sec += std::get<1>(l) * daysInSec;
        sec += std::get<2>(l) * hoursInSec;
        sec += std::get<3>(l) * minutesInSec;
        sec += std::get<4>(l);
        return sec;
}


// klasa Human
class Human{
    public:
        // konstruktory
        Human() {}
        Human(const std::string name, const l_time age) : name(name), age(age) {}
        
        // gettery
        std::string get_name() const {
            return name;
        }
        l_time get_age() const {
            return age;
        }
        int get_index() const{
            return index;
        }
        
        // update czasu
        void update_time(const l_time t){
            age = age + t;
        }
        
        // pomocnicza funkcja clone, zwiększa index o 1, wywoływana w klasie pochodnej w celu indeksowania clonów
        void clone(){
            index++;
        }
        
    protected:
        std::string name;
        l_time age;
        int index = 1;
};

// klasa Clone dziedzicząca po Human
class Clone : public Human {
    public:
        // konstruktor, obiekt human nie może być const ponieważ wtedy nie można wywołać funkcji clone
        Clone(Human &human){
            age = human.get_age();
            name = human.get_name() + "_" + std::to_string(human.get_index());
            human.clone();
        }
};


