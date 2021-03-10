//duyet to hop

#include <iostream>
using namespace std;

bool check_prime(int a){
    for (int i = 2; i <= sqrt(a); i++){
        if (a % i == 0) return false;
    }
    return true;
}
int main(){
    cout << check_prime(62501);
    return 0;
}