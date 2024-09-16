#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include "ingredient.h"

// Cinnamon
class Cinnamon : public Ingredient {
public:
    Cinnamon(size_t units) : Ingredient{5, units} { name = "Cinnamon"; }
    std::string get_name() override { return name; }
    Ingredient* clone() override { return new Cinnamon(*this); }
};

// Chocolate
class Chocolate : public Ingredient {
public:
    Chocolate(size_t units) : Ingredient{5, units} { name = "Chocolate"; }
    std::string get_name() override { return name; }
    Ingredient* clone() override { return new Chocolate(*this); }
};

// Sugar
class Sugar : public Ingredient {
public:
    Sugar(size_t units) : Ingredient{1, units} { name = "Sugar"; }
    std::string get_name() override { return name; }
    Ingredient* clone() override { return new Sugar(*this); }
};

// Cookie
class Cookie : public Ingredient {
public:
    Cookie(size_t units) : Ingredient{10, units} { name = "Cookie"; }
    std::string get_name() override { return name; }
    Ingredient* clone() override { return new Cookie(*this); }
};

// Espresso
class Espresso : public Ingredient {
public:
    Espresso(size_t units) : Ingredient{15, units} { name = "Espresso"; }
    std::string get_name() override { return name; }
    Ingredient* clone() override { return new Espresso(*this); }
};

// Milk
class Milk : public Ingredient {
public:
    Milk(size_t units) : Ingredient{10, units} { name = "Milk"; }
    std::string get_name() override { return name; }
    Ingredient* clone() override { return new Milk(*this); }
};

//MilkFoam
class MilkFoam : public Ingredient {
public:
    MilkFoam(size_t units) : Ingredient{5, units} { name = "MilkFoam"; }
    std::string get_name() override { return name; }
    Ingredient* clone() override { return new MilkFoam(*this); }
};

// Water
class Water : public Ingredient {
public:
    Water(size_t units) : Ingredient{1, units} { name = "Water"; }
    std::string get_name() override { return name; }
    Ingredient* clone() override { return new Water(*this); }
};

#endif // SUB_INGREDIENTS_H