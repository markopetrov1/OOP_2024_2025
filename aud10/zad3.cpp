#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main(){

    ifstream fin("/Users/Marko/CLionProjects/OOP-2024-25/aud10/vlezna.txt");
    ofstream fout("/Users/Marko/CLionProjects/OOP-2024-25/aud10/izlezna.txt");

    if(!fin.is_open()){
        cout<<"Failed to open input stream"<<endl;
        return -1;
    }

    if(!fout.is_open()){
        cout<<"Failed to open output stream"<<endl;
        return -1;
    }

    string line;

    while(getline(fin,line)){
        fout<<line.length()<<endl;
        fout<<line<<endl;
    }

    return 0;
}
