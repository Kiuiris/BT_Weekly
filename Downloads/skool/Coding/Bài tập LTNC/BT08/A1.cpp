#include <iostream>
using namespace std;

void f(int xval){
    int x;
    x = xval;
    // in địa chỉ của x tại đây
    cout << &x << endl;
}
void g(int yval){
    int y;
    // in địa chỉ của y tại đây
    cout << &y << endl;
}

int main(){
    f(7);
    g(11);
    return 0;
}

/*
output:
0x7ffee8abe8e8
0x7ffee8abe8e8
nhan xet:
dia chi cua bien x va y la giong nhau.
khi ham main goi ham f va ham f chay xong thi stack frame cua f bi xoa di
sau do ham main goi ham g. luc nay vi tri stack frame cua ham g trung voi vi tri stack frame cua ham f
va hai bien x va y deu la hai bien dia phuong dau tien cua hai ham
nen hai bien duoc luu cung mot dia chi (nhung khong cung mot luc)
*/
