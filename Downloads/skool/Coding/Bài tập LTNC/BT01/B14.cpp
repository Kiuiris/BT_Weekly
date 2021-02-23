#include <iostream>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    
    int a, b;
    a = rand() % 100;
    b = rand() % 100;
    
    cout << a << ' ' << b << endl;
    
    int chose = a;
    if (chose < 50) chose = b;
    
    bool win = (chose > a || chose > b);
    
    if (win) cout << "Congrats Bob, you won!" << endl;
    else cout << "Better luck next time!" << endl;
    return 0;
}