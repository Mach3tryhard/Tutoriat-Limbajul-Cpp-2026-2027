#include <iostream>

class Subject {
public:
 virtual ~Subject();
 virtual void Attach(Observer*);
 virtual void Detach(Observer*);
 virtual void Notify();
protected:
 Subject();
private:
 List<Observer*> *_observers;
};
void Subject::Attach (Observer* o) {_observers->Append(o); }
void Subject::Detach (Observer* o) {_observers->Remove(o); }
void Subject::Notify () {
 ListIterator<Observer*> i(_observers);
 //construieste un iterator, i, pentru containerul_observers
 for (i.First(); !i.IsDone(); i.Next()) { i.CurrentItem()->Update(this);}
}
