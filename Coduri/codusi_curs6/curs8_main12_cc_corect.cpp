#include <vector>
#include <iostream>

class Instrument {
public:
    virtual ~Instrument() = 0;
    virtual void play(int) const {}
    virtual Instrument* clone() const = 0;
};
Instrument::~Instrument() = default;

class Wind : public Instrument {
public:
    /* implementare play */
    Instrument* clone() const override {
        return new Wind(*this);  // apelăm cc
    }
};
class String : public Instrument {
public:
    /* implementare play */
    Instrument* clone() const override {
        return new String(*this);
    }
};

class Orchestra {
    std::vector<Instrument*> instruments;
public:
    void add(Instrument* inst) { instruments.push_back(inst->clone()); }
    void rehearse() {
        for(const auto& inst : instruments)
            inst->play(0);
    }
    Orchestra() = default;
    ~Orchestra() {
        for(auto* inst : instruments)
            delete inst;
    }
    Orchestra(const Orchestra& other) {
        for(const auto& inst : other.instruments) {
            instruments.push_back(inst->clone());
        }
    }
};

int main() {
    Orchestra o1;
    auto* wind = new Wind;
    auto* string = new String;
    o1.add(wind);
    o1.add(string);
    // vrem să facem delete aici pt că ar fi bine să facem delete unde facem și new
    delete string;
    delete wind;
    o1.rehearse();
    Orchestra o2 = o1;
    // sau
    // Orchestra o3(o1);
}
