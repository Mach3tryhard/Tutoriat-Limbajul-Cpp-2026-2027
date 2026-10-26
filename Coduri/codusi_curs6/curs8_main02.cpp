#include <iostream>

class Base1 {
public:
    ~Base1() { std::cout << "~Base1()\n"; }
};

class Derived1 : public Base1 {
public:
    ~Derived1() { std::cout << "~Derived1()\n"; }
};

class Base2 {
public:
    virtual ~Base2() { std::cout << "~Base2()\n"; }
};

class Derived2 : public Base2 {
public:
    ~Derived2() { std::cout << "~Derived2()\n"; }
};

int main() {
    Base1* bp = new Derived1;
    delete bp; // Afis: ~Base1()
    Base2* b2p = new Derived2;
    delete b2p; // Afis: ~Derived2()  ~Base2()
}

