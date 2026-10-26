#include <iostream>

enum note { middleC, Csharp, Eflat }; // Etc.

class Instrument {
public:
    virtual void play(note) const = 0;
};
void Instrument::play(note) const { std::cout << "Instrument::play" << std::endl; }

class Wind : public Instrument {
public:
    void play(note) const override { std::cout << "Wind::play" << std::endl; }};

class String : public Instrument {
public:
    void play(note) const override { std::cout << "String::play" << std::endl; }};

void tune(Instrument& i) {  i.play(middleC);  }

int main() {
    Wind flute;
    String cello;
    tune(flute);
    tune(cello);
}
