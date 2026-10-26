#include <iostream>
#include <stdexcept>

class AppError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
class SomeCommonError : public AppError {
    using AppError::AppError;
};
class OtherCommonError : public AppError {
    using AppError::AppError;
};

class SomeSpecialError : public AppError {
    using AppError::AppError;
};
class OtherSpecialError : public AppError {
    using AppError::AppError;
};
class AnotherSpecialError : public AppError {
    using AppError::AppError;
};

void handleCommonErrors() {
    try {
        throw;
    } catch(SomeCommonError& err) {
        std::cout << "got some common error\n";
        /* handle error */
    } catch(OtherCommonError& err) {
        std::cout << "got other common error\n";
        /* handle error */
    } catch(AppError& err) {
        std::cout << "got app error\n";
        /* handle error */
    }
}

void f(int nr) {
    try {
        // cod care aruncă diverse erori
        switch(nr) {
            case 1:
                throw SomeSpecialError("special");
                break;
            case 2:
                throw OtherSpecialError("other special");
                break;
            case 3:
                throw SomeCommonError("so common");
                break;
            case 4:
                throw OtherCommonError("again so common");
                break;
        }
    } catch(SomeSpecialError& err) {
        std::cout << "got some special error\n";
        /* handle error */
    } catch(OtherSpecialError& err) {
        std::cout << "got other common error\n";
        /* handle error */
    } catch(...) { handleCommonErrors(); }
}

void g(int nr) {
    try {
        // cod care aruncă diverse erori
        switch(nr) {
            case 22:
                throw AnotherSpecialError("another special");
                break;
            case 33:
                throw SomeCommonError("so common..");
                break;
            case 43:
                throw OtherCommonError("so common again");
                break;
        }
    } catch(AnotherSpecialError& err) {
        std::cout << "got another common error\n";
        /* handle error */
    } catch(...) { handleCommonErrors(); }
}

int main() {
    int n = -1;
    std::cout << "n: ";
    std::cin >> n;
    f(n);
    g(n + 20);
}
