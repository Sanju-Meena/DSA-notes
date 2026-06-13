#include <iostream>
using namespace std;

int I_LOVE_YOU = 143 ; //Declare a global variable;

void fun(){
    int a =9;
    cout<<"the value of I_LOVE_YOU is "<<I_LOVE_YOU <<"\n" ;
    int I_LOVE_YOU = 13 ; 
    cout<<"the value of I_LOVE_YOU is "<<I_LOVE_YOU <<"\n" ;
}

int main()
{
    int I_LOVE_YOU = 1 ; //yaha hamne local variable declare kiya hai.
     I_LOVE_YOU = 14 ;
    fun() ;
    cout<<"\nThe value of I_LOVE_YOU is "<<I_LOVE_YOU<<endl ;
    {
        cout<<"The value of I_LOVE_YOU is "<<I_LOVE_YOU<<endl ;
        I_LOVE_YOU = 1 ;
        cout<<"The value of I_LOVE_YOU is "<<I_LOVE_YOU ;  
    }
    

    bool I_LOVE_YOU ;
    cout<< I_LOVE_YOU <<".\n" ; // ye 0 print karega .
    I_LOVE_YOU = true ;
    bool I_hate_YOU = false ;
    cout<< I_LOVE_YOU <<".\n" ; // ye 1 print karega .
    cout<< I_hate_YOU ; // ye 0 print karega 
    return 0;
}