#include <iostream>

class Base {
protected:
    ~Base() = default;
};

class Derived1 : public Base {};
class Derived2 : public Base {};

int main() {
    Derived1 d1;
    Derived2 d2;
    // Base b; // error
}