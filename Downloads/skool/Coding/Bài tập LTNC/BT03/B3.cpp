#include <iostream>
using namespace std;

bool check_palin(const int& a){
    int d, s =0, t = a;
    while (t > 0){
        d = t%10;
        s = s*10 + d;
        t /= 10;
    }
    if (s == a) return true;
    else return false;
}

int main(){
	int test, num;
	cin >> test;
	int a[test][2];

	for (int i = 0; i < test; i++){
		for (int j = 0; j < 2; j++){
			cin >> a[i][j];
		}
    }

    for (int i = 0; i < test; i++){
        num = 0;
        for (int j = a[i][0]; j <= a[i][1]; j++){
            if (check_palin(j)) {
                num++;
                cout << j << ' ';
            }
        }
        cout << num << endl;
    }

	return 0;
}