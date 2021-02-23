#include <iostream>
using namespace std;

int main(){
    double w, h;
    cout << "Enter your weight (in kg): ";
    cin >> w;
    cout << "Enter your height (in meter): ";
    cin >> h;
    
    double bmi = w/(h*h);
    
    cout << bmi << endl;
    
    return 0;
}