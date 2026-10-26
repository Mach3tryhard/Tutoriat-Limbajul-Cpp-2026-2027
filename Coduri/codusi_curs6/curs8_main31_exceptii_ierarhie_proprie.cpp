#include <iostream>
#include <stdexcept>
#include <fmiv2.h>


class SchoolError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class StudentError : public SchoolError {
    using SchoolError::SchoolError;
};
class TeacherError : public SchoolError {
    using SchoolError::SchoolError;
};

class Student {
    bool m_tired = false;
public:
    Student(bool tired) : m_tired(tired) {}
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
    std::string getLecture() const { return "oop_lecture.ppt"; }
};

int main() {
    try {
        Student st1(false), st2(true);
        Teacher t1(false, false), t2(false, true);
        st1.studyLate();   // might throw StudentError
        t1.prepareLate();  // might throw TeacherError
        FMIComputer::loadPPT(t1.getLecture()); // might throw PPTError : public std::runtime_error
        st2.studyLate();   // might throw StudentError
        t2.prepareLate();  // might throw TeacherError
    } catch(StudentError& err) {
        std::cout << "stud: " << err.what() << "\n";   // am prins eroare specifică din codul nostru
    } catch(SchoolError& err) {
        std::cout << "eroare de la noi: " << err.what() << "\n";   // am prins eroare generică din codul nostru
    } catch(PPTError& err) {
        std::cout << "eroare ppt: " << err.what() << "\n";   // am prins eroare specifică din <fmiv2.h>
    } catch(FMIError& err) {
        std::cout << "eroare externa: " << err.what() << "\n";   // am prins eroare generică din <fmiv2.h>
    } catch(std::runtime_error& err) {
        std::cout << err.what() << "\n";   // am prins o altă eroare
    }
}
