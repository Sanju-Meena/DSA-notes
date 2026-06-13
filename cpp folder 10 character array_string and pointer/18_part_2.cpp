#include<iostream>
using namespace std;

void increment(int **p){
    ++(**p);
}
int main(){
    // Question 1.
    int f = 100;
    int *p = &f;
    int **q = &p;
    int s = ++(**q);
    int *r = *q;
    ++(*r);
    cout<<f<<" "<<s<<endl;
   
    // Question 2.
    int num = 110;
    int *ptr = &num;
    increment(&ptr);
    cout<<num<<endl;
}