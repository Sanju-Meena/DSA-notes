#include<bits/stdc++.h>
using namespace std;
//rotate a matrix n*n by 90 degree in clockwise direction;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i = 0 ;i<n;i++){
        for(int j = 0 ; j < m ; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    for(int i = 0 ;i<n;i++){
        for(int j = 0 ; j < m ; j++){
            cout<<arr[i][j]<<" ";
        }cout <<endl;
    }
    cout<<endl;    

    for(int i = 0 ;i<n;i++){
        for(int j = 0 ; j < m/2 ; j++){
            swap(arr[i][j],arr[i][m-1-j]);
        }
    }

    for(int i = 0 ;i<n;i++){
        for(int j = 0 ; j < m ; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;

    for(int i = 0 ;i<n-1;i++){
        for(int j = 0 ; j < m-1-i ; j++){
           swap(arr[i][j],arr[n-1-j][m-1-i]);
        }
    }

     for(int i = 0 ;i<n;i++){
        for(int j = 0 ; j < m ; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    
}