#include "lasagna_master.h"
#include <string>
#include <vector>

namespace lasagna_master {

int preparationTime(std::vector<std::string> layers, int time_per_layer) {
    return static_cast<int>(layers.size()) * time_per_layer;
}

amount quantities(const std::vector<std::string>& layers) {
    int noodles = 0;
    double sauce = 0.0;

    for (const std::string& layer : layers) {
        if (layer == "noodles") {
            noodles += 50;
        } else if (layer == "sauce") {
            sauce += 0.2;
        }
    }
    return amount{noodles, sauce};
}

void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList) {
    myList.back() = friendsList.back();
}

void addSecretIngredient(std::vector<std::string>& myList, const std::string& secretIngredient) {
    myList.back() = secretIngredient;
}

std::vector<double> scaleRecipe(const std::vector<double>& quantities, int numberOfPortions) {
    std::vector<double> scaledRecipe(quantities.size());
    for (size_t i = 0; i < quantities.size(); i++) {
        scaledRecipe[i] = quantities[i] * (static_cast<double>(numberOfPortions) / 2.0);
    }
    return scaledRecipe;
}

}  // namespace lasagna_master