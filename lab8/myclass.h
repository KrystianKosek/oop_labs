#pragma once
#include <iostream>
#include "terrorist.h"
#include "weapon.h"
#include <memory>

class Terrorist1 : public Terrorist, public Knife, public Rifle{
    // dziedzicze konstruktor z klasy Terrorist
    using Terrorist::Terrorist;
    public:
        // override metoda what z klasy terrorist do której przekazuje vector z Knife::name oraz Rifle::name
        void what() const override{
            Terrorist::print({Knife::name, Rifle::name});
        }
        
        // override metoda attack z klasy terrorist w której wywołuje odpowiednio metody cut i shoot z klas Knife i Rifle
        void attack() const override{
            Knife::cut();
            Rifle::shoot();
        }
};

class Terrorist2 : public Terrorist, public Axe, public Bomb{
    // dziedzicze konstruktor z klasy Terrorist
    using Terrorist::Terrorist;
    public:
        // override metoda what z klasy terrorist do której przekazuje vector z Axe::name oraz Bomb::name
        void what() const override{
            Terrorist::print({Axe::name, Bomb::name});
        }
        
        // override metoda attack z klasy terrorist w której wywołuje odpowiednio metody cut i shoot z klas Axe i Bomb
        void attack() const override{
            Axe::chop();
            Bomb::explode();
        }
};

class Safety : public Terrorist{
    public:
        // konstruktor przypisujący wskaźnik przekazany jako parametr
        Safety(Terrorist *ptr) : terr(ptr) {}
        
        // konstruktor przypisujący wskaźnik pobrany metodą get z referencji do uniqe_ptr
        // funkcje get znalazłem tutaj en.cppreference.com/w/cpp/memory/unique_ptr
        Safety(std::unique_ptr<Terrorist> &ptr) : terr(ptr.get()) {}
        
        // pusty destruktor ustawiony na default, nie musimy nic usuwać ponieważ nic nie alokujemy, jedynie przepinamy wskaźniki
        ~Safety() = default;
        
        // ustawia naszą zmienną isSafety na true
        void apply_safety_measures(){
            isSafety = true;
        }
        
        // wywołuje funkcje what z terrorysty podpiętego pod wskaźnik
        void what() const override{
            terr->what();
        }
        
        // sprawdza czy klasa jest unieszkodliwiona, jeśli nie to wywołuje z terrorysty podpiętego pod wskaźnik metode attack
        void attack() const override{
            if(!isSafety)
                terr->attack();
        }
    private:
        // jako parametry przechowuje wsk do Terrorist oraz bool'a isSafety który sprawdza czy terrorysta jest unieszkodliwiony
        Terrorist *terr;
        bool isSafety = false;
};