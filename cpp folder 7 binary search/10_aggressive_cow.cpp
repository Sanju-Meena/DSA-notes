#include <iostream>
using namespace std;

bool possible(int arr[] , int size,int t,int dif,int cow){
    int s = 0,e = t,c = 1;
    for(int i = 0;i<size;i++){
        for(int j = i+1;j<size;j++){
            int a =  arr[i], b =  arr[j], r;
            if(a>b){r = a-b;}
            else{r = b-a;}
            if(r >= dif){
            cout<<1<<endl;
            return true;}
            
        }
    }
    cout<<0<<endl;
    return false;
}

int solution(int arr[] , int size,int t){
    int s = 0,e = t;
    int c;
     cout<<"no. of cow \n";
    cin>>c;
    int dif = s + (e - s)/2 ;
     int ans = -1;
    while(s<=e){
        if(possible(arr,size,t,dif,c)){
            ans = dif ;
            s = dif +1;
            cout<<"s = "<<s<<endl ;
        }
        else{
            e = dif -1;
            cout<<" e = "<<e<<endl;
        }
        dif = s + (e - s)/2 ;
        cout<<"dif = "<<dif<<endl ;
    }
    return ans;
}

int main(){
    int n;
    cout<<"enter size : ";
    cin>>n;
    int arr[n] ;
    for(int i = 0;i<n;i++){
      cin>>arr[i];
    }
    int max = arr[0];
     for(int i = 0;i<n;i++){
      if(max<arr[i]){
        max = arr[i] ;
      }
    }
    int x = solution(arr,n,max);
    cout<<x;
}