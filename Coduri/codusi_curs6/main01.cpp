#include <iostream>

class C1{};

class Baza {
public:
   virtual ~Baza() {}
   virtual void f() {}
   virtual int g() { return 1; }
   virtual void h(int, float) {}
   Baza* covariant() { return new Baza; }
};
//Baza::~Baza() = default;

void abc() {}
void abc(int, int) {}

class Derivata : public Baza {
public:
   void f() override { std::cout << "altceva"; }
   Derivata* covariant() { return new Derivata; }
   void der() {}
};

class Derivata2 : public Baza {
public:
   void f() override { std::cout << "altceva 2"; }
};

class Derivata3 : public Baza {
public:
   void f() override { std::cout << "altceva 3"; }
};


int main() {
    Derivata3 d;
    Derivata d1;
    Derivata* obiect = d1.covariant();
    int x;
    std::cin >> x;
    Baza* ptr;
    if(x == 1)
        ptr = new Derivata;
    else
        ptr = new Derivata2;
    ptr->f();
    delete ptr;
    //std::cout << sizeof(C1) << "\n";
//    std::cout << sizeof(C2) << "\n";
}
