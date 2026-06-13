#include<iostream>
using namespace std;
// digit is present or not by linear search;
// using binary search, find key is present or not;
bool search(int arr[],int n,int k){
    if(n<0){return false;}
    else if(arr[0] == k){return true;}
    else{
         search(arr+1,n-1,k);
    }
}

bool search(int arr[],int s, int e,int k){
    int m = s + (e-s)/2;
    if(s>e){return false;}
    else if(arr[m] == k){return true;}
    else if(arr[m]>k){return search(arr,s,m-1,k);}
    else{return search(arr,m+1,e,k); }
    
}
int main(){
    int arr[5] ={3,5,1,2,6};
    int n = 5, key;
    cout<<"Enter key\n";
    cin>>key;
    int ans = search(arr,n,key);
    cout<<ans<<endl;

    int ar[5] = {2,3,5,7,9};
    int m = 5;
    int k;
    cin>>k;
    int s = 0,e = m-1;
    cout<<search(ar,s,e,k);
}