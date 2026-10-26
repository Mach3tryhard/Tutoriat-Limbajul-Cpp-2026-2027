#include <vector>

class Instrument {
public:
    virtual ~Instrument() = 0;
    virtual void play(int) const {}
};
Instrument::~Instrument() = default;

class Wind : public Instrument { /* implementare play */ };
class String : public Instrument { /* implementare play */ };

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
};

int main() {
    Orchestra o1;
    o1.add(new Wind);
    o1.add(new String);
    o1.rehearse();
}
