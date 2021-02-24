#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (i != j && str[i] == str[j]){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}