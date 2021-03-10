//Loi su dung con tro
#include <iostream>
using namespace std;

int* weird_sum(int a, int b){
    int c;
    c = a + b;
    return &c;
}

int main(int argc, const char* argv[] ){
    int* px;
    cout << "px: " << px << ", *px: " << *px << endl;//con tro chua khoi tao

    px = NULL;
    cout << "px: " << px << ", *px: " << *px << endl;//truy nhap con tro NULL

    cout << "Weird_sum(15, 3): " << weird_sum(15, 3) << endl;//dangling references

    //Loi giu con tro toi bien co pham vi nho hon pham vi cua con tro do
    int a = 10, b = 20, *pG;
    {
        int g;
        pG = &g;
        g = max(a, b);
    }
    {
        int temp = 100;
        cout << "temp is: " << temp << endl;
    }

    cout << "max(" << a << ", " << b << ") = " << *pG << endl; 
    return 0;
}