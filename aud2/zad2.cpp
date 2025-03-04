//
// Created by Marko on 2.3.25.
//
#include <iostream>
#include <cstring>
using namespace std;

enum EmployeeType{
    BASIC,
    MANAGER,
    OWNER
};

class Employee{
private:
    char name[50];
    int salary;
    EmployeeType type;
public:
    Employee(char * _name = "John", int _salary = 50000, EmployeeType _type = EmployeeType(1)){
        strcpy(name, _name);
        salary = _salary;
        type = _type;
    }

    ~Employee(){}

    char * getName(){
        return name;
    }

    int getSalary(){
        return salary;
    }

    EmployeeType getType(){
        return type;
    }

    void setName(char * _name){
        strcpy(name, _name);
    }

    void setSalary(int _salary){
        salary = _salary;
    }

    void setType(EmployeeType _type){
        type = _type;
    }

    void print(){
        cout<<"Employee: "<<name<<", Salary: "<<salary<<" Type: ";

        switch (type) {
            case 0:
                cout<<"BASIC"<<endl;
                break;
            case 1:
                cout<<"MANAGER"<<endl;
                break;
            default:
                cout<<"OWNER"<<endl;
        }
    }

};

int main(){
    Employee employees[100];
    int n, salary, type;
    char name[50];


    cin>>n;

    for(int i=0;i<n;i++){
        cin>>name>>salary>>type;
        employees[i].setName(name);
        employees[i].setSalary(salary);
        employees[i].setType(EmployeeType(type));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(employees[i].getSalary() > employees[j].getSalary())
            {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        employees[i].print();
    }

    return 0;
}

//
//5
//Stefan 15000 0
//John 33000 1
//Marko 10000 0
//Nikola 100000 2
//Ana 55000 1
//
