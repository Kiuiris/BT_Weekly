#include <iostream>
using namespace std;

int main(){
    string f, f0 = "a", f1 = "b";
    f = "";
    cout << "Tu Fibonacci thu 0 la: " << f0 << endl;
    cout << "Tu Fibonacci thu 1 la: " << f1 << endl;
    for (int i = 2; i <= 10; i++){
        f = f1 + f0;
        f0 = f1;
        f1 = f;
        cout << "Tu Fibonacci thu " << i << " la: " << f << endl;
    }
    return 0;
}