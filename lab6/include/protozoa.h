#pragma once
#include "organism.h"
#include "gene_utils.h"

class Protozoa : public Organism
{
public:
    //Klasa dziedziczy po Organism
    // Konstruktor wywołuje konstruktor z klasy matki
    Protozoa(std::string name, DNA dna) : Organism(name, dna) {}
    
    // Przeciążone funkcje reproduce zwraca nam nową bakterie z możliwą mutacją
    Organism *reproduce(Organism *wsk) override
    {
        if(this->get_name() == wsk->get_name()){
            return new Bacteria(wsk->get_name(), DNA(this->dna[0], wsk->get_dna()[1]));
        }
        return nullptr;
    }
    Organism *reproduce() override
    {
        return nullptr;
    }

private:
};