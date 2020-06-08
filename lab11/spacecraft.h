// Tutaj należy wpisać kod
#pragma once
#include "human.h"

// definicja vectora
typedef std::vector< Human* > vector;

// klasa Spacecraft
class Spacecraft{
    public:
        // konstruktory
        Spacecraft() {}
        Spacecraft(const vector vec) : vec(vec) {}
        
        // funkcja update_time, przyjmująca jako parametr funkcje oraz czas
        // wywoływana jest dla każdego obiektu human w naszym vectorze
        void update_time(std::function<l_time(const l_time &)> fun, const l_time t){
            for(auto v : vec){
                v->update_time(fun(t));
            }
        }
        // operator [] zwraca obiekt Human z vectora o podanym imieniu
        Human operator [](const std::string name){
            for(auto & v: vec){
                if(v->get_name() == name){
                    return *v;
                }
            }
            return Human();
        }
    private:
        vector vec;
};