#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m] ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>arr[i][j];}}

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] < 10){cout<<" "<<arr[i][j]<<" ";}
            else{cout<<arr[i][j]<<" ";}

        }cout<<endl; }
    cout<<endl;

    // wave print.
    for(int j = 0 ;j<m;j++){
        for(int i = 0;i<n;i++){
            if(j%2 == 0 ){cout<<arr[i][j]<<" ";}
            if(j%2 == 1 ){ int k = n - i -1 ;cout<<arr[k][j]<<" ";}
        }cout<<endl; }
    cout<<endl;

    // spiral print.
    int co = n*m ,i = 0, j= 0;
    int il = 0,ir = m,id = n, iu = i+1;

    while(co>0){
        // forward k liye.
        for(;j<ir && co>=0;j++){
            cout<<arr[i][j]<<" ";
            co--;
        }cout<<endl;
        j--; i++;
        ir--;

        //  downward k liye.
        for(;i<id && co>=0;i++){
            cout<<arr[i][j]<<" ";
            co--;
        }cout<<endl;
        i--;j--;
        id--;

        //  backward k liye.
        for(;j>=il && co>=0;j--){
            cout<<arr[i][j]<<" ";
            co--;
        }cout<<endl;
        j++;i--;
        il++;

        // upward k liye.
        for(;i>=iu && co>=0;i--){
            cout<<arr[i][j]<<" ";
            co--;
        }cout<<endl;
        i++;j++;
        iu++;

    }
}
// 5 5 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25