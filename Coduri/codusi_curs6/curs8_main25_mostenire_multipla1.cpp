#include <iostream>

class base {
//public:
    int i;
};

class derived1 : virtual public base {
//public:
    // base::i sizeof 4
    int j;  // sizeof 4
    // +8 de la virtual
};

class derived2 : virtual public base {
//public:
    int k;
};

class derived3 : public derived1, public derived2 {
//public:
    // base::i sizeof 4
    // derived1::j sizeof 4
    // derived2::k sizeof 4
    int sum;  // sizeof 4
    // +8 de la un virtual
    // +8 de la al doilea virtual
    // +8 padding (posibil 4+4) // total 40 pe GCC/Clang
};

int main() {
    std::cout << sizeof(base) << '\n';
    std::cout << sizeof(derived1) << '\n';
    std::cout << sizeof(derived3) << '\n';
}
