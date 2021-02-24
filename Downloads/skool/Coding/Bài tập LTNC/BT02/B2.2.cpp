#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x, y, p;
    cin >> x >> y;
    p = x;
    for (int i = 1; i < y; i++){
        p *= x;
    }
    cout << "The product is: " << p << endl;
    cout << "Check with pow(): " << pow(x, y) << endl;
    
    return 0;
}