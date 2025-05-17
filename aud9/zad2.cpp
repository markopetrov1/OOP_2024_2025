//
// Created by Marko on 12.5.25.
//
#include <iostream>
#include <cstring>
using namespace std;

class Product{
protected:
    char name[50];
    double price;
public:
    Product(char *name, double price){
        strcpy(this->name, name);
        this->price = price;
    }

    virtual ~Product(){}

    char * getName(){
        return name;
    }

    double getPrice(){
        return price;
    }
};

class Discount{
public:
    virtual double getPrice() = 0;
    virtual double getPriceWithDiscount() = 0;
};

class FoodProduct : public Product, public Discount{
private:
    int calories;
public:
    FoodProduct(char *name, double price, int calories) : Product(name, price){
        this->calories = calories;
    }

    ~FoodProduct(){}

    double getPrice() override{
        return price;
    }

    double getPriceWithDiscount() override{
        return price*0.9;
    }

};

class DigitalProduct : public Product, public Discount{
private:
    double size;
public:
    DigitalProduct(char *name, double price, double size) : Product(name, price){
        this->size = size;
    }
    ~DigitalProduct(){}

    double getPriceWithDiscount() override{
        return price*0.85;
    }

    double getPrice() override{
        return price;
    }
};

double getTotalDiscountForProducts(Discount **discountedProducts, int n){
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum += (discountedProducts[i]->getPrice() - discountedProducts[i]->getPriceWithDiscount());
    }
    return sum;
}

int main(){
    int n, type, calories;
    double size, price;
    char name[50];
    cin>>n;
    Discount **discountedProducts = new Discount * [n];

    for(int i=0;i<n;i++){
        cin>>type>>name>>price;
        if(type == 1){
            cin>>calories;
            discountedProducts[i] = new FoodProduct(name,price,calories);
        }
        else{
            cin>>size;
            discountedProducts[i] = new DigitalProduct(name,price,size);
        }
    }

    cout<<getTotalDiscountForProducts(discountedProducts, n);


    return 0;
}


