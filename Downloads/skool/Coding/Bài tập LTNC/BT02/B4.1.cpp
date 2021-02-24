#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for (int i = n; i > 0; i--){
        cout << setw(((2*n-1)-(2*i-1))/2+1);
        for (int j = 2*i-1; j > 0; j--){
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}