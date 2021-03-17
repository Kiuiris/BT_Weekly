#include <iostream>
using namespace std;

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    char a = '1', b = '2';
    swap(a, b);
    cout << a << ", " << b << endl;
    return 0;
}