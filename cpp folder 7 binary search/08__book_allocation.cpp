#include <iostream>
using namespace std;
// isme hame n0. ka partition karna hai jisse maximum no. aaye partition k baad unka minimum hamara anns hoga .
bool ispossible(int arr[], int size, int n, int mid)
{
    int student = 1, count = 0;
    for (int i = 0; i < size; i++)
    {
        if (mid >= count + arr[i])  {
            count = count + arr[i];
        }
        else{
             student++;
            if (n < student || mid < arr[i]){
                cout<<0<<endl;
            return false;}
            count = arr[i] ;
        }
    }
    cout<<1<<endl;
    return true;
}

int book_allocation(int arr[], int size, int t, int n)
{
    int s = 0, e = t;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e){         
        if(ispossible(arr, size, n, mid)){
             ans = mid;
             e = mid - 1;
              cout<<"e = "<<e<<endl;
        }
        else{
            s = mid + 1;
            cout<<"s = "<<s<<endl;
        }
        mid = s + (e - s) / 2;
        cout<<"mid = "<<mid<<endl;
    }
    cout<<ans<<endl;
    return ans;
}

int main()
{
    int x;
    cout<<"array size : ";
    cin >> x;
    int ar[x];
    for (int i = 0; i < x; i++) {
        cin >> ar[i];
    }
    int t = 0;
    for (int i = 0; i < x; i++)
    {
        t = t + ar[i];
    }
    cout<<t<<endl;
    int n;
    cout << "no. of student.\n";
    cin >> n;
    int ans =  book_allocation(ar, x, t,n);
    cout<<ans;
}