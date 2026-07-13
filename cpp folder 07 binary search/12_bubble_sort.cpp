#include<iostream>
using namespace std;
// pahele biggest no. koo right palace pr rakho and then fir 2nd highest koo.....;
//TC = n-1!
int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int see[n] ;
    for(int i = 0;i<n;i++){
        cin>>see[i] ;
    }
    
    for(int i = 0;i<n-1;i++){
        bool change = false;
        for(int j = 0;j<n-1-i;j++){
          if(see[j] > see[j+1]){
             swap(see[j], see[j+1]);
             change = true;
          }
        }
        if(change == false){
            break;
        }
    }
     
     for(int i = 0;i<n;i++){
        cout<<see[i]<<" " ;
    }
}