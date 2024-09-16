#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include <iostream>
#include <vector>
#include <string>
#include "sub_ingredients.h"

class EspressoBased {
public:
    // 在C++中，virtual std::string get_name() = 0;中的= 0表示该函数是一个纯虚函数（pure virtual function）。
    // 纯虚函数（Pure Virtual Function）的意义：
    // 抽象接口：纯虚函数用来定义一个抽象接口，这意味着该函数在基类（通常是抽象类）中没有实现，只是声明。这要求派生类（继承该基类的类）必须提供这个函数的实现。
    // 抽象类：包含至少一个纯虚函数的类被称为抽象类（abstract class）。抽象类不能实例化对象，因为它不完整——即包含未实现的纯虚函数。
    // 派生类实现：任何继承这个抽象类的派生类必须实现这个纯虚函数，否则该派生类也会成为一个抽象类。
    virtual std::string get_name() = 0;
    virtual double price() = 0;

    void brew();
    std::vector<Ingredient*>& get_ingredients();

    virtual ~EspressoBased();

protected:
    EspressoBased();
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;

};

#endif // ESPRESSO_BASED_H