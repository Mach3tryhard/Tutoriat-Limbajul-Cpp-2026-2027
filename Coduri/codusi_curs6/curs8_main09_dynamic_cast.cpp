#include <vector>

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
            inst->play(0);
    }
    ~Orchestra() {
        for(auto* inst : instruments)
            delete inst;
    }
    Orchestra() = default;
    Orchestra(const Orchestra& other) {
        for(const auto& inst : other.instruments)
            if(auto* wind = dynamic_cast<Wind*>(inst))
                instruments.push_back(new Wind(*wind));
            else if(auto* string = dynamic_cast<String*>(inst))
                instruments.push_back(new String(*string));
    }
};

int main() {
    Orchestra o1;
    o1.add(new Wind);
    o1.add(new String);
    o1.rehearse();
    Orchestra o2 = o1;
    // sau
    // Orchestra o3(o1);
}
