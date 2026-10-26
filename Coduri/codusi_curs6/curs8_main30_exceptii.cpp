#include <iostream>
#include <stdexcept>
#include <fmi.h>


class StudentError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
class TeacherError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Student {
    bool m_tired = false;
public:
    void studyLate() {
        std::cout << "studying for exams...\n";
        if(m_tired)
            throw StudentError{"zzz..."};
    }
};

class Teacher {
    bool m_tired = false;
    bool m_busy = false;  // replace with true
public:
    Teacher(bool tired, bool busy) : m_tired(tired), m_busy(busy) {}
    void prepareLate() {
        std::cout << "preparing kahoot...\n";
        if(m_tired || m_busy)
            throw TeacherError{"zzz AND busy"};
    }
    std::string getLecture() const { return "oop_lecture.pptx"; }
};

int main() {
    try {
        Student st1, st2;
        Teacher t1(false, false), t2(false, true);
        st1.studyLate();   // might throw StudentError
        t1.prepareLate();  // might throw TeacherError
        FMIComputer::loadPPT(t1.getLecture()); // might throw PPTError : public std::runtime_error
        st2.studyLate();   // might throw StudentError
        t2.prepareLate();  // might throw TeacherError
    } catch(std::runtime_error& err) {
        std::cout << err.what() << "\n";   // am prins eroare din codul nostru sau din <fmi.h>?
    }
}
