#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <type_traits>

class WaterContainer{
    public:
        // Konstruktory
        WaterContainer() : max(0.0), size(0.0) {}
        WaterContainer(const double max) : max(max), size(0.0)  {}
        
        // metoda put ustawiająca wartość size na przekazaną wartość o ile mieści się w zakresie
        void put(const double V){
            size = 0.0;
            if(V > max){
                std::string err = "Error: Container too small.";
                throw err;
            }
            size = V;
        }
        
        // przeciążony operator += dodający do size wartość size przekazanego obiektu
        void operator +=(WaterContainer &V){
            if(size + V.get() > max){
                std::cout << "Error: Container too small.\n";
                return;
            }
            
            size += V.get();
            V.clean();
        }
        
        // getter
        double get() const{
            return size;
        }
        
        // clean, ustawia size na 0.0
        void clean(){
            size = 0.0;
        }
        
    private:
        double max;
        double size;
};

// enum bilonów
enum Bill{
    Ten_PLN,
    Twenty_PLN,
    Fifty_PLN,
    Hundred_PLN
};


class Wallet{
    public:
        // konstruktory
        Wallet() {}
        Wallet(const int max) : max(max) {}
        
        // metoda put dodaje elementy z przekazanego vectora do naszego vectora bilons.
        void put(std::vector<Bill> bills){
            bilons.clear();
            if(bills.size() > max){
                std::string err = "Error: Wallet too small.";
                throw err;
            }
            for(auto &v: bills){
                bilons.push_back(v);
            }
        }
        
        // przeciązony operator += dopisujący nowe bilony z przekazanego obiektu
        void operator += (Wallet &V){
            if(bilons.size() + V.returnSize() > max){
                std::cout << "Error: Wallet too small.\n";
                return;
            }
            while(V.returnSize() > 0){
                bilons.push_back(V.pop_first()); 
            }
        }
        
        // getter
        std::vector<Bill> get() const{
            return bilons;
        }
        
        // zwraca usunięty pierwszy element vectora
        Bill pop_first(){
            Bill x = bilons[0];
            bilons.erase(bilons.begin());
            return x;
        }
        
        // zwraca rozmiar vectora 
        double returnSize() const{
            return bilons.size();
        }
        
        // opróżnia vector
        void clean(){
            bilons.clear();
        }
        
    private:
        unsigned int max;
        std::vector<Bill> bilons;
};

// operator wypisywania vectora bilonów
std::ostream & operator << (std::ostream &o, const std::vector<Bill> & w){
    std::map<Bill, std::string> billToStr = {{ Ten_PLN, "Ten"}, { Twenty_PLN, "Twenty"}, { Fifty_PLN, "Fifty"}, {Hundred_PLN, "Hundred"}};
    if(w.empty()){
        o << "No bills.";
    }
    for(auto v : w){
        o << billToStr[v] << " ";
    } 
    return o;
}

// szablon funkcji dopisującej elementy drugiego obiektu do pierwszego
template<typename T> void move_to_container(T &a, T &b){
    a += b;
}

// szablon funkcji tworzący vector kopii obiektu o przekazanym rozmiarze
template<int x, typename T> std::vector<T> replicate_container(T &a){
    std::vector<T> vec;
    for(int i = 0; i < x; i++)
        vec.push_back(a);
    return vec;
}

// szablon funkcji porównujący typy przekazanych obiektów
template<typename T, typename F> void compare_container_type(T &a, F &b){
    if(std::is_same<T, F>::value){
        std::cout << "The containers are of same type.\n";
    }
    else{
        std::cout << "The containers are of different type.\n";
    }
}

