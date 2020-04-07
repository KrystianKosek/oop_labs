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