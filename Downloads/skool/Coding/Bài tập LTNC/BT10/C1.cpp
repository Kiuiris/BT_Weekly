#include <iostream>
using namespace std;

int len(const char* s){
    int count = 0;
    while (s[count] != '\0'){
        count++;
    }
    return count;
}

struct String{
    //a
    int n;
    char* str;
    String(int _n){
        int n = _n;
        str = new char[n];
    }
    //b
    String(const char* s){
        int l = len(s);
        str = new char[l];
        for (int i = 0; i < l; i++){
            str[i] = s[i];
        }
    }
    //c
    ~String(){
        delete[] str;
    }
    //d
    void print(){
        int i = 0;
        while (str[i] != '\0'){
            cout << str[i];
            i++;
        }
        cout << endl;
    }
    //e
    void append(const char* s){
        int ls = len(s);
        int lstr = len(str);
        char* temp = new char[ls + lstr];
        for (int i = 0; i < len(str); i++){
            temp[i] = str[i];
        }
        for (int i = lstr; i < ls+lstr; i++){
            temp[i] = s[i - lstr];
        }
        str = temp;
    }
};

int main() {
    
    String s1("Hello");
    s1.print();
    
    String greet("Hi");
    greet.append(", Eve");
    greet.print();
    
    return 0;
}