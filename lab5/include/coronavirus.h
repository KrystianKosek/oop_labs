#pragma once

#include "virus.h"

class CoronaVirus : public Virus
{
public:
    // konstruktory, wywołują konstruktory klasy matki (Virus) i ustawiają wartość giverName
    CoronaVirus() : Virus()
    {
        giverName = "";
    }
    CoronaVirus(string name, string giverName, const std::vector<Nucleotide> seq) : Virus(name)
    {
        this->giverName = giverName;
        RNA = new GeneSeq(seq);
    }

    CoronaVirus(CoronaVirus &copy) : Virus(copy)
    {
        giverName = copy.giverName;
    }

    CoronaVirus(CoronaVirus &&copy) : Virus(std::move(copy))
    {
        giverName = move(copy.giverName);
    }

    // zwraca nazwe dawcy
    string get_animal_host()
    {
        return giverName;
    }

    // przeciążone operatory przypisywania, wywoływują przeciążone operatory przypisywania klasy matki (Virus)
    CoronaVirus &operator=(CoronaVirus &copy)
    {
        if (&copy == this)
        {
            return *this;
        }
        this->Virus::operator=(copy);
        giverName = copy.giverName;
        return *this;
    }

    CoronaVirus operator=(CoronaVirus &&copy)
    {
        if (&copy == this)
        {
            return *this;
        }
        this->Virus::operator=(std::move(copy));
        giverName = move(copy.giverName);
        return *this;
    }

private:
    string giverName;
};