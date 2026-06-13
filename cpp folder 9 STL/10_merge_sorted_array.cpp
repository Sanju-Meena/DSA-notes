#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 4;
    int arr[n] = {2,4,6,8} ;
    int m = 5;
    int ar[m]={1,5,5,7,9} ;
    int as[n+m] ; 
    // int j = 0;
    // for(int i =0;i<n+m;i++){
    //    if(i < n){as[i] = arr[i];}
    //    else if(i >= n) { as[i] = ar[j]; j++;}
    // }
    // sort(as,as+(n+m)) ;
    // for(auto it : as){cout<<it<<" ";}cout<<endl; 
    int i = 0,j=0,k=0;
    for(; j<m && i<n;k++){
        if(arr[i] > ar[j] ){as[k] = ar[j++];}
        else if(arr[i] == ar[j]){as[k] = ar[i]; k++; as[k]= ar[i++];j++;}
        else if(arr[i] < ar[j]){as[k] = arr[i++];}
    }
    while(i<n){as[k++] = arr[i++];}
    while(j<m){as[k++] = ar[j++];}
    for(auto it : as){cout<<it<<" ";}cout<<endl;

}