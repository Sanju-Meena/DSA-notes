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
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout <<i-j+1 << " ";
            j++;
        }
        cout << "\n";
        i++ ;
    }
}