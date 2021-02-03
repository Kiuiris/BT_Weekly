/**Bài tập về nhà số 1 - Kỳ 2 - Tuần 1 (18 - 25/1//21)
 Lập trình nâng cao INT2215 22*/
#include <iostream>
using namespace std;

//Dạng B
//13
#include <cmath>

int main(){
    int x, y;
    cin >> x >> y;
    double dis = sqrt(x*x + y*y);
    cout << dis << endl;
    return 0;
}

//14
int main(){
    srand(time(0));
    
    int a, b;
    a = rand() % 100;
    b = rand() % 100;
    
    cout << a << ' ' << b << endl;
    
    int chose = a;
    if (chose < 50) chose = b;
    
    bool win = (chose > a || chose > b);
    
    if (win) cout << "Congrats Bob, you won!" << endl;
    else cout << "Better luck next time!" << endl;
    return 0;
}

//15
int main(){
    string f, f0 = "a", f1 = "b";
    f = "";
    cout << "Tu Fibonacci thu 0 la: " << f0 << endl;
    cout << "Tu Fibonacci thu 1 la: " << f1 << endl;
    for (int i = 2; i <= 10; i++){
        f = f1 + f0;
        f0 = f1;
        f1 = f;
        cout << "Tu Fibonacci thu " << i << " la: " << f << endl;
    }
    return 0;
}

//16
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a == b && b == c) ? "true" : "false");
    cout << endl;
    return 0;
}

//17
int main(){
    int year;
    cin >> year;
    
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

//18
#include <cmath>

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    cout << dis << endl;
    return 0;
}

//19
int main(){
    int x, y, z;
    cin >> x >> y >> z;
    bool b;
    if (x < y < z || x > y > z) b = true;
    else b = false;
    cout << b << endl;
    return 0;
}

//20
int main(){
    int a, b;
    cin >> a >> b;
    
    if (a % 7 == 0 && b % 7 == 0) cout << "true\n";
    else cout << "false\n";
    
    return 0;
}

//21
#include <cmath>

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    double p, area;
    p = (a + b + c)/2;
    area = sqrt(p*(p-a)*(p-b)*(p-c));
    
    cout << area << endl;
    
    return 0;
}

//22
int main(){
    double w, h;
    cin >> w >> h;
    
    double bmi = w/(h*h);
    
    cout << bmi << endl;
    
    return 0;
}

//23
int main(){
    int a, b;
    cin >> a >> b;
    cout << max(a, b) << endl;
    return 0;
}

//24
int main(){
    int d, m, y, n;
    char ch;
    cout << "Enter the date (dd/mm/yyyy): \n";
    cin >> d >> ch >> m >> ch >> y;
    
    const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3) y -= 1;
    n = (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    
    switch(n){
        case 0:
            cout << "Sunday\n";
            break;
        case 1:
            cout << "Monday\n";
            break;
        case 2:
            cout << "Tuesday\n";
            break;
        case 3:
            cout << "Wednesday\n";
            break;
        case 4:
            cout << "Thursday\n";
            break;
        case 5:
            cout << "Friday\n";
            break;
        default:
            cout << "Saturday\n";
    }
    return 0;
}


//25
int main(){
    int a[5];
    for (int i = 0; i < 5; i++){
        cin >> a[i];
    }
    for (int i = 0; i<5; i++)
        for (int j = i+1; j < 5; j++)
            if (a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    cout << a[2] << endl;
    return 0;
}

//Dạng C
//26
int main(){
    int n;
    cin >> n;
    int a[n];
    double sum;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    
    cout << "Mean: " << sum/n << endl;
    cout << "Max: " << a[n-1] << endl;
    cout << "Min: " << a[0] << endl;
    
    return 0;
}

//27
int main(){
    int n;
    for ( ; ; ){
        cin >> n;
        /*dung khi n = -1
        if (n == -1){
            break;
        }
        */
        (n >= 0 && n % 5 == 0) ? cout << (n/5) : cout << "-1";
        cout << endl;
    }
    cout << "Bye" << endl;
    return 0;
}

//28
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

//29
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
//30
int main(){
    int n;
    cin >> n;
    for (int i = n; i > 0; i--){
        for (int j = i; j > 0; j--)
            cout << '*';
        cout << endl;
    }
    return 0;
}
