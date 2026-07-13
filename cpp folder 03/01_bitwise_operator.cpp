#include <iostream>
using namespace std;
//( and-->&, or-->|, not---> ~ , xor---> ^)
int main()
{
    int a = 4;
    int b = 6;
    int c = a & b;
    // 100 & 110 = 100= 4;
    int d = a | b;
    // 100 | 110 = 110= 6;
    int e = a ^ b;
    // 100 ^ 110 = 010= 2;
    int f = ~a;
    // a = 000...100
    //~a = 111...011
    // now print to take 2 compliment.
    //  1--> 000...100
    // 2---> 000...101 = -5.
    cout << (a&b) << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
}
// int a = 2 , b = 3;
//( and-->&, or-->|, not---> ~ , xor---> ^)
// 0perator( and--> & => 2 & 3 => 10 & 11 now plus 10
//  +  11
// ---------
// and k case mai  =  10 = 2
// or k case mai  =   11 = 3

//  if a = 5 ;
// then  a = 000000...... 101 ;
// then ~ a = 1111....... 010;
// to print ~a then take 2's compliment of ~a
// 1 st compliment--->0000......101
//  2 nd compliment--->   add 1
//              ---> 00000000....102.
//  ~a = -5 means-(2*2^0 + 1*2^2) = -6 ans.

// now xor---> ^ atmost one 1 pr 1 and baki sb pr 0.
// int a = 2 , b = 3;
// a^b = 010 ^ 100 = 110
//  a^b = 110=6