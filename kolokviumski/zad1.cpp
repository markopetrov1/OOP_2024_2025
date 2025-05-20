//
// Created by Marko on 17.5.25.
//
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


class NoProductFoundException{
private:
    string category;
public:
    NoProductFoundException(string category){
        this->category = category;
    }

    void showMessage(){
        cout<<"No products from category "<<category<<" were found in the store"<<endl;
    }
};

class Product{
private:
    string name;
    string category;
    int price;
    int quantity;
public:
    Product(){
    }

    Product(string name, int price, int quantity){
        this->name = name;
        this->category = category;
        this->price = price;
        this->quantity = quantity;
    }

    Product(const Product &other){
        this->name = other.name;
        this->category = other.category;
        this->price = other.price;
        this->quantity = other.quantity;
    }

    ~Product(){}


    int totalPrice(){
        return price * quantity;
    }

    friend ostream &operator<<(ostream &out, Product &p){
        out<<p.name<<" ("<<p.category<<") "<<p.quantity<<" x "<<p.price<<" = "<<p.totalPrice()<<endl;
        return out;
    }

    friend istream &operator>>(istream &in, Product &p){
        getline(in, p.name);
        in>>p.category;
        in>>p.price;
        in>>p.quantity;
        in.ignore();
        return in;
    }

    string getCategory(){
        return category;
    }
};

class Store{
private:
    Product *products;
    int numProducts;
public:
    Store(){
        products = new Product[0];
        numProducts = 0;
    }

    Store(Product *products, int numProducts){
        this->numProducts = numProducts;
        this->products = new Product[numProducts];
        for(int i=0;i<numProducts;i++){
            this->products[i] = products[i];
        }
    }

    Store(const Store &other){
        this->numProducts = other.numProducts;
        this->products = new Product[numProducts];
        for(int i=0;i<numProducts;i++){
            this->products[i] = other.products[i];
        }
    }

    ~Store(){
        delete [] products;
    }

    Store operator=(Store &other){
        if(this != &other){
            delete [] products;
            this->numProducts = other.numProducts;
            this->products = new Product[numProducts];
            for(int i=0;i<numProducts;i++){
                this->products[i] = other.products[i];
            }
        }
        return *this;
    }

    Store &operator+=(Product &p){
        Product *temp = new Product[numProducts+1];
        for(int i=0;i<numProducts;i++){
            temp[i] = products[i];
        }
        temp[numProducts++] = p;

        delete [] products;

        products = temp;

        return *this;
    }

    friend ostream &operator<<(ostream &out, Store &s){
        for(int i=0;i<s.numProducts;i++)
            out<<s.products[i];

        return out;
    }

    Store fromCategory (string & category){
        Store s;

        for(int i=0;i<numProducts;i++){
            if(products[i].getCategory() == category){
                s += products[i];
            }
        }

        if(s.numProducts == 0){
            throw NoProductFoundException(category);
        }

        return s;
    }






};


void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {

    wtf();


    Store s;


    ifstream fin("input.txt");
    ofstream fout1("output1.txt");
    ofstream fout2("output2.txt");

    Product p;
    while(fin>>p){
        s += p;
    }

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT

    string category;
    cin >> category;

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    fout1<<s;

    try{
        Store newStore = s.fromCategory(category);
        fout2<<newStore;
    }
    catch (NoProductFoundException e){
        e.showMessage();
    }

    //DO NOT MODIFY THE CODE BELLOW

    cout << "All products:" << endl;
    rff("output1.txt");
    cout << "Products from category " << category << ": " << endl;
    rff("output2.txt");

    return 0;
}