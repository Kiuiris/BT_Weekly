#include <iostream>

using namespace std;

const int size = 10;

struct BigNum{
    int* num = new int[10];
};

int main(){
    int *p = new int;
    BigNum n;
    cout << "n.num: " << n.num << endl;

    p = n.num;
    cout << "p: " << p << endl;

    delete p;
    return 0;
}
/*
Dia chi ma p va n.num tro toi la giong nhau
*/
