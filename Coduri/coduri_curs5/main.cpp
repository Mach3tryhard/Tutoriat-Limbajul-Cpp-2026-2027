#include <iostream>
#include <vector>

#include "Baza.h"
#include "Derivata.h"

class Zombie {
protected:
    int creieri_prajiti;
    double viteza;
    std::string nume;
public:
    virtual void vorbeste() const = 0;

    Zombie(int creieri_adunati, double viteza, const std::string &nume)
        : creieri_prajiti(creieri_adunati),
          viteza(viteza),
          nume(nume) {
    }

    virtual ~Zombie() = default;
    Zombie() {}
};

class Profesor : public  Zombie {
public:
    void vorbeste() const override {
        std::cout << "ough... [academic]\n";
    }

    Profesor(int creieri_adunati, double viteza, const std::string &nume)
        : Zombie(creieri_adunati, viteza, nume) {
    }
    Profesor(int) {}
    // void dubios() & {}
};

class Student : public  Zombie {
public:
    // void dubios() {}
    void vorbeste() const override {
        std::cout << "ough... [studențește]\n";
    }
};

class StudentMaster : public Student, public Profesor {
    StudentMaster() : Profesor(2), Student() {}
    long traume;
    void f() {
        // Student::creieri_prajiti;
        // Profesor::creieri_prajiti;
    }
};

class Facultate {
    std::string nume;
    // std::vector<Student> studenti;
    // Profesor paznic;
    // bool aviz_isu = false;
    std::vector<Zombie*> personal;
    public:
    void festivitate() {
        for (const auto & zombie: personal) {
            zombie->vorbeste();
        }
    }
[[nodiscard]] std::string get_nume() const {
        return nume;
    }

    // [[nodiscard]] std::vector<Student> get_studenti() const {
    //     return studenti;
    // }

};

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
/*int main() {
    Facultate fac;
    std::cout << fac.get_nume();
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}*/

#include <iostream>

class Dispozitiv {
    bool in_use;
public:
    Dispozitiv() {
        in_use = false;
        std::cout << "constr dispozitiv\n";
    }
    // constr de copiere
    Dispozitiv(const Dispozitiv& other) : in_use(other.in_use) {
        std::cout << "cc dispozitiv\n";
    }
    ~Dispozitiv() { std::cout << "destr dispozitiv\n"; }
    void start() { in_use = true; }
    bool status() const { return in_use; }
    void stop() { in_use = false; }
};

class Proiector : public Dispozitiv {
    std::string model;
    int scara = 1;
    int nr_butoane{};
    char categorie = 'c';
public:
    Proiector() : Dispozitiv(), model("digital projection"), scara(1) {
        std::cout << "constr proiector\n";
    }
    Proiector(const Proiector& other) : Dispozitiv(other) {
        std::cout << "cc Proiector\n";
    }
    ~Proiector() {
        std::cout << "destr proiector\n";
    }
    void foloseste() {
        start(); // Different name call
        std::cout << "proiecteaza lectie\n";
        scara = 0;
    }
    bool status() {
        return Dispozitiv::status() && scara > 0; // Same-name function call
    }
};

class Sala {
    Dispozitiv disp;
public:
    void prezinta() {
        disp.start();
    }
};


// SOLID
// S - single responsibility principle
// O - open for extension - closed for modification principle
// L - Liskov substitution principle
// I - interface segregation principle
// D - dependency inversion principle

void f(const Baza& b) {
    std::cout << "apelat f\n";
}

class Bazaaa {
    int x;
    int y;
public:
    virtual ~Bazaaa() = default;
    Bazaaa(int x_, int y_) : x(x_), y(y_) {}
};
class Der1 : public virtual Bazaaa {
public:
    Der1(int x_, int y_)
        : Bazaaa(x_, y_) {
    }
};
class Der2 : public virtual Bazaaa {
public:
    Der2(int x_, int y_)
        : Bazaaa(x_, y_) {
    }
};
class DerM : public Der1, public Der2 {
public:
    DerM(int x_, int y_, int x, int y)
        : Bazaaa(2, 10), Der1(x_, y_),
          Der2(x, y) {
    }
};

class B1 {};
class D1 : public B1 {};
class B2 {
    virtual void f() {}
    virtual void f2() {}
    virtual void f3() {}
public:
    virtual B2* chestie() {
        return this;
    }
};
class D2 : public B2 {
public:
    D2* chestie() override;
};

int main() {
    B2 b;
    b.chestie();
    D2 d222;
    B2& b_ref = d222;
    B2* rez1 = b_ref.chestie();
    d222.chestie();
    D2* rez2 = d222.chestie();
    std::cout << sizeof(B1) << " " << sizeof(D1) << "\n";
    std::cout << sizeof(B2) << " " << sizeof(D2) << "\n";
    // Zombie z1;
    f(Baza{});
    f(Derivata{});
    Baza b1;
    b1.h();
    Derivata d11;
    d11.h();
    d11.h(1);
    Baza::sf();
    Baza::sf(1);
    // Derivata::sf();
    // Derivata::sf(2);
    d11.haha();
    d11.z;
    std::cout << sizeof(Dispozitiv) <<  "   "<< ' ' << sizeof(Proiector);
    Dispozitiv d1; d1.start();
    Proiector pr, pr2(pr);
    pr.start(); // funcție din interfața clasei Dispozitiv
    pr.stop();
    pr.foloseste();
    std::cout << (pr.status() ? "on" : "off") << "\n"; // Redefined functions hide base versions:
    Dispozitiv& disp = pr;
    Dispozitiv disp2 = pr;
    std::cout << (disp.status() ? "on" : "off") << "\n";
}
