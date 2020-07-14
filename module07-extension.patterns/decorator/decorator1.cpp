#include <iostream>

struct drink {
    virtual double get_price() = 0;
};

struct drink_decorator : public drink {
    drink_decorator(drink *pDrink) : pDrink(pDrink) {}

protected:
    drink *pDrink;

};

struct coffee : public drink {
    double get_price() override {
        return 12.5;
    }
};

struct tea : public drink {
    double get_price() override {
        return 7.5;
    }
};

struct sugar : public drink_decorator {
    sugar(drink *pDrink) : drink_decorator(pDrink) {}

    double get_price() override {
        return pDrink->get_price() + 1.;
    }

};

struct milk : public drink_decorator {
    milk(drink *pDrink) : drink_decorator(pDrink) {}

    double get_price() override {
        return pDrink->get_price() + 2.;
    }

};


int main() {
    drink *coffeeWithSugar = new sugar(new sugar(new coffee));
    std::cout << coffeeWithSugar->get_price() << std::endl;
    drink *teaWithSugarAndMilk = new sugar(new milk(new tea));
    std::cout << teaWithSugarAndMilk->get_price() << std::endl;
    return 0;
}
