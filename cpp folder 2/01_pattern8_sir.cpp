#include <iostream>
using namespace std;
// 1
// 2 3
// 3 4 5 
// 4 5 6 7 like this .
int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    int i = 1;
    // int value = i ;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << j+i-1 << " ";
            j++;
            // hum ye bhi kr sakte the.
            // cout<<value ;
            //  value++ ;
            // j++ ;
        }
        cout << "\n";
        i++;
    }
}