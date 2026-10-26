#include <iostream>

class Pet { public: virtual ~Pet(){}};
class Dog : public Pet {};
class Cat : public Pet {};

int main() {
    Pet* b = new Cat; // Upcast
    if (auto* d1 = dynamic_cast<Dog*>(b)) {
        std::cout << "d1 = " << d1 << std::endl;
    }
    else if (auto* d2 = dynamic_cast<Cat*>(b)) {
        std::cout << "d2 = " << d2 << std::endl;  // b și d2 rețin aceeași adresă
        std::cout << "b  = " << b  << std::endl;
    }
    try {
        auto& d1 = dynamic_cast<Dog&>(*b);  // dacă nu reușește, se aruncă excepție
        auto& d2 = dynamic_cast<Cat&>(*b);
    } catch(std::bad_cast&) { std::cout << "eroare cast\n"; }
}

