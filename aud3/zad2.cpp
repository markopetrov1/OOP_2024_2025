#include <iostream>
#include <cstring>
using namespace std;

class Ekipa{
private:
    char ime[50];
    int godina;
    char grad[50];
public:
    Ekipa(char* _ime="Real Madrid", int _godina=1880, char * _grad= "Madrid"){
        strcpy(ime, _ime);
        godina = _godina;
        strcpy(grad, _grad);
    }

    ~Ekipa(){}

    const char *getIme() const {
        return ime;
    }

    int getGodina() const {
        return godina;
    }

    void setGodina(int godina) {
        Ekipa::godina = godina;
    }

    const char *getGrad() const {
        return grad;
    }
};

class Natprevar{
private:
    Ekipa domakjin;
    int goloviDomakjin;
    Ekipa gostin;
    int goloviGostin;
public:
    Natprevar(){}

    Natprevar(const Ekipa &_domakjin, int _goloviDomakjin, const Ekipa &_gostin, int _goloviGostin){
        domakjin = _domakjin;
        goloviDomakjin = _goloviDomakjin;
        gostin = _gostin;
        goloviGostin = _goloviGostin;
    }

    ~Natprevar(){}

    Ekipa getDomakjin() const {
        return domakjin;
    }
    int getGoloviDomakjin() const{
        return goloviDomakjin;
    }
    Ekipa getGostin() const{
        return gostin;
    }

    int getGoloviGostin() const{
        return goloviGostin;
    }

};

bool revans(const Natprevar n1, const Natprevar n2){
    if(
            strcmp(n1.getDomakjin().getIme(), n2.getGostin().getIme()) == 0 &&
            strcmp(n1.getGostin().getIme(), n2.getDomakjin().getIme()) == 0
    )
        return true;
    return false;
}

Ekipa duel(const Natprevar& n1, const Natprevar n2){
    if(revans(n1, n2)){
        int zbirGoloviPrvaEkipa = n1.getGoloviDomakjin() + n2.getGoloviGostin();
        int zbirGoloviVtoraEkipa = n1.getGoloviGostin() + n2.getGoloviDomakjin();
        if(zbirGoloviPrvaEkipa > zbirGoloviVtoraEkipa){
            return n1.getDomakjin();
        }
        else if(zbirGoloviPrvaEkipa < zbirGoloviVtoraEkipa){
            return n1.getGostin();
        }
        else{
            cout<<"Nereseno"<<endl;
            Ekipa e1("nereseno", 2, "...");
            return e1;
        }
    }else{
        cout<<"Natprevarite ne se sovpagjaat"<<endl;
        Ekipa e2("nema",2, "...");
    }
}

int main(){
    Ekipa e1("Real Madrid", 1880,  "Madrid");
    Ekipa e2("FC Barcelona", 1880, "Barcelona");

     Natprevar n1(e1, 1, e2, 2);
     Natprevar n2(e2, 1, e1, 0);

    Ekipa rezultat = duel(n1, n2);

    if(strcmp(rezultat.getIme(), "nema") != 0 && strcmp(rezultat.getIme(), "nereseno") != 0){
        cout<<rezultat.getIme();
    }

    const int broj = 5;



    return 0;
}