#include <vector>
#include <iostream>
#include <memory>

class Instrument {
public:
    virtual ~Instrument() = 0;
    virtual void play(int) const {}
    virtual std::shared_ptr<Instrument> clone() const = 0;
};
Instrument::~Instrument() = default;

class Wind : public Instrument {
public:
    /* implementare play */
    std::shared_ptr<Instrument> clone() const override {
        return std::make_shared<Wind>(*this);  // apelăm cc
    }
};
class String : public Instrument {
public:
    /* implementare play */
    std::shared_ptr<Instrument> clone() const override {
        return std::make_shared<String>(*this);
    }
};

class Sala {
    std::string nume;
public:
    friend void swap(Sala& s1, Sala& s2) {
        using std::swap;
        swap(s1.nume, s2.nume);
        std::cout << "swap sala\n";
    }
};

class Orchestra {
    std::vector<std::shared_ptr<Instrument>> instruments;
    Sala sala;
public:
    void add(std::shared_ptr<Instrument> inst) { instruments.push_back(inst->clone()); }
    void rehearse() {
        for(const auto& inst : instruments)
            inst->play(0);
    }
    Orchestra() = default;
    Orchestra(const Orchestra& other) {
        for(const auto& inst : other.instruments) {
            instruments.push_back(inst->clone());
        }
    }
    Orchestra& operator=(Orchestra other) {
        if(this == &other)
            return *this;
        
        swap(*this, other);
        return *this;
    }
    friend void swap(Orchestra& o1, Orchestra& o2) {
        using std::swap;
        swap(o1.instruments, o2.instruments);  // std::swap
        swap(o1.sala, o2.sala);                // swap din clasa Sala
    }
};

int main() {
    Orchestra o1;
    auto wind = std::make_shared<Wind>();
    auto string = std::make_shared<String>();
    o1.add(wind);
    o1.add(string);
    // vrem să facem delete aici pt că ar fi bine să facem delete unde facem și new
    o1.rehearse();
    Orchestra o2 = o1;
    // sau
    // Orchestra o3(o1);
    Orchestra o4;
    o4 = o1;
}
