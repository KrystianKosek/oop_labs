#pragma once
#include <iostream>
#include "gene_sequence.h"
using namespace std;

class Virus
{
public:
    // destruktor
    ~Virus()
    {
        delete RNA;
    }

    // konstruktory
    Virus() : name(""), RNA(nullptr), age(0) {}

    Virus(string name) : name(name), RNA(nullptr), age(0) {}

    Virus(Virus &copy) : name(copy.name), RNA(new GeneSeq(copy.RNA->get_sequence())), age(0)
    {
        copy.age++;
    }

    Virus(Virus &&copy) : name(move(copy.name)), RNA(move(copy.RNA)), age(move(copy.age))
    {
        copy.RNA = nullptr;
    }

    // przeciążone operatory przypisywania, kopiujacy i przenoszący
    Virus &operator=(Virus &copy)
    {
        if (&copy == this)
        {
            return *this;
        }
        name = copy.name;
        delete RNA;
        RNA = new GeneSeq(copy.RNA->get_sequence());
        age = copy.age;
        return *this;
    }

    Virus operator=(Virus &&copy)
    {
        if (&copy == this)
        {
            return *this;
        }
        name = move(copy.name);
        delete RNA;
        RNA = move(copy.RNA);
        age = move(copy.age);
        copy.RNA = nullptr;
        return *this;
    }

    // funkcje zwracające parametry klasy virus
    int get_age()
    {
        return age;
    }

    string get_name()
    {
        return name;
    }

    GeneSeq *get_RNA() const
    {
        return RNA;
    }

    // usuwa RNA poprzednie jeśli istnieje i ustawia nowe
    void set_RNA(const std::vector<Nucleotide> seq_)
    {
        if (RNA)
            delete RNA;
        RNA = new GeneSeq(seq_);
    }

protected:
    string name;
    GeneSeq *RNA;
    int age;
};