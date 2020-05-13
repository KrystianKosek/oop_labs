// Tutaj należy pisać program
#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <initializer_list>
#include <iterator>
#include <algorithm>
#include <functional>
#include "blackhole.h"

class BHCatalogue{
    public:
        // pusty konstruktor
        BHCatalogue() {}
        
        // dodajemy na koniec katalogu nową czarną dziurę
        void add(const BlackHole &tmp){
            if(catalog.size() >= 5){
                std::cout << ">> Catalogue full. \""<< tmp.get_name() << "\" not added.\n";
                return;
            }
            catalog.insert({getNumber(), tmp});
        }
        
        // wywołujemy w pętli funkcje add dla referencji do czarnej dziury
        void add(std::initializer_list<BlackHole> list){
            for(auto ref : list){
                add(ref);
            }
        }
        
        // zwraca rzymski odpowiednik integera w postaci stringa
        std::string getNumber(){
            if(catalog.size() == 0){
                return "I.";
            }
            else if(catalog.size() == 1){
                return "II.";
            }
            else if(catalog.size() == 2){
                return "III.";
            }
            else if(catalog.size() == 3){
                return "IV.";
            }
            else{
                return "V.";
            }
        }
        
        // getter, zwraca konkretną czarną dziure
        BlackHole get(std::string number){
            return catalog.at(number);
        }
        
        // zwraca katalog czarnych dziur
        std::map<std::string, BlackHole> get_map(){
            return catalog;
        }
        
        // zwraca posortowany vector czarnych dziur
        std::vector<BlackHole> get_ordered_by_mass(){
            std::vector<BlackHole> vec;
            for(auto v : catalog){
                vec.push_back(v.second);
            }
            std::sort(vec.begin(), vec.end());
            return vec;
        }

        std::vector<BlackHole> get_custom(std::function<bool(const BlackHole &)> fun){
            std::vector<BlackHole> vec;
            for(auto v : catalog){
                if(fun(v.second))
                    vec.push_back(v.second);
            }
            return vec;
        }
        
        
    private:
        // katalog czarnych dziur
        std::map<std::string, BlackHole> catalog;
};

double operator "" _pc(long double x){
    return x * 3.1 * 1e13;
}