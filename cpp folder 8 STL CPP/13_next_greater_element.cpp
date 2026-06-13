#include<bits/stdc++.h>
using namespace std;
// find next greater element array;
int main(){
    int arr[6] = {4,5,2,25,7,8} ;
    int asd[6] ;

    for(int i = 0;i<6;i++){
        int s = arr[i] ,c=0;
        for(int j = i+1;j<6;j++){
            if(s<arr[j]){c = 1;s = arr[j]; break;}
        }
        if(c==0)asd[i] = -1;
        else{asd[i] = s ;}
    }

    for(int i = 0;i<6;i++){
        cout<<asd[i]<<" ";
    }
// TC = O(n^2) ;
}