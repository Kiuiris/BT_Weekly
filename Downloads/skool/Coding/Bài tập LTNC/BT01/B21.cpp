#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    double p, area;
    p = (a + b + c)/2;
    area = sqrt(p*(p-a)*(p-b)*(p-c));
    
    cout << area << endl;
    
    return 0;
}