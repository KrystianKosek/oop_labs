#pragma once
#include "organism.h"
#include "gene_utils.h"
class Bacteria : public Organism
{
public:
    //Klasa dziedziczy po Organism
    // Konstruktor wywołuje konstruktor z klasy matki
    Bacteria(std::string name, DNA dna) : Organism(name, dna) {}
    // Przeciążone funkcje reproduce zwraca nam nową bakterie z możliwą mutacją
    Organism *reproduce(Organism *wsk) override
    {
        return new Bacteria(wsk->get_name(), mutation(this->get_dna()));
    }
    Organism *reproduce() override
    {
        return new Bacteria(name, mutation(this->get_dna()));
    }

private:
};