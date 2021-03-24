#include <iostream>

using namespace std;

int main(){
    int num = 15;
    int* pnum = &num;

    delete pnum;
    return 0;
}
/*
Lenh delete chi danh cho NULL pointer va con tro su dung cap phat dong
Bien pnum chi la con tro tro toi vung nho cua bien dia phuong num
nen khong the dung lenh delete voi bien pnum
*/
