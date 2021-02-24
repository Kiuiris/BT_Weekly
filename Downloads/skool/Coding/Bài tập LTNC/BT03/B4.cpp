#include <iostream>
using namespace std;

int main(){
    int row, col, count;
    cin >> row >> col;
    char map[row][col];

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            count = 0;
            if (map[i][j] != '*'){
                for (int m = i-1; m <= i+1; m++){
                    if (m < 0) continue;
                    for (int n = j-1; n <= j+1; n++){
                        if (n < 0) continue;
                        if (map[m][n] == '*') count++;
                    }
                }
                map[i][j] = count + '0';
            }
        }
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}