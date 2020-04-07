#include "gene_sequence.h"

// przeciążony operator wypisywania
std::ostream &operator<<(std::ostream &out, const GeneSeq &seq_)
{
    if (seq_.chain.empty())
    {
        out << '0';
    }
    for (auto x : seq_.chain)
    {
        out << static_cast<char>(x) << " ";
    }
    out << "\n";
    return out;
}