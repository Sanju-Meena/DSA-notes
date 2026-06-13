#include<iostream>
using namespace std;
/* #include<iostream> : means #include ek pre processor directive hai
   jo iostream ki library ko copy karega hamare source code mai compile hone se pahele; */

// Macro created
#define pi 3.14 
/* 1. Macro --> A piece of code in a program that is replaced by value of macro before compiling.
   2. It does not take any storage;
   3. It's value is fixed, it cannot be changeable;
   4. It is used without semicolon.
   5. Macro is a single line function type which assign value before compilation wherever it is used; */

#define area(l,b) l*b
#define v a
#define a 10
#define min(n,m) (((n>m) ? n:m))
// cout<<e<<endl; Ye work nahi karega error aayega.

// Global variable--> we cannot use this bcz we can use reference variable instead of global variable.
int num = 5;  // It is bad practise bcz any function can update the value of global variable.
void update(){
    num++;
    cout<<"num in update is "<<num<<endl;   
}

int main(){
    cout<<pi<<endl;
    // pi++; it cannot valid error aayega.
    int r = 5 ;
    double area = pi*r*r;
    cout <<"Area is : "<<area<<endl;
    int b = 5,h = 7;
    cout<<"Area of rectangle is "<<area(b,h)<<endl;
    cout<<v<<" "<<a<<endl;
    cout<<"which one is greater "<<b<<" or " << h<<": "<<min(b,h)<<endl;
    #define e 2.71
    cout<<e<<endl;

    // Now discuss about global variable.
    cout<<"num in main is "<<num<<endl;
    update();
    cout<<"num in again main after update is "<<num<<endl;
    int num = 15;
    cout<<"num is "<<num<<endl;
    {
        int r = 10;
        cout<<"r in explict block is  "<<r<<endl;
    }
    cout<<"r in main is "<<r<<endl;  
}