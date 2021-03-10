//Ham xu ly xau
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s1[] = "sueemsueemsueemilysue", s2[] = "sue", temp[] = "";
    int count = 0, size1 = sizeof(s1)-1, size2 = sizeof(s2)-1;
    cout << size1 << ", " << size2 << endl;
    for (int i = 0; i < size1; i++){
        if (s1[i] == s2[0]){
            int k = 0;
            for (int j = i; j < i+size2; j++){
                temp[k] = s1[j];
                k++;
            }
            cout << temp << endl;
            if (strcmp(temp, s2) == 0){
                cout << "temp:" << endl;
                for (int l = 0; l < sizeof(temp); l++) cout << temp[l];
                cout << endl;
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}