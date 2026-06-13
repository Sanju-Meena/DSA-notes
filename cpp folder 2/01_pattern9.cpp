#include<iostream>
using namespace std;
// 1
// 2 1 
// 3 2 1
// 4 3 2 1 like this .
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
            cout << k << " ";
            j++;
            k-- ;
        }
        cout << "\n";
        k = k + i +1 ;
        i++ ;
    }
}