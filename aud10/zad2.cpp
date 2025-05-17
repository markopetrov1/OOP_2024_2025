//
// Created by Marko on 12.5.25.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctype.h>
using namespace std;

int main(){
//    1.ifstream 2. ofstream
    ifstream fileInput("/Users/Marko/CLionProjects/OOP-2024-25/aud10/primer.txt");

    if(!fileInput.is_open()){
        return -1;
    }

    char c;

    int counterRow = 0; // broj na samoglaski vo daden red
    int totalCounter = 0; // vkupno samoglaski
    int totalRows = 0; // vkupno redovi so 10+ samoglaski

    while(fileInput.get(c)){
       c = tolower(c);

       if(c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u'){
           counterRow++;
           totalCounter++;
       }

       if(c == '\n'){
           if(counterRow >= 10){
               totalRows++;
           }
           counterRow = 0;
       }
    }

    cout<<"Vkupno "<<totalRows<<" reda imaat povekje od 10 samoglaski."<<endl;
    cout<<"Vo datotekata ima vkupno "<<totalCounter<<" samoglaski"<<endl;

    return 0;
}

