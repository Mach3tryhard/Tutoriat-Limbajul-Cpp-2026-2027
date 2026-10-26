#include <vector>

class Instrument {
public:
    enum tip {wind, string};
    virtual ~Instrument() = 0;
    virtual void play(int) const {}
    Instrument(tip tip_) : mTip(tip_) {}
    tip getTip() const { return mTip; }
private:
    tip mTip;
};
Instrument::~Instrument() = default;

class Wind : public Instrument {
public:
    Wind() : Instrument(tip::wind) {}
    /* implementare play */
};
class String : public Instrument {
public:
    String() : Instrument(tip::string) {}
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
            // sau Instrument::tip::wind
            if(inst->getTip() == Instrument::wind)
                instruments.push_back(new Wind(*static_cast<Wind*>(inst)));
            else if(inst->getTip() == Instrument::string)
                instruments.push_back(new String(*static_cast<String*>(inst)));
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
