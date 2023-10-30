#include<iostream>
using namespace std;

void change(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 5;
    int b = 10;
    int* c = &a;
    int* d = &b;
    
    change(c, d);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    
    return 0;
}

