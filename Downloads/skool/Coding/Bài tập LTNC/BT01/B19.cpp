#include <iostream>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    bool b;
    if (x < y < z || x > y > z) b = true;
    else b = false;
    cout << b << endl;
    return 0;
}