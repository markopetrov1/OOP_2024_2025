#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Triangle{
private:
    int a, b, c;
public:
    Triangle(int _a = 3, int _b = 5, int _c = 8){
        a = _a;
        b = _b;
        c = _c;
    }

    int perimeter(){
        return a+b+c;
    }

    float area(){
        float s = (a+b+c)/2;
        return sqrt(s* (s-a) *(s-b)* (s-c) );
    }
};

int main (){
    int a, b, c;
    cin>>a>>b>>c;

    Triangle t(a, b, c);

    cout<<"Perimetar: "<<t.perimeter()<<endl;
    cout<<"Plostina: "<<t.area()<<endl;

    return 0;
}