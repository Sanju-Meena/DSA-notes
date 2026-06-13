#include <iostream>
using namespace std;
// 1
// 2 3
// 4 5 6
// 7 8 9 10 like this .
int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    int i = 1;
    int k = 1 ;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << k<< " ";
            j++;
            k++ ;
        }
        cout << "\n";
        i++;
    }
}