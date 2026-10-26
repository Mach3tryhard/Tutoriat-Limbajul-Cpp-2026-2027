#include <iostream>

class base {
    int i;
public:
    base(int z) : i(z) {}
};

class derived1 : virtual public base {
    // base::i sizeof 4
    int j;  // sizeof 4
    // +8 de la virtual
public:
    derived1() : base(1) {}
};

class derived2 : virtual public base {
    int k;
public:
    derived2() : base(2) {}
};

class derived3 : public derived1, public derived2 {
    // base::i sizeof 4
    // derived1::j sizeof 4
    // derived2::k sizeof 4
    int sum;  // sizeof 4
    // +8 de la un virtual
    // +8 de la al doilea virtual
    // +8 padding (posibil 4+4) // total 40 pe GCC/Clang
public:
    derived3() : base(3), derived1(), derived2() {}
};

int main() {
    std::cout << sizeof(base) << '\n';
    std::cout << sizeof(derived1) << '\n';
    std::cout << sizeof(derived3) << '\n';
}
