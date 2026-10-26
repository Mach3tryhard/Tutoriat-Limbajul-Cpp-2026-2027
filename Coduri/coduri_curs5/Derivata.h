//
// Created by marius on 31.10.2025.
//

#ifndef CURS5_2025_DERIVED_H
#define CURS5_2025_DERIVED_H
#include <iostream>

#include "Baza.h"


class Derivata : public Baza {
    void k();
    int q{};

public:
    Derivata(int x, int y, int z, int q)
        : Baza(x, y, z),
          q(q) {
    }
    using Baza::h;
    using Baza::Baza;
    void h(int) {}

    Derivata(const Derivata &other)
        : Baza(other),
          q(other.q) {
    }
    // static void sf() {}

    Derivata & operator=(const Derivata &other) {
        if (this == &other)
            return *this;
        Baza::operator =(other);
        q = other.q;
        return *this;
    }

    Derivata() = default;
};


#endif //CURS5_2025_DERIVED_H