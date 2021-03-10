//Dangling references
#include <iostream>
using namespace std;

char* weird_string() { 
   char c[] = "123345";
   return c; 
}

int main(){
    weird_string();
    return 0;
}
/*
output:
A5.cpp:7:11: warning: address of stack memory associated with local variable 'c'
    returned [-Wreturn-stack-address]
    return c; */
