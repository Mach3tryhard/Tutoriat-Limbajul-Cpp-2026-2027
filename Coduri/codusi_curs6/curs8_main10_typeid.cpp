#include <vector>
#include <iostream>

class Instrument {
public:
    virtual ~Instrument() = 0;
    virtual void play(int) const {}
};
Instrument::~Instrument() = default;

class Wind : public Instrument {
public:
    /* implementare play */
};
class String : public Instrument {
public:
    /* implementare play */
};

class Orchestra {
    std::vector<Instrument*> instruments;
public:
    void add(Instrument* inst) { instruments.push_back(inst); }
    void rehearse() {
        for(const auto& inst : instruments)
            if(inst)
                inst->play(0);
    }
    ~Orchestra() {
        for(auto* inst : instruments)
            delete inst;
    }
    Orchestra() = default;
    Orchestra(const Orchestra& other) {
        for(const auto& inst : other.instruments) {
            if(!inst)
                continue;
            // nu avem voie să facem typeid pe pointer nul polimorfic
            // pentru că este dereferențiat
            if(typeid(*inst) == typeid(Wind)) {
                instruments.push_back(new Wind(static_cast<Wind&>(*inst)));
                // sau
                // instruments.push_back(new Wind(*static_cast<Wind*>(inst)));
                std::cout << "copiez wind\n";
            }
            else if(typeid(*inst) == typeid(String)) {
                instruments.push_back(new String(static_cast<String&>(*inst)));
                std::cout << "copiez string\n";
            }
        }
    }
};

int main() {
    Orchestra o1;
    o1.add(new Wind);
    o1.add(new String);
    o1.add(nullptr);
    o1.rehearse();
    Orchestra o2 = o1;
    // sau
    // Orchestra o3(o1);
}
