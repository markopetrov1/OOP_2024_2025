//
// Created by Marko on 12.5.25.
//
#include <iostream>
using namespace std;

class Vehicle{
protected:
    int acceleration;
public:
    Vehicle(){
        this->acceleration = 15;
        cout<<"Vehicle constructor called!"<<endl;
    }

    ~Vehicle(){
        cout<<"Vehicle destructor called!"<<endl;
    }

    int getAcceleration(){
        return acceleration;
    }
};

class Jet :  public Vehicle{
public:
    Jet(){
        cout<<"Jet constructor called!"<<endl;
    }

    ~Jet(){
        cout<<"Jet destructor called!"<<endl;
    }
};

class Car :  public Vehicle{
public:
    Car(){
        cout<<"Car constructor called!"<<endl;
    }

    ~Car(){
        cout<<"Car destructor called!"<<endl;
    }
};

class JetCar : public Jet, public Car{
public:
    JetCar(){
        cout<<"JetCar constructor called!"<<endl;
    }

    ~JetCar(){
        cout<<"JetCar destructor called!"<<endl;
    }
};

int main(){

    JetCar jetCar;

//    jetCar.getAcceleration();

    return 0;
}