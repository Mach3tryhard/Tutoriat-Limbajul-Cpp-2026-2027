#include <iostream>

class AbstractBase {
public:
    virtual ~AbstractBase() = 0;
};

AbstractBase::~AbstractBase() = default;
// sau
// AbstractBase::~AbstractBase() {}

class Derived : public AbstractBase {};

int main() {
    Derived d;
}