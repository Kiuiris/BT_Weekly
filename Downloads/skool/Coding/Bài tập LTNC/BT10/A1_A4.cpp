#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point(){};
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
};
//A1
void print(Point P){
    cout << '(' << P.x << ", " << P.y << ')' << endl;
}

//A2
void by_ref(Point& P){
    cout << &P << endl;
}

void by_val(Point P){
    cout << &P << endl;
}

//A3
Point mid_point(const Point& M, const Point& N){
    Point mid;
    mid.x = (M.x+N.x)/2;
    mid.y = (M.y+N.y)/2;
    return mid;
}

int main() {
    Point Q(3, 4), D(1, 2);
    
    //A1
    print(Q);
    //A2
    cout << "Address of Q: " << &Q << endl;
    cout << "Address of Q in by_ref: ";
    by_ref(Q);
    cout << "Address of Q in by_val: ";
    by_val(Q);
    //A3
    print(mid_point(D, Q));
    //A4
    cout << "Address of Q: " << &Q << endl;
    cout << "Address of Q.x: " << &(Q.x) << endl;
    cout << "Address of Q.y: " << &(Q.y) << endl;
    /*
    Nhan xet:
    dia chi cua truong dau tien trong cau truc trung voi dia chi cua bien. cac bien sau se duoc xep vao cac o dia chi tiep theo tuong ung voi tung kieu bien
    */
    return 0;
}
