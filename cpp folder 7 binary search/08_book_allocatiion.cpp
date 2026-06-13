#include<iostream>
using namespace std;
bool ispossible(int arr[], int n , int st , int t,int m){
    int pc = 0,b = 1;
    for(int i = 0;i<n;i++){
        if(m >= pc + arr[i]){
           pc = pc + arr[i] ;
        }
        else{
            b++;
            if(st<b || m < arr[i]){
                cout<<0<<endl;
                return false;
            }
            pc = arr[i] ;
        }
    }
    cout<<1<<endl;
    return true;
}

int main(){
    int n,st,t = 0;
    cout<<"Enter size \n";
    cin>>n;  cout<<"kitne student mai batana hai\n";
    cin>>st;
    int arr[n] ; cout<<"array element\n";
    for(int i = 0;i<n;i++){cin>>arr[i] ;}
    for(int i = 0;i<n;i++){ t = t + arr[i] ;}
    int s = 0 , e = t,m = s + (e - s)/2 ;
    int ans = 0;

    while(s<e){
        cout<<m<<endl;
        if((ispossible(arr,n,st,t,m))){
            ans = m;
            e = m -1 ;
        }
        else{
            s = m + 1 ;
        }
        m = s + (e - s )/2;
    }
    
    cout<<"minimum "<<ans ;
}