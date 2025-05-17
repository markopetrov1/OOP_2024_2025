//
// Created by Marko on 12.5.25.
//
#include <iostream>
#include <cstring>
using namespace std;

class NegativeValueException{
private:
    char message[100];
public:
    NegativeValueException(char *message){
        strcpy(this->message, message);
    }

    void showMessage(){
        cout<<message<<endl;
    }
};

class Discount{
public:
    virtual float getDiscountPrice() = 0;
    virtual float getPrice() = 0;
    virtual void printRule() = 0;

    static double eur_to_mkd;
    static double usd_to_mkd;
};

double Discount::eur_to_mkd=61.53;
double Discount::usd_to_mkd=54.96;

class Product{
protected:
    char name[50];
    double price;
public:
    Product(char *name, double price){
        strcpy(this->name, name);
        this->price = price;
    }

    virtual void changePrice(double price){
        if(price < 0){
            throw NegativeValueException("Negative value for price!");
        }
        this->price = price;
    }
};

class FoodProduct : public Product, public Discount{
private:
    int calories;
public:
    FoodProduct(char *name, double price, int calories) : Product(name ,price){
        this->calories = calories;
    }

    float getPrice() override{
        return price;
    }

    float getDiscountPrice() override{
        return price;
    }

    void printRule() override{
        cout<<"Според новата политика на продавницата храната нема попуст"<<endl;
    }

};

class Drinks : public Product, public Discount{
private:
    char brand[50];
    bool isAlcoholic;
public:
    Drinks(char *name, double price, char *brand, bool isAlcoholic) : Product(name ,price){
        strcpy(this->brand, brand);
        this->isAlcoholic = isAlcoholic;
    }

    float getPrice() override{
        return price;
    }

    float getDiscountPrice() override{
        if(isAlcoholic && (price / Discount::eur_to_mkd) > 20 ){
            return price*0.95;
        }

        if(!isAlcoholic && strcmp(brand, "Coca-Cola") == 0){
            return price*0.9;
        }

        return price;
    }

    void printRule() override{
        cout<<"Пијалоците и тоа алкохолните поскапи од 20 евра имаат попуст 5%, а неалкохолните од брендот Coca-Cola имаат попуст од 10%"<<endl;
    }
};

class Cosmetics : public Product, public Discount{
private:
    int weight;
public:
    Cosmetics(char *name, double price, int weight) : Product(name ,price){
        this->weight = weight;
    }

    float getPrice() override{
        return price;
    }

    float getDiscountPrice() override{
        if(price / Discount::eur_to_mkd > 5){
            return price*0.88;
        }

        if(price / Discount::usd_to_mkd > 20){
            return price*0.86;
        }
    }

    void printRule() override{
        cout<<"Сите козметички производи поскапи од 5 евра имаат попуст 12%, а оние поскапи од 20 долари имаат попуст 14%"<<endl;
    }

};

int main(){
    int n, type, weight, calories;
    char brand[50], name[50];
    bool isAlcoholic;
    double price;
    cin>>n;
    Product **products = new Product * [n];

    for(int i=0;i<n;i++){
        cin>>type>>name>>price;
        if(type == 1){
            cin>>calories;
            products[i] = new FoodProduct(name, price, calories);
        }
        else if(type == 2){
            cin>>brand>>isAlcoholic;
            products[i] = new Drinks(name, price, brand, isAlcoholic);
        }
        else{
            cin>>weight;
            products[i] = new Cosmetics(name, price, weight);
        }
    }

    for(int i=0;i<n;i++){
        Cosmetics * cosmeticProduct = dynamic_cast<Cosmetics *>(products[i]);

        if(cosmeticProduct){
            try{
                cosmeticProduct->changePrice(750);
            }
            catch (NegativeValueException e){
                e.showMessage();
            }
        }
    }
    return 0;
}