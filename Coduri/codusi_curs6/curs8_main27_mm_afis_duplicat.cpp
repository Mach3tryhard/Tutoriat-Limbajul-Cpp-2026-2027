#include <iostream>

class base {
    int i{1};  // sizeof 4
    // +8 funcție virtuală
    // +4 padding
protected:
    virtual void afis(std::ostream& os) const {
        os << "i: " << i << "\n";
    }
public:
    virtual ~base() = default;
    base() = default;
    base(const base&) = default;
    base& operator=(const base&) = default;
    friend std::ostream& operator<<(std::ostream& os, const base& b) {
        b.afis(os);
        return os;
    }
};

class derived1 : virtual public base {
    // base::i sizeof 4
    int j{2};  // sizeof 4
    // +8 de la virtual public
    // +8 de la funcție virtual
    // +8 padding
protected:
    void afis(std::ostream& os) const override {
        base::afis(os);
        os << "j: " << j << "\n";
    }
};

class derived2 : virtual public base {
    int k{3};
protected:
    void afis(std::ostream& os) const override {
        base::afis(os);
        os << "k: " << k << "\n";
    }
};

class derived3 : public derived1, public derived2 {
    // base::i sizeof 4
    // derived1::j sizeof 4
    // derived2::k sizeof 4
    int l{4};  // sizeof 4
    // +8 de la un virtual public
    // +8 de la al doilea virtual public
    // +8 de la funcții virtuale
    // +8 padding (posibil 4+4) // total 48 pe GCC/Clang
protected:
    void afis(std::ostream& os) const override {
        derived1::afis(os);
        derived2::afis(os);
        os << "l: " << l << "\n";
    }
};

int main() {
    std::cout << sizeof(base) << '\n';
    std::cout << sizeof(derived1) << '\n';
    std::cout << sizeof(derived3) << '\n';
    base* b = new derived3;
    std::cout << *b;
    delete b;
}
