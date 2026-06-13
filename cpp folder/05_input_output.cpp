#include<iostream> 
/* #include is a preprocessor directive means it tells the compiler to 
include the contents of the iostream header file before actual compilation starts.*/

// iostream stand for input output stream;
// iostream is a header file;
// there are 2 type of header file.
// 1. system header file : it comes with the compiler .
// 2. user defined header files : it is written by the programmer.
//  hame UDHF banate hai .
// #include "this.h" /* isme hum jo code likhenge voo ye header file mai aayennge.

using namespace std ;
// "cpp reference for header file" se hame
// sari header file mil jayage.
int main(){
int num1, num2 ;
cout<<"enter the value of num1 , num2 :\n";
// "<<" is called as insertion operetor .
// ">>" is called as extraction operator .
cin>>num1 ;
cin>>num2 ;
cout<< "The sum of num1 + num2 is "<< num1 + num2 ;
cout<< "\nThe sum of " << num1 << " + " << num2 << " is "<< num1 + num2 ;
return 0; 
 }