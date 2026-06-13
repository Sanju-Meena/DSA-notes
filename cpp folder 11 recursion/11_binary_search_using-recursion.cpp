#include<iostream>
using namespace std;
// using binary search, find key is present or not;
bool search(int arr[],int s, int e,int k){
    int m = s + (e-s)/2;
    if(s>e){return false;}
    else if(arr[m] == k){return true;}
    else if(arr[m]>k){return search(arr,s,m-1,k);}
    else{return search(arr,m+1,e,k); }
    
}

int main(){
    int arr[5] = {2,3,5,7,9};
    int n = 5;
    int k;
    cin>>k;
    int s = 0,e = n-1;
    cout<<search(arr,s,e,k);
}