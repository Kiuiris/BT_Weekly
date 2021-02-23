#include <iostream>
using namespace std;

int main(){
    int n;
    for ( ; ; ){
        cin >> n;
        /*dung khi n = -1
        if (n == -1){
            break;
        }
        */
        (n >= 0 && n % 5 == 0) ? cout << (n/5) : cout << "-1";
        cout << endl;
    }
    cout << "Bye" << endl;
    return 0;
}