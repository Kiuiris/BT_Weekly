#include <iostream>
using namespace std;

int main(){
    int i = 1, h = 12;
    while (i < 24){
        if (h == 12 && i == 1){
            cout << h << " midnight" << endl;
            h = 1;
        }
        if (h == 12 && i == 12){
            cout << h << " noon";
            h = 1;
        }
        if (i < 12){
            cout << h << " am";
            h++;
        }
        if (i > 12){
            cout << h << " pm";
            h++;
        }
        cout << endl;
        i++;
    }
    return 0;
}