#include <iostream>
using namespace std;

int main( ){
    /*
    //tinh kich thuoc bien char
    char a[4] = "abc"; 
    for (char *cp = a; (*cp) != '\0'; cp++){
        cout << (void*) cp << " : " << (*cp) << endl;
    }
    //tinh kich thuoc bien int
    int n[4] = {1, 2, 3, 0};
    for (int *ip = n; (*ip) != 0; ip++){
        cout << (void*) ip << " : " << (*ip) << endl;
    }*/
    //tinh kich thuoc bien double
    double num[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 0};
    for (double *dp = num; (*dp) != 0; dp++){
        cout << (void*) dp << " : " << (*dp) << endl;
    }

    return 0;
}
/*
Neu dung cp+=2 thay vi cp++ thi ham se in ra cac dia chi cach nhau 16 bit tuon duong voi 2 o nho cua kieu double.
*/
