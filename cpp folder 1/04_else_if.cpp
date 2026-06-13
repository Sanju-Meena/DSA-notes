#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "enter the value of a and b\n";
    cin >> a >> b;
    cout << "the value of a and b is " << a << "," << b << endl;

    if (a > b)
    {
        cout << "a is greater than b\n";
    }
    else
    {
        cout << "b is greater than a";
    }
}