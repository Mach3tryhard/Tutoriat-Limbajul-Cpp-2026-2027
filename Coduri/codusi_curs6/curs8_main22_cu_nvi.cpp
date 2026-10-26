#include <vector>
#include <iostream>
#include <chrono>

class Instrument {
public:
    virtual ~Instrument() = 0;
    virtual Instrument* clone() const = 0;
    void perform(int note) const {
        using namespace std::literals;
        readNote(note);
        prepare();
        play(note);
        rest(10ms);
    }
private:
    virtual void play(int) const {}
    void readNote(int) const {}
    void prepare() const {}
    void rest(auto) const {}
};
Instrument::~Instrument() = default;

class Wind : public Instrument {
    void play(int note) const override {
        std::cout << "play wind\n";
    }
public:
    Wind* clone() const override {
        return new Wind(*this);  // apelăm cc
    }
    void sufla() { std::cout << "sufla\n"; }
};
class String : public Instrument {
    void play(int note) const override {
        std::cout << "play string\n";
    }
public:
    String* clone() const override {
        return new String(*this);
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
    std::vector<Instrument*> instruments;
    Sala sala;
public:
    void add(Instrument* inst) { instruments.push_back(inst->clone()); }
    void rehearse() {
        for(const auto& inst : instruments)
            inst->perform(0);
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
    Orchestra o4;
    o4 = o1;
    Instrument* ptr1 = new Wind;
    // ptr1->sufla();  // eroare: ‘class Instrument’ has no member named ‘sufla’
    // Wind* ptr2 = ptr1; // eroare:  invalid conversion from ‘Instrument*’ to ‘Wind*’
    delete ptr1;
    Wind* ptr3 = new Wind;
    Wind* ptr4 = ptr3->clone();
    delete ptr3;
    delete ptr4;
}
