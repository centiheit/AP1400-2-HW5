#include "cappuccino.h"

Cappuccino::Cappuccino() {
    this->name = "Cappuccino";
    this->ingredients.push_back(new Espresso(2));
    this->ingredients.push_back(new Milk(2));
    this->ingredients.push_back(new MilkFoam(1));
}

// 这里不能直接使用浅拷贝，需要实现深拷贝，否则对于TEST7，
// 会导致调用两次析构函数而出现double free的问题
// ***深拷贝的基本思路：***
// 复制指针成员：对于指向动态分配内存的成员（如 ingredients），需要为每个元素分配新的内存，并复制内容，而不是简单地复制指针。
// 非指针成员（如 name）：可以直接复制，因为这些成员类型（如 std::string）提供了默认的深拷贝行为。
// Cappuccino::Cappuccino(const Cappuccino& cap) {
//     name = cap.name;
//     ingredients = cap.ingredients;
//     side_items = cap.side_items;
// }
Cappuccino::Cappuccino(const Cappuccino& cap) {
    name = cap.name;
    for (auto i : cap.ingredients) {
        ingredients.push_back(i->clone());
    }
    for (auto i : cap.side_items) {
        side_items.push_back(i->clone());
    }
}

Cappuccino::~Cappuccino() {
    for (auto& i : this->side_items) {
        delete i;
    }
    this->side_items.clear();
}

void Cappuccino::operator=(const Cappuccino& cap) {
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

std::string Cappuccino::get_name() {
    return this->name;
}

double Cappuccino::price() {
    double total_price = 0;
    for (auto i : this->ingredients) {
        total_price += i->price();
    }
    for (auto i : this->side_items) {
        total_price += i->price();
    }
    return total_price;
}

void Cappuccino::add_side_item(Ingredient* side) {
    this->side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items() {
    return this->side_items;
}