#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

template <typename T>
struct observer {
    virtual void field_changed(T& source, const std::string &field_name) = 0;
};

template <typename T>
struct observable {
    void notify(T &source,const std::string &name){
        for (auto &o : observers){
            o->field_changed(source, name);
        }
    }
    void attach(observer<T> *f){
        observers.push_back(f);
    }
    void detach(observer<T> *f){
        auto end = std::remove(observers.begin(),observers.end(),f);
        observers.erase(end, observers.end());
    }
private:
    std::vector<observer<T>*> observers;
};

struct stock : public observable<stock> {
    stock(const std::string &symbol, double price) : symbol(symbol), price(price) {}

    const std::string &getSymbol() const {
        return symbol;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        stock::price = price;
        notify(*this, "price");
    }

private:
    const std::string symbol;
    double price;
};

struct algotrader : observer<stock> {
    void field_changed(stock &source, const std::string &field_name) override {
          std::cout << "stock's " << field_name << " has changed to " << source.getPrice() << std::endl;
    }
};

int main(){
    stock dcl("deepc",42.);
    algotrader *pAlgotrader = new algotrader;
    dcl.attach(pAlgotrader);
    dcl.setPrice(42.1);
    dcl.setPrice(42.2);
    dcl.setPrice(42.3);
    dcl.detach(pAlgotrader);
    dcl.setPrice(42.4);
    return 0;
}