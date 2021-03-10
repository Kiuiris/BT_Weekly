//Mang truyen vao ham dang con tro
#include <iostream>
using namespace std;

int func(int a[]){
    return sizeof(a);
}

int main(){
    int arr[10];
    int *a;
    cout << "Size of array in main: " << sizeof(arr) << endl;
    cout << "Size of array in func: " << func(arr) << endl;
    cout << "Size of pointer a: " << sizeof(a) << endl;

    return 0;
}
/*
Output:
Size of array in main: 40
Size of array in func: 8
Size of pointer a: 8
*/