#include<bits/stdc++.h>
using namespace std;
// sort algorithm input mai address mai leta hai.
// TC = nlog(n) ;
// inbuilt algorithm hum use karte hai iska naam hai introsort.
// introsort  = mix of 3 sort that are (quick short + heap sort + insertion sort ).
int main(){
    int arr[6] = {5,4,2,25,7,8} ;
    /* sort(a,b); sort k ander hum address dete hai ,a ka mtlb kaha jaha se sorting start karni hai vaha ka address
       b mai hum jaha tk sorting karni hai uske agle element ka address.    */
       sort(arr,arr+6) ; //arr mtlb first element ka address or arr+6 mtlb 6th element k agle element ka address.
       for(int i = 0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    vector<int> v = {7,4,6,3,90,43,2,5,7};
    sort(v.begin()+2,v.end() - 2) ; //2nd index se sort karna hai or last 3rd elment tk sort karna hai. 
       for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}