#include <iostream>
using namespace std;
int main()
{
    int a = 4;
    int b = 6;
    // left shift.
    cout<<(a<<1)<<endl; // a ko 1 baar left shift kr do.
    // a = 000..100
    //<<a = 0000...1000 = 8.{ 4 *2}
    cout<<(3<<2)<<endl ;//00..11
                //   00..1100.=12{3*2*2}
    // RIGHT SHIFT.
    cout<<(b>>1)<<endl;//00..110
                       //000..11. = 3{6/2}.
     cout<<(b>>2)<<endl;
                        //0000...1.=1
   //000..11. = 3{6/(2*2)}
//    but always muntiply by 2 or divide by 2 ka funda nahi chalega.

    cout<<a<<endl<<b<<endl;
}
//  always padding with 0 in positive no.but in -ve no.
// depend upon the compiler.