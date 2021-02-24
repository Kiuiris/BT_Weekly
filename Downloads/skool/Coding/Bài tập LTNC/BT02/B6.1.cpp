#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++){
        k = i + 1;
        for (int j = 0; j < n; j++){
            a[i][j] = k++;
            if (k == n + 1) k = 1;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}