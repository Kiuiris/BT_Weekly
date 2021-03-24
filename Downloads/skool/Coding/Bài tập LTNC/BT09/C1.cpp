#include <iostream>
using namespace std;

int str_len(const char a[]);
char* reverse (const char a[]);
char* delete_char(const char a[], const char c);
char* pad_right(const char a[], const int n);
char* pad_left(const char a[], const int n);
char* truncate(const char a[], const int n);
char* trim_left(const char a[]);
char* trim_right(const char a[]);


int main(){
    char s[] = "emily dickinson";
    char s1[] = "sue";
    char s2[] = "  eve  ";

    //Dao xau
    cout << "Reversed: " << reverse(s) << endl;

    //Xoa ki tu
    cout << "'i' deleted: " << delete_char(s, 'i') << endl;
    
    //Don phai
    cout << "Padded right: " << '_' << pad_right(s1, 5) << '_' << endl;

    //Don trai
    cout << "Padded left: " << '_' << pad_left(s1, 5) << '_' << endl;

    //Cat xau
    cout << "Truncated: " << '_' << truncate(s, 5) << '_' << endl;

    //Loc trai
    cout << "Trimmed left: " << '_' << trim_left(s2) << '_' << endl;
    
    //Loc phai
    cout << "Trimmed right: " << '_' << trim_right(s2) << '_' << endl;
    return 0;
}

int str_len(const char a[]){
    int count = 0;
    while (*(a+count) != '\0'){
        count++;
    }
    return count;
}

char* reverse (const char a[]){
    int len = str_len(a);
    char* s = new char[len];
    for (int i = 0; i < len; i++){
        s[i] = a[len-i-1];
    }
    return s;
}

char* delete_char(const char a[], const char c){
    int len = str_len(a);
    char* s = new char[len];
    int j = 0;
    for (int i = 0; i < len; i++){
        if (a[i] != c){
            s[j] = a[i];
            j++;
        }
    }
    return s;
}

char* pad_right(const char a[], const int n){
    int len = str_len(a);
    char* s = new char[len];
    for (int i = 0; i < len; i++){
        s[i] = a[i];
    }
    for (int i = len; i < n; i++){
        s[i] = ' ';
    }
    return s;
}

char* pad_left(const char a[], const int n){
    int len = str_len(a);
    int d = n - len;
    char* s = new char[len];
    for (int i = 0; i < d; i++){
        s[i] = ' ';
    }
    for (int i = 0; i < len; i++){
        s[d+i] = a[i];
    }
    return s;
}

char* truncate(const char a[], const int n){
    int size;
    if (str_len(a) <= n) size = str_len(a);
    else size = n;
    char* s = new char[size];
    for (int i = 0; i < size; i++){
        s[i] = a[i];
    }
    return s;
}

char* trim_left(const char a[]){
    int pos, j = 0;
    for (pos = 0; pos < str_len(a); pos++){
        if (a[pos] != ' ') break;
    }
    char* s = new char;
    for (int i = pos; i < str_len(a); i++){
        s[j] = a[i];
        j++;
    }
    return s;
}

char* trim_right(const char a[]){
    char* s = new char;
    int pos;
    for (pos = str_len(a) - 1; pos >= 0; pos--){
        if (a[pos] != ' ') break;
    }
    for (int i = 0; i <= pos; i++){
        s[i] = a[i];
    }
    return s;
}