#include <iostream>
using namespace std;

int main(){
    int* p = new int;
    int* p2 = p;
    *p = 10;
    delete p;
    cout << *p2 << endl;
    *p2 = 100;
    cout << *p2 << endl;
    delete p2;//dong lenh gay loi
}
/*
lenh delete p giai phong p qua som khien phan sau cua chuong trinh khong chay duoc vi p2 tro toi mot vung bo nho khong xac dinh
*/