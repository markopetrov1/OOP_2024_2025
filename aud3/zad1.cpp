#include <iostream>
#include <cstring>

using namespace std;

class Momche{
private:
    char ime[20];
    char prezime[20];
    int godini;
public:
    Momche(char * _ime = "Nikola", char * _prezime = "Nikolovski", int _godini=25){
        strcpy(ime, _ime);
        strcpy(prezime, _prezime);
        godini = _godini;
    }
    ~Momche(){}

    char * getIme(){
        return ime;
    }

    char * getPrezime(){
        return prezime;
    }

    int getGodini(){
        return godini;
    }

    void print(){
        cout<<"Momche: "<<ime<<" "<<prezime<<" "<<godini;
    }
};

class Devojche{
private:
    char ime[20];
    char prezime[20];
    int godini;
public:
    Devojche(char * _ime = "Nikolina", char * _prezime = "Nikolovska", int _godini=32){
        strcpy(ime, _ime);
        strcpy(prezime, _prezime);
        godini = _godini;
    }
    ~Devojche(){}

    char * getIme(){
        return ime;
    }

    char * getPrezime(){
        return prezime;
    }

    int getGodini(){
        return godini;
    }

    void print(){
        cout<<"Devojche: "<<ime<<" "<<prezime<<" "<<godini;
    }
};


class Sredba{
private:
    Momche momche;
    Devojche devojche;
public:
    Sredba(){}

    Sredba(const Momche& m,  Devojche &d){
        momche = m;
        devojche = d;
    }

    ~Sredba(){}

    void print(){
        cout<<"Sredba: ";
        momche.print();
        devojche.print();
        cout<<endl;
    }

    void daliSiOdgovaraat(){
        if(abs(momche.getGodini() - devojche.getGodini()) <= 5){
            cout<<"Si odgovaraat"<<endl;
        }
        else{
            cout<<"Ne si odgovoraat";
        }
    }

};

int main(){
    Momche m;
    Devojche d;

    Sredba s(m, d);

    s.print();
    s.daliSiOdgovaraat();

    return 0;
}