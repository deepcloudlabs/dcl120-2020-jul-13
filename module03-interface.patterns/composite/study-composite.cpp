#include <vector>
#include <memory>

template <typename Self>
struct cell {
    template<typename T>
    void connect_to(T &other);
    template<typename T>
    T *begin();
    template<typename T>
    T *end();
};

// leaf
struct neuron : cell<neuron> {
    std::uint32_t id;
    std::vector<neuron *> in,out;

    neuron() {
        static int id= 1;
        this->id = id++;
    }

    neuron *begin() { return this;}
    neuron *end() { return this+1;}

};

// composite
struct layer : cell<layer> {
    std::vector<neuron> neurons;
    layer(int count){
        while (--count){
            neurons.emplace_back(neuron());
        }
    }
    auto begin() { return neurons.begin();}
    auto end() { return neurons.end();}
};

// cell
template <typename Self>
template<typename T>
void cell<Self>::connect_to(T &other) {
    for (neuron &from : *static_cast<Self*>(this)){
        for(neuron &to : other){
            from.out.push_back(&to);
            to.in.push_back(&from);
        }
    }
}

int main(){
    neuron n1, n2;
    layer layer1{1}, layer2{2};

    n1.connect_to(layer1);
    layer2.connect_to(n2);
    layer1.connect_to(layer2);
    n1.connect_to(n2);
}