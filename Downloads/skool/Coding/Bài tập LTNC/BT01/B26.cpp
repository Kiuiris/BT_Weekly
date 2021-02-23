#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    double sum;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    
    cout << "Mean: " << sum/n << endl;
    cout << "Max: " << a[n-1] << endl;
    cout << "Min: " << a[0] << endl;
    
    return 0;
}