#pragma once
#include <string>
#include <vector> 

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int time_per_layer = 2);
amount quantities(const std::vector<std::string>& layers);
void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList);
void addSecretIngredient(std::vector<std::string>& myList, const std::string& secretIngredient);
std::vector<double> scaleRecipe(const std::vector<double>& quantities, int numberOfPortions);

}  // namespace lasagna_master
