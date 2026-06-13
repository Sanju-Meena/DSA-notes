#include<iostream>
using namespace std ;

int main(){
cout<<"operator in cpp:"<<endl ;

//  Arithmetic operators.
int a=10, b=8 ;
cout<<"The sum of a+b is "<<a+b<<endl;
cout<<"The subtraction of a-b is "<<a-b<<endl;
cout<<"The muntiply of a*b is "<<a*b<<endl;
cout<<"The divide of a/b is "<<(float)a/b<<endl;
cout<<"The divide of a/b is "<<a/b<<endl;
cout<<"The divide of a/b is "<<float(a/b)<<endl; //it will give you 1 .
cout<<endl;

// increment and decrement operator.
cout<<"The remainder of a%b is "<<a%b<<"\n";
cout<<"The increment of a++ is "<<a++<<"\n";
cout<<"The increment of ++a is "<<++a<<"\n";
cout<<"The decrement of a-- is "<<a--<<"\n";
cout<<"The decrement of --a is "<<--a<<endl;
cout<<"The value of a is "<<a<<endl;
cout<<"The value of b is "<<b<<endl;
cout<<endl;

// Assignment operators-->use to assign value to variable.
int c = 4; 
float s_f = 6.5 ;
char jkl = 'd' ;

// comparision operator or relational operator and it will give value either 1 or 0;
cout<<"The value of a==b is "<< (a==b) ;
cout<<"\nThe value of a!=b is "<< (a!=b) ;
cout<<"\nThe value of a<=b is "<< (a<=b) ;
cout<<"\nThe value of a>=b is "<< (a>=b) ;
cout<<"\nThe value of a>b is "<< (a>b) ;
cout<<"\nThe value of a<b is "<< (a<b)<<endl ;
cout<<endl;

// logical operator
a = 10,b = 8;
cout<<"The value of this logical operator is : "<<(a!=b && a>b)<< endl;
cout<<"The value of this logical operator is : "<<(a!=b && a<b)<< endl;
cout<<"The value of this logical operator is : "<<((!(a==b)) || (a<b))<< endl;
return 0; 
}