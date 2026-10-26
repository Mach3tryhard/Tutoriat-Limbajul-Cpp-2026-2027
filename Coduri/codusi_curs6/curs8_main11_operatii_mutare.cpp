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
            inst->play(0);
    }
    ~Orchestra() = default;
    Orchestra() = default;
    Orchestra(const Orchestra& other) = delete;
    Orchestra& operator=(const Orchestra& other) = delete;
    Orchestra(Orchestra&& other) = default;
    Orchestra& operator=(Orchestra&& other) = default;
};

int main() {
    Orchestra o1;
    auto* wind = new Wind;
    auto* string = new String;
    o1.add(wind);
    o1.add(string);
    o1.rehearse();
    Orchestra o2 = std::move(o1);
    // în acest punct, "conținutul" din o1 nu este valid
    delete string;
    delete wind;
    // sau
    // Orchestra o3(std::move(o2));
}
