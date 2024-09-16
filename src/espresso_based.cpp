#include "espresso_based.h"

void EspressoBased::brew() {
    std::cout << "Brewing " << name << "..." << std::endl;
    for(const auto& i : ingredients)
        std::cout << "Adding " << i->get_name() << "..." << std::endl;
    std::cout << name << " is ready!" << std::endl;
}

std::vector<Ingredient*>& EspressoBased::get_ingredients() {
    return ingredients;
}

EspressoBased::EspressoBased() {}

EspressoBased::EspressoBased(const EspressoBased& esp) {
    name = esp.name;
    for(const auto& i : esp.ingredients)
        ingredients.push_back(i->clone());
}

void EspressoBased::operator=(const EspressoBased& esp) {
    name = esp.name;
    for(const auto& i : esp.ingredients)
        ingredients.push_back(i->clone());
}

EspressoBased::~EspressoBased() {
    for(auto& i : ingredients)
        delete i;
    ingredients.clear();
}