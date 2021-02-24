#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int siz = s.size(), begin = 0, last = siz - 1;

    while (begin != last && last >= 0) {
        if (s[begin] != s[last]){
            cout << "No\n";
            return 0;
        }
        begin++;
        last--;
    }
    cout << "Yes\n";
    return 0;
}