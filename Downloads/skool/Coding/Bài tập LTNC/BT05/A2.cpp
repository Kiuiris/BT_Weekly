//Function call stack
#include <iostream>
using namespace std;

long factorial(int x){
    if (x == 1){
        cout << "x = " << x << " at " << &x << endl;
        return 1;
    }
    else {
        cout << "x = " << x << " at " << &x << endl;
        return x*factorial(x-1);
    }
}

int main(){
    int n = 8;
    cout << factorial(n) << endl;
    return 0;
}
/*Tra loi vao day*/