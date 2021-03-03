//Dia chi cac bien
#include <iostream>
using namespace std;

int main(){
    int t1;
    char t2;
    int a[10];
    char b[10];
    char t3;
    int t4;

    cout << "Dia chi 3 phan tu lien tiep cua a:" << endl;
    for (int i = 0; i < 3; i++){
        cout << (void *)&a[i] << endl;
    }

    cout << "Dia chi 3 phan tu lien tiep cua b:" << endl;
    for (int i = 0; i < 3; i++){
        cout << (void *)&b[i] << endl;
    }
    /*Cac dia chi cua cac phan tu trong mang a cach nhau 4 bit, mang b cach nhau 1 bit*/

    cout << "Dia chi cua t1: " << &t1 << endl;
    cout << "Dia chi cua t2: " << (void *)&t2 << endl;
    cout << "Dia chi cua t3: " << (void *)&t3 << endl;
    cout << "Dia chi cua t4: " << &t4 << endl;

    /*Cac bien t1, t2, t3, t4 dung lien nhau, cach nhau dung bang so bit cua bien*/

    return 0;
}