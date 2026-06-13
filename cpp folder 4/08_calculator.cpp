#include <iostream>
using namespace std;

int main()
{
    int a,b ;
    cin>>a>>b;
    char sign;
    cout << "enter the sign\n";
    cin >> sign;
    switch (sign)
    {
    case '+': cout<<"sum is "<<(a+b);
              break;
    case '-': cout<<"difference is "<<(a-b);
              break;
    case '*': cout<<"muntlipication is "<<(a*b);
              break;
    case '/': cout<<"divide is "<<(a/b);
              break;
    }                         
}
