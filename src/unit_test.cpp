#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"
#include "cappuccino.h"
#include "mocha.h"


TEST(HW5Test, TEST1) {
    Cinnamon    cinnamon{2};  
    EXPECT_EQ(cinnamon.get_name(), "Cinnamon");
    EXPECT_EQ(cinnamon.get_price_unit(), 5);
    EXPECT_EQ(cinnamon.get_units(), 2);
    EXPECT_EQ(cinnamon.price(), 10);
}

TEST(HW5Test, TEST2) {
    Cinnamon    cinnamon{1};  
    Chocolate   chocolate{1};
    Sugar       sugar{2};    
    Cookie      cookie{1};  
    Espresso    espresso{2}; 
    Milk        milk{2} ;    
    MilkFoam    milkFoam{1}; 
    Water       water{2};    
}

TEST(HW5Test, TEST3) {
    Cinnamon    cinnamon{1};  
    Sugar       sugar{2};    
    Cookie      cookie{1};  
    Water       water{2};

    Ingredient* ingredient;
    ingredient = &cinnamon;
    EXPECT_EQ(ingredient->get_name(), "Cinnamon");
    ingredient = &sugar;
    EXPECT_EQ(ingredient->get_name(), "Sugar");
    ingredient = &cookie;
    EXPECT_EQ(ingredient->get_name(), "Cookie");
    ingredient = &water;
    EXPECT_EQ(ingredient->get_name(), "Water");
}

TEST(HW5Test, TEST4) {
    Cappuccino cappuccino{};
    EXPECT_EQ(cappuccino.get_name(), "Cappuccino");
    auto ingredients = cappuccino.get_ingredients();

    for (const auto& i : ingredients) {
        std::cout << i->get_name() << std::endl;
    }

    EXPECT_EQ(ingredients.size(), 3);
    for(const auto& i : ingredients)
        EXPECT_TRUE(i->get_name() == "Espresso" || i->get_name() == "Milk" || i->get_name() == "MilkFoam");
}

TEST(HW5Test, TEST5) {
    Cappuccino cappuccino{};
    EXPECT_DOUBLE_EQ(cappuccino.price(), 55);
    cappuccino.add_side_item(new Cinnamon{1});
    EXPECT_DOUBLE_EQ(cappuccino.price(), 60);
}

TEST(HW5Test, TEST6) {
    EspressoBased* esp{new Cappuccino{}};
    reinterpret_cast<Cappuccino*>(esp)->add_side_item(new Cookie{1});
    // 如果你的基类 EspressoBased 的析构函数不是虚函数，那么在通过基类指针删除派生类对象时
    // （例如 delete esp，其中 esp 是 EspressoBased* 类型的指针指向一个 Cappuccino 对象），
    // 只会调用基类的析构函数，而不会调用派生类的析构函数，导致派生类中的资源泄漏。
    // ***所以，这里需要干的是将EspressoBased中的析构函数添加virtual属性***
    std::vector<Ingredient*>& sides = reinterpret_cast<Cappuccino*>(esp)->get_side_items();
    EXPECT_EQ(sides.size(), 1);
    delete esp;
    EXPECT_EQ(sides.size(), 0);
}

TEST(HW5Test, TEST7) {
    Cappuccino cappuccino;
    cappuccino.add_side_item(new Chocolate{2});

    for (const auto& i : cappuccino.get_ingredients()) {
        std::cout << i->get_name() << std::endl;
    }

    for (const auto& i : cappuccino.get_side_items()) {
        std::cout << i->get_name() << std::endl;
    }

    Cappuccino copy{cappuccino};

    for (const auto& i : copy.get_ingredients()) {
        std::cout << i->get_name() << std::endl;
    }

    for (const auto& i : copy.get_side_items()) {
        std::cout << i->get_name() << std::endl;
    }

    std::cout << copy.get_name() << std::endl;
    std::cout << copy.price() << std::endl;

    EXPECT_EQ(copy.get_name(), "Cappuccino");
    EXPECT_DOUBLE_EQ(copy.price(), 65);
}

TEST(HW5Test, TEST8) {
    Cappuccino cappuccino;
    cappuccino.add_side_item(new Water{1});
    Cappuccino equal;
    equal.add_side_item(new Sugar{1});
    equal = cappuccino;
    EXPECT_EQ(equal.price(), 56);
}

TEST(HW5Test, TEST9) {
    Cappuccino equal;
    equal.add_side_item(new Sugar{2});
    equal = equal;
    EXPECT_EQ(equal.price(), 57);
}

TEST(HW5Test, TEST10) {
    Mocha mocha{};
    EXPECT_EQ(mocha.get_name(), "Mocha");
    auto ingredients = mocha.get_ingredients();

    EXPECT_EQ(ingredients.size(), 4);
    for(const auto& i : ingredients)
        EXPECT_TRUE(i->get_name() == "Espresso" || i->get_name() == "Milk" || i->get_name() == "MilkFoam" || i->get_name() == "Chocolate");
    EXPECT_DOUBLE_EQ(mocha.price(), 60);

    EspressoBased* esp{new Mocha{}};
    reinterpret_cast<Cappuccino*>(esp)->add_side_item(new Cookie{1});
    reinterpret_cast<Cappuccino*>(esp)->add_side_item(new Sugar{2});
    std::vector<Ingredient*>& sides = reinterpret_cast<Cappuccino*>(esp)->get_side_items();
    EXPECT_EQ(sides.size(), 2);
    delete esp;
    EXPECT_EQ(sides.size(), 0);
}

TEST(HW5Test, TEST11) {
    Cappuccino cappuccino{};
    cappuccino.brew();
}

TEST(HW5Test, TEST12) {
    Mocha mocha{};
    mocha.brew();
}





