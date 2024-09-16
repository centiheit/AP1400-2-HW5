#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
public:
    double get_price_unit() { return price_unit; }
    size_t get_units() { return units; }
    virtual std::string get_name() { return name; }

    double price() { return price_unit * units; }

    virtual ~Ingredient() = default;
    // 这里定义了一个纯虚函数clone()，用于实现深拷贝
    virtual Ingredient* clone() = 0;

protected:
    Ingredient(double price_unit, size_t units) : price_unit(price_unit), units(units) {}

    double price_unit;
    size_t units;
    std::string name;
};


#endif // INGREDIENT_H