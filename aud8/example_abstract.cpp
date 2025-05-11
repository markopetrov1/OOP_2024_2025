#include <iostream>
#include <cstring>

using namespace std;

class Payment{
protected:
    int amount;
public:
    Payment(int amount){
        this->amount = amount;
    }

    virtual void processPayment() = 0;

    virtual void printInfo(){
        cout<<"Processing payment for user..."<<endl;
    }
};

class CashPayment : public Payment{
public:
    CashPayment(int amount) : Payment(amount){

    }

    void printInfo(){
        cout<<"Processing cash payment for user..."<<endl;
    }


    void processPayment(){
        cout<<"Processed cash payment with amount "<<amount<<" USD"<<endl;
    }

};

class CreditCardPayment : public Payment{
public:
    CreditCardPayment(int amount) : Payment(amount){

    }

    void printInfo(){
        cout<<"Processing credit card payment for user..."<<endl;
    }

    void processPayment(){
        cout<<"Processed credit card payment with amount "<<amount<<" USD"<<endl;
    }

};

int main(){
    int n, type, amount;
    cin>>n;
    Payment **payments = new Payment * [n];


    for(int i=0;i<n;i++){
        cin>>type>>amount;
        if(type == 1){
            payments[i] = new CashPayment(amount);
        }
        else{
            payments[i] = new CreditCardPayment(amount);
        }
    }

    for(int i=0;i<n;i++){
        payments[i]->printInfo();
        payments[i]->processPayment();
    }

    return 0;
}
