#include<iostream>
using namespace std ;

int main(){
    int qw[7] = {9,7,5,8,7,9,5} ;
    // for(int j = 0;j<7;j++){
    //     int c = qw[j] ;
    //     int p = 0;
    //     for(int i = 0;i<7;i++){
    //         if(c == qw[i] && i!=j){
    //             p = 1 ;
    //             break ;
    //         }
    //     }
    //     if(p==1){}
    //     else{cout<<"unique element is "<< qw[j];}
    // }
  int n = 7 , i = 0;
  int ans = 0 ;
    while( i < n){
        ans = ans ^qw[i] ;
        i++ ;
    }
    cout<<ans<<endl;
}