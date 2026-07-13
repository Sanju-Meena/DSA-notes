#include <iostream>
using namespace std;
int power(int a, int b)
{
    int i = 1, ans = 1;
    while (i <= b)
    {ans = ans * a;
     i++;
    }
    return ans;
}

int main()
{
    int a, b;
    cout << "enter the value of a and b\n";
    cin >> a >> b;
    int result = power(a, b);
    cout << result << endl;

    int c, d;
    cout << "enter the value of c and d\n";
    cin >> c >> d;
    result = power(c, d);
    cout << result;
}
