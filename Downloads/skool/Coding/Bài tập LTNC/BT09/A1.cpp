#include <iostream>
using namespace std;

char* concat (const char* s1, const char* s2){
    char* sum = new char;
    int i = 0, k = 0;
    while (s1[i] != '\0'){
        *(sum+i) = *(s1+i);
        i++;
    }
    while (s2[k] != '\0'){
        *(sum+i) = *(s2+k);
        i++;
        k++;
    }
    return sum;
}

int main(){
    char s1[] = "Hello";
    char s2[] = "World";
    cout << concat(s1, s2) << endl;
    return 0;
}