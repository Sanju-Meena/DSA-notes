#include <iostream>
using namespace std;
int power()
{
    int i = 1, ans = 1;
    int a, b;
    cout << "enter the value of a and b\n";
    cin >> a >> b;
    while (i <= b)
    {ans = ans * a;
      i++;
    }
    cout << "power of " << a << " and " << b << " is " << ans << endl;
    return ans;
}

int main()
{
    int result = power();
    result = power();
    result = power();
}