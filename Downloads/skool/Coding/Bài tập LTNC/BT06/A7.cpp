//duyet hoan vi

#include <iostream>
using namespace std;

string permutation(string s, int lo, int hi){
    if (lo == hi){
        return s;
    }
    for (int i = lo; i <= hi; i++){
        swap(s[lo], s[i]);
        return permutation(s,lo+1, hi);
        swap(s[lo], s[i]);
    }
    return s;
}

int main (){
    string a = "abcd";
    cout << permutation(a, 0, 3);
    return 0;
}