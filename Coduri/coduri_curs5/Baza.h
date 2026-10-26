//
// Created by marius on 31.10.2025.
//

#ifndef CURS5_2025_BAZA_H
#define CURS5_2025_BAZA_H


class Baza {
    int x{};
    void f();

protected:
    int y{};
    void g();

public:
    int z{};
    void h();
    void haha() {}

    Baza(int x, int y, int z)
        : x(x),
          y(y),
          z(z) {
    }

    Baza() = default;
    static void sf() {}
    static void sf(int) {}
};


#endif //CURS5_2025_BAZA_H