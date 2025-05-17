//
// Created by Marko on 16.5.25.
//

#include <iostream>
using namespace std;
class Base {
public:
    ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor\n"; }
};

int main(){
    Base* obj = new Derived();
    delete obj;  // only Base's destructor will be called!

    return 0;
}


//class Base {
//public:
//    virtual ~Base() { std::cout << "Base destructor\n"; }
//};
//
//class Derived : public Base {
//public:
//    ~Derived() { std::cout << "Derived destructor\n"; }
//};
//
//Base* obj = new Derived();
//delete obj; //  ------  both destructors are called!
