#include "mocha.h"

Mocha::Mocha() {
    this->name = "Mocha";
    this->ingredients.push_back(new Espresso(2));
    this->ingredients.push_back(new Milk(2));
    this->ingredients.push_back(new MilkFoam(1));
    this->ingredients.push_back(new Chocolate(1));
}

Mocha::Mocha(const Mocha& cap) {
    name = cap.name;
    for (auto i : cap.ingredients) {
        ingredients.push_back(i->clone());
    }
    for (auto i : cap.side_items) {
        side_items.push_back(i->clone());
    }
}

Mocha::~Mocha() {
    for (auto i : this->side_items) {
        delete i;
    }
    this->side_items.clear();
}

void Mocha::operator=(const Mocha& cap) {
    // 如果是自我赋值，直接返回
    if (this == &cap) {
        return;
    }
    name = cap.name;
    // push_back需要赋值的元素前，需要先清空原有的元素
    for (auto& i : ingredients) {
        delete i;
    }
    ingredients.clear();
    for (auto& i : side_items) {
        delete i;
    }
    side_items.clear();
    for (auto i : cap.ingredients) {
        ingredients.push_back(i->clone());
    }
    for (auto i : cap.side_items) {
        side_items.push_back(i->clone());
    }
}

std::string Mocha::get_name() {
    return this->name;
}

double Mocha::price() {
    double total_price = 0;
    for (auto i : this->ingredients) {
        total_price += i->price();
    }
    for (auto i : this->side_items) {
        total_price += i->price();
    }
    return total_price;
}

void Mocha::add_side_item(Ingredient* side) {
    this->side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items() {
    return this->side_items;
}