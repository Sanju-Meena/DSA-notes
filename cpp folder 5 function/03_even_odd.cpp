#include <iostream>
using namespace std;

void even_odd()
{
    int a;
    cout << "enter the value of a\n";
    cin >> a;
    if (a % 2 == 0)
    cout << "number is even\n ";
    else
    cout << "num is odd\n";
}

int main()
{
    even_odd();
    even_odd();
    even_odd();
}
