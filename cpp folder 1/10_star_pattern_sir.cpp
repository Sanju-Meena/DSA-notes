#include <iostream>
using namespace std;
// ****
// ****
// ****
// **** likethis.
// draw pattern as same as upper side is given.

int main()
{
    int n;
    cout << "enter the value of n" << endl;
    cin >> n;
    int i = 1;
    while (n >= i)
    {
        int j = 1;
        while (j <= n)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}
// j is the number of column;
// i is the number of row.
// n is the no.of star in a row.