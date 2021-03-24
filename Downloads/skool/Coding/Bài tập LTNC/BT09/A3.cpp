#include <iostream>
using namespace std;

int main(){
    char* a = new char[10];
    char* c = a + 3;
    for (int i = 0; i < 9; i++) a[i] = 'a'; 
    a[9] = '\0';
    cerr <<"a: " << "-" << a << "-" << endl;
    cerr <<"c: " << "-" << c << "-" << endl;
    delete c;
    cerr << "a after deleting c:" << "-" << a << "-" << endl;
}
/*
Lenh delete c khong chay nhu mong muon
Khong the su dung toan tu delete cho bien c vi c tro toi giua mot vung bo nho dong
*/