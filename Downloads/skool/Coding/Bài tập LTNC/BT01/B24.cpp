#include <iostream>
using namespace std;

int main(){
    int d, m, y, n;
    char ch;
    cout << "Enter the date (dd/mm/yyyy): \n";
    cin >> d >> ch >> m >> ch >> y;
    
    const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3) y -= 1;
    n = (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    
    switch(n){
        case 0:
            cout << "Sunday\n";
            break;
        case 1:
            cout << "Monday\n";
            break;
        case 2:
            cout << "Tuesday\n";
            break;
        case 3:
            cout << "Wednesday\n";
            break;
        case 4:
            cout << "Thursday\n";
            break;
        case 5:
            cout << "Friday\n";
            break;
        default:
            cout << "Saturday\n";
    }
    return 0;
}