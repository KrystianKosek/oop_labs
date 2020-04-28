#pragma once
#include "gene_sequence.h"

class DNA : public GeneSeq
{
public:
    // przeciążony operator wypisywania
    friend std::ostream &operator<<(std::ostream &out, const DNA &dna);
    // konstruktor
    DNA(GeneSeq &seq1, GeneSeq &seq2) : GeneSeq(seq1)
    {
        chain2 = seq2.get_sequence();
    }

    // Konstruktor przyjmujacy dwa wektory 
    DNA(const std::vector<Nucleotide> seq1, const std::vector<Nucleotide> seq2) : GeneSeq(seq1), chain2(seq2) {}

    // operator [] zwraca referencje do chain lub chain2
    std::vector<Nucleotide> & operator[](int x)
    {
        if (x == 0)
            return chain;
        else if (x == 1)
            return chain2;
    }
    
    // operator [] zwraca stałą kopie obiektu chain lub chain2
    std::vector<Nucleotide> operator[](int x) const
    {
        if (x == 0)
            return chain;
        else if (x == 1)
            return chain2;
    }
    
    // działa analogicznie do operatora []
    std::vector<Nucleotide> get_chain(int x) const
    {
        if (x == 0)
            return chain;
        else if (x == 1)
            return chain2;
    }

private:
    // dodatkowy vector nukleotydów
    std::vector<Nucleotide> chain2;
};
std::ostream &operator<<(std::ostream &out, const DNA &dna)
{
    out << GeneSeq(dna);
    for (unsigned i = 0; i < dna.chain2.size(); i++)
    {
        out << "| ";
    }
    out << "\n";
    out << GeneSeq(dna.chain2);
    return out;
}