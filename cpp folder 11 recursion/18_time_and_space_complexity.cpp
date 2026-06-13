#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// TC = total no. of loop count + total no. of function call (in general);
// space complexity = maximum no. of variable store at any instance of time;

int fact(int n){
    if( n == 0 || n == 1){return 1;}
    return n*fact(n-1);
}

int fib(int n){
    if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}
int main(){
    int t;
    cin>>t;
    int ans = fact(t);
    cout<<ans<<endl;
    // TC = O(n) -> due to n-1 recursive call for factorial function;
    // sc = O(n); due to n stack call;


    // Binary search;
    int n = 10;
    int arr[10] = {1,25,36,24,45,51,21,31,45,100};
    sort(arr,arr+n);
    for(int i = 0;i<10;i++)cout<<arr[i]<<" "; cout<<endl;
    // TC = O(logn);
    // sC = O(logn);

    // fibonacchi series;
    ans = fib(t);
    cout<<ans<<endl;
    // no. of function call  = 1.618 ^ n; and in general 2^n;
    // SC = O(n);

}