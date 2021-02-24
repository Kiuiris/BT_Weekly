#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    cout << num << ' ';
    while (num > 0){
        int t = num;
        cin >> num;
        if (num != t) cout << num << ' ';
    }
    return 0;
}