#include<bits/stdc++.h>
using namespace std;
// search an element when 2D array in a sorting way;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i = 0 ;i<n;i++){
        for(int j = 0 ; j < m ; j++){
            cin>>arr[i][j];
        }
    }
    int time = 10;
    while(time--){
    int t;
    cin>>t;
    int s = 0,e = n*m - 1;
    int mid = s+(e-s)/2;
    while(s<=e){
        int ele = arr[mid/m][mid%m];
        if(ele == t){cout<<"Found\n";break;}
        else if(ele<t){s = mid+1;}
        else{e = mid-1;}
        mid = s + (e-s)/2;
    }
    if(s>e){cout<<"Not found\n";}
    }

}