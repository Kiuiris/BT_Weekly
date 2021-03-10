//mang la tham so cua ham
#include <iostream>
using namespace std;

void test(int a[]){
    cout << "Address of Array in func: " << &a << endl;
    cout << "Address of 1st in func:   " << (void *)&a[0] << endl;
}

int main(){
    int a[6] = {0, 4, 5, 1, 2, 3};
    cout << "Address of Array in main: " << &a << endl;
    cout << "Address of 1st in main:   " << (void *)&a[0] << endl;
    test(a);
    return 0;
}
/*
output:
Address of Array in main: 0x7ffedfe2e8d0
Address of 1st in main:   0x7ffedfe2e8d0
Address of Array in func: 0x7ffedfe2e898
Address of 1st in func:   0x7ffedfe2e8d0

nhan xet: 
trong ham main dia chi cua mang duoc tinh tu dia chi cua bien dau tien cua mang
*/