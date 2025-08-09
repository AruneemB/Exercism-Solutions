#include "protein_translation.h"
#include <unordered_map>

namespace protein_translation {

std::vector<std::string> proteins(const std::string &rna) {
    static const std::unordered_map<std::string, std::string> codon_map = {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"}, {"UUG", "Leucine"},
        {"UCU", "Serine"}, {"UCC", "Serine"},
        {"UCA", "Serine"}, {"UCG", "Serine"},
        {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}
    };

    std::vector<std::string> protein_sequence;

    for (size_t i = 0; i + 2 < rna.size(); i += 3) {
        std::string codon = rna.substr(i, 3);
        auto it = codon_map.find(codon);
        if (it != codon_map.end()) {
            if (it->second == "STOP") break;
            protein_sequence.push_back(it->second);
        }
    }
    return protein_sequence;
}

}  // namespace protein_translation
