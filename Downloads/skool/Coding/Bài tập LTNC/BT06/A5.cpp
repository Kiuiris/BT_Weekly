//de quy tinh toan qua nhieu
#include <iostream>
using namespace std;

long F(int n) { 
   if (n == 0) return 0; 
   if (n == 1) return 1; 
   return F(n-1) + F(n-2); 
}

int main(){
    int n;
    cin >> n;
    cout << F(n) << endl;

    int a, a1 = 1, a2 = 1;
    if (n == 1) cout << a1 << endl;
    if (n == 2) cout << a2 << endl;
    for (int i = 3; i <= n; i++){
        a = a1 + a2;
        a1 = a2;
        a2 = a;
    }
    cout << a << endl;
    
    return 0;
}