#include <iostream>
using namespace std;

/*string reverse (string ps){
	string t;
	for (int i = ps.size(); i >= 0; i--)
}*/

int main(){
	int n;
	cin >> n;
	string pass[n];
	for (int i = 0; i < n; i++){
		cin >> pass[i];
	}

	string t;
	for (int i = 0; i < n; i++){
        t = "";
		for (int j = pass[i].size() - 1; j >= 0; j--){
			t += pass[i][j];
		}
        for (int j = 0; j < n; j++){
            if (t == pass[j]) {
                cout << t.size() << ' ';
                int mid = (t.size()-1)/2;
                cout << pass[i][mid];
                return 0;
            }
        }
	}

	return 0;
}