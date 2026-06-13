#include<bits/stdc++.h>
using namespace std;
// symbol table used to do maping a variable with address.
// size of pointer is always 4 ;
int main(){
    int num = 5;
    cout<<num<<endl;
    // Address of operator - '&'.
    cout<<"Address of num is - "<<&num<<endl; //This is an Hexadecimal form.

    // Pointer is used to store the address of a variable.
    int *ptr = &num;
    // *ptr ko hamesha ek value assign karna define karte he yadi nahi hoo to null character assign kr dena.
    cout<<"Value is "<<*ptr<<endl;
    // (*) is a dereference operator.
    // *ptr means value at ptr address.
    cout<<endl;

    double d = 8.55;
    double *pt = &d;
    cout<<"Value is "<<*pt<<endl;
    cout<<"Address is "<<pt<<endl;
    cout<<endl;
    
    cout<<"Size of integer is "<<sizeof(num)<<endl;
    cout<<"Size of integer is "<<sizeof(ptr)<<endl; //It is system dependent but in majority cases it will 8 or in my laptop it is 4.
    cout<<"Size of integer is "<<sizeof(d)<<endl;
    cout<<"Size of integer is "<<sizeof(pt)<<endl;
    cout<<endl;

    char ch = 'a';
    char *p = &ch;
    cout<<"Value is "<<*p<<endl;
    cout<<"Size of integer is "<<sizeof(*p)<<endl;
    cout<<"Size of integer is "<<sizeof(p)<<endl;
    cout<<endl;
}