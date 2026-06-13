#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void print(int arr[][3],int r,int c){ 
    /*Hame function call k liye column ki length constant karni hogi main function mai,
     variable nahi le sakte, nahi too call nahi hoga.*/
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}
bool ispresent(int arr[][3],int r,int c,int t){
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(t == arr[i][j]){return true;}
        }
    }
    return false;
}

int main(){
    //Internal working of 2D array ;
    int r,c;
    cin>>r>>c;
    int v[r*c];
    for(int i = 0;i<r*c;i++){
        cin>>v[i];
    }
    int ro,co;
    cout<<"Enter the row and column number : ";
    cin>>ro>>co;
    cout<<v[c*(ro-1) + (co-1)]<<endl; //--->ismai hum row or column k indices ko 1 se start karvayenge;
    // cout<<v[c*ro + co]<<endl; //ismai hum row or column k indices ko 0 se start karvayenge;

    int in,jn;
    cin>>in>>jn;
    int arr[in][jn];

    //take column wise input;
     for(int i = 0;i<jn;i++){
        for(int j = 0;j<in;j++){
            cin>>arr[j][i];
        }
    }
    
    int ar[2][3] = {7,2,3,4,5,6};
    // int ar[2][3] = {{1,2,3},{4,5,6}}; //same hai jo upar wali line karti hai voo ye bhi karega;
    print(ar,2,3);
    int target;
    cout<<"Enter a no. that you check it is present or not\n";
    cin>>target;
    if(ispresent(ar,2,3,target)){cout<<"Present hai\n";}
    else{cout<<"Present nahi hai\n";}

    // largest column sum and column no. ??
    int ros,clo;
    cin>>ros>>clo;
    int as[ros][clo];
    for(int i = 0;i<ros;i++){
        for(int j = 0 ;j<clo;j++){
            cin>>as[i][j];
        }
    }
    
    int maxi = INT_MIN,indi;
    // INT_MIN integer ki sabse choti value ko store karta hai.
    for(int i = 0;i<clo;i++){
        int s = 0;
        for(int j = 0;j<ros;j++){
            s+=as[j][i];
        }
        if(maxi <s){cout<<maxi<<" "<<s<<endl;maxi = s; indi = i; }
    }
    cout<<"largest sum of column no "<<indi+1<< " is "<<maxi;
    



}