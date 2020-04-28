#pragma once
#include <iostream>
#include "dna.h"

class Organism
{
public:
    // konstruktor z 2 parametrami
    Organism(std::string name, DNA dna) : name(name), dna(dna) {}
    // destruktor
    virtual ~Organism() = default;
    // zwraca name
    std::string get_name()
    {
        return name;
    }
    // zwraca kod dna
    DNA get_dna() const
    {
        return dna;
    }
    // czysto wirtualne funkcje reproduce
    virtual Organism *reproduce(Organism *) = 0;
    virtual Organism *reproduce() = 0;

    // operator zawirusowywania.
    void operator<<(const Virus &vir)
    {
        int branch = rand() % 2;
        int index = 0;
        vector<Nucleotide> vrna = *vir.get_RNA();
        if (branch == 1)
        {
            int pos = rand() % dna.operator[](1).size();
            int i = pos;
            for (index = 0; index < vrna.size(); index++)
            {
                dna[1][(i + index) % dna.get_sequence().size()] = vrna[index];
            }
        }
        else
        {
            int pos = rand() % dna.operator[](0).size();
            int i = pos;
            for (index = 0; index < vrna.size(); index++)
            {
                dna[0][(i + index) % dna.get_sequence().size()] = vrna[index];
            }
        }
    }

protected:
    std::string name;
    DNA dna;
};