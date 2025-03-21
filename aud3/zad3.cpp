#include <iostream>
#include <cstring>

using namespace std;

class Datum{
private:
    int den;
    int mesec;
    int godina;
public:
    Datum(int _den=5, int _mesec=12, int _godina=1997){
        den = _den;
        mesec = _mesec;
        godina = _godina;
    }

    ~Datum(){}

    int getDen(){
        return den;
    }

    int getMesec()
    {
        return mesec;
    }

    int getGodina(){
        return godina;
    }

    void print()
    {
        cout<<den<<"."<<mesec<<"."<<godina;
    }
};

class Vraboten{
private:
    char ime[50];
    int plata;
    Datum datum;
public:
    Vraboten(){}

    Vraboten(char * _ime, int _plata, Datum _datum){
        strcpy(ime, _ime);
        plata = _plata;
        datum = _datum;
    }

    ~Vraboten(){}

    void print(){
        cout<<"Vraboten: "<<ime<<", plata: "<<plata<<", datum na ragjanje: ";
        datum.print();
        cout<<endl;
    }

    char * getIme(){
        return ime;
    }

    int getPlata(){
        return plata;
    }

    Datum getDatum(){
        return datum;
    }
};

Vraboten getNajplatenVraboten(Vraboten * vraboteni, int n){
    int idx = 0;
    int maxPlata = vraboteni[0].getPlata();

    for(int i=1;i<n;i++){
        if(vraboteni[i].getPlata() > maxPlata){
            maxPlata = vraboteni[i].getPlata();
            idx = i;
        }
    }

    return vraboteni[idx];
}

int sporediVraboteni(Vraboten v1, Vraboten v2){
    if(v1.getDatum().getGodina() > v2.getDatum().getGodina()){
        return 1;
    }
    else if(v1.getDatum().getGodina() < v2.getDatum().getGodina()){
        return 2;
    }
    else if(v1.getDatum().getMesec() > v2.getDatum().getMesec()){
        return 1;
    }
    else if(v1.getDatum().getMesec() < v2.getDatum().getMesec()){
        return 2;
    }
    else if(v1.getDatum().getDen() > v2.getDatum().getDen()){
        return 1;
    }
    else if(v1.getDatum().getDen() < v2.getDatum().getDen()){
        return 2;
    }
    else{
        return 0;
    }

}

Vraboten getNajmladVraboten(Vraboten * vraboteni, int n){
    Vraboten najmladVraboten = vraboteni[0];
    for(int i=1;i<n;i++){
        if(sporediVraboteni(vraboteni[i], najmladVraboten ) == 1){
            najmladVraboten = vraboteni[i];
        }
    }
    return najmladVraboten;
}

int main(){

    Datum d1(1, 1, 1980);
    Datum d2(1, 2, 1983);
    Datum d3(11, 12, 1984);

    Vraboten v[3];

    Vraboten v1("Marjan", 40000, d1);
    Vraboten v2("Stefan", 30000, d2);
    Vraboten v3("Marko", 20000, d3);

    v[0] = v1;
    v[1] = v2;
    v[2] = v3;

    Vraboten najmlad = getNajmladVraboten(v, 3);
    Vraboten najplaten = getNajplatenVraboten(v, 3);

    cout << "Najmlad vraboten: " << endl;
    najmlad.print();

    cout << "Vraboten so najgolema plata: " << endl;
    najplaten.print();

    return 0;
}