#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 34;
    a = 45;
    cout << "The value of a is " << a << endl;
    char ch = 's';
    ch = '4';
    cout << "the character of ch is " << ch << endl;
    // constant in c++
    const int b = 5;
    //  b = 7 ; ---> ab aap ye nahi kr sakte kyuki b aapka ek constant hai.
    //  b = 7 likhne p ab error aaayega .
    cout << b << endl;

    // setw(x)---->x ki jitne value utni space leave karega fir value print karega.

    // manupulator in c++ .
    int p = 4, q = 5, r = 6;
    cout << "the value of p is " <<setw(p)<< p<<endl;
    cout << "the value of q is " <<setw(4)<< q<<endl;
    cout << "the value of r is " <<setw(3)<< r<<endl;
    return 0;
}