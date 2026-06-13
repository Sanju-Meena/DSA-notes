#include <iostream>
using namespace std;

int c = 50;
int main()
{
    int a = 5 , b = 10;
    int c = a + b;
    cout << "the value of c is " << c << endl;
    // :: ---> this is called "scope resolution operator".
    // :: --> ye hamko global variable ko print karvana mai help karta hai.
    cout << "the value of ::c is " << ::c << endl;

    // *********float, double and long double literals**********
    float d = 34.4f;       // yaha hamne or bhi clear kr diya ki float point no. hai d;
    long double e = 34.4l; 
    // 34.5 is bydefault double manta hai.
    cout << "the value of d and e is " << d << ", " << e << endl;
    cout << "Size of 34.4 is " << sizeof(34.4) << endl;
    cout << "Size of 34.4f is " << sizeof(34.4f)<<", " <<sizeof(34.4F) << endl;
    cout << "Size of 34.4l is " << sizeof(34.4l) << ", "<< sizeof(34.4L) << endl<<endl;

    // *************Reference variable*****************
    // ek variable k do naam;
    float v = 455; 
    float &y = v; //yaha v k address ko y naam de diya hai mtlb y = v;
    cout<<"Value of v is "<<v<<endl;
    cout<<"Value of &y is "<<&y<<endl;
    cout<<"Value of y is "<<y<<endl;
    cout << endl;

    // *********Typecasting *************
    int p = 50 ;
    float q = 60.78 ;
    cout<<"the value of p is "<<(float)p <<endl ;
    cout<<"the value of q is "<<(float)q <<endl ;
    cout<<"the value of q is "<<(int)q<<", "<<(int)(q)<<", "<<int(q)<<endl;
    cout<<"the value of p+q is "<<p+q <<endl;
    cout<<"the value of a+b is "<<p+int(q) <<endl;
    return 0;
}