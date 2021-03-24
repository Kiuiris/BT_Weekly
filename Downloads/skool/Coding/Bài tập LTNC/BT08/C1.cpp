#include <iostream>
using namespace std;

int str_len(char a[]);
void swap(char &a, char &b);
void erase(char a[], int pos);
void reverse (char a[]);
void delete_char(char a[], char c);
void pad_right(char a[], int n);
void pad_left(char a[], int n);
void truncate(char a[], int n);
bool is_palindrome(char a[]);
void trim_left(char a[]);
void trim_right(char a[]);


int main(){
    char s[] = "emily dickinson";
    char s1[] = "sue";
    char s2[] = "  eve  ";

    //Dao xau
    reverse(s);
    cout << "Reversed: " << s << endl;

    //Xoa ki tu
    delete_char(s, 'i');
    cout << "'i' deleted: " << s << endl; 

    //Don phai
    pad_right(s1, 5);
    cout << "Padded right: " << '_' << s1 << '_' << endl;

    //Don trai
    pad_left(s1, 7);
    cout << "Padded left: " << '_' << s1 << '_' << endl;

    //Cat xau
    truncate(s, 5);
    cout << "Truncated: " << '_' << s << '_' << endl;

    //Xau doi guong
    cout << "Is " << s << " palindrome? ";
    if (is_palindrome(s)) cout << "yes" << endl;
    else cout << "no" << endl;
    cout << "Is " << s2 << " palindrome? ";
    if (is_palindrome(s2)) cout << "yes" << endl;
    else cout << "no" << endl;

    //Loc trai
    trim_left(s2);
    cout << "Trimmed left: " << '_' << s2 << '_' << endl;

    //Loc phai
    trim_right(s2);
    cout << "Trimmed right: " << '_' << s2 << '_' << endl;

    return 0;
}

int str_len(char a[]){
    int count = 0;
    while (*(a+count) != '\0'){
        count++;
    }
    return count;
}

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

void erase(char a[], int pos){
    for (int i = pos; i < str_len(a)-1; i++){
        a[i] = a[i+1];
    }
    a[str_len(a) - 1] = '\0';
}

void reverse (char a[]){
    int begin = 0, last = str_len(a) - 1;
    while (begin < last){
        swap(a[begin], a[last]);
        begin++;
        last--;
    }
}

void delete_char(char a[], char c){
    for (int i = 0; i < str_len(a); i++){
        if (a[i] == c){
            erase(a, i);
        }
    }
}

void pad_right(char a[], int n){
    if (str_len(a) < n){
        for (int i = str_len(a); i < n; i++){
            a[i] = ' ';
        }
    }
}

void pad_left(char a[], int n){
    int i = str_len(a) - 1;
    int j = n - 1;
    do{
        a[j] = a[i];
        i--;
        j--;
    }
    while (i >= 0);
    for (int k = 0; k <= j; k++){
        a[k] = ' ';
    }
}

void truncate(char a[], int n){
    int len = str_len(a);
    if (len > n){
        for (int i = len - 1; i >= len; i--){
            a[i] = '\0';
        }
    }
}

bool is_palindrome(char a[]){
    int begin = 0, last = str_len(a) - 1;
    while (begin < last){
        if (a[begin] != a[last]){
            return false;
        }
        begin++;
        last--;
    }
    return true;
}

void trim_left(char a[]){
    while (a[0] == ' '){
        erase(a, 0);
    }
}

void trim_right(char a[]){
    int i = str_len(a);
    for (int i = str_len(a) - 1; a[i] == ' '; i--){
        a[i] = '\0';
    }
}
