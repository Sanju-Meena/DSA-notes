#include<bits/stdc++.h>
using namespace std;

//Lower bound mai value present hogi too voo he aayegi nahi too uske agle vali aayegi. 
void lower_bounde(int *a,int *b,int d){
    int *ptr = lower_bound(a,b,d) ;
    if(*ptr == *b){cout<<"no value\n";} //ye na karte too garbage value aati.
   else{cout<<*ptr<<endl;}
}

// upper bound mai hamesa value de gai value ki agli value aayegi. 
void upper_bounde(int *a,int *b,int d){
    int *ptr = upper_bound(a,b,d) ;
    cout<<*ptr<<endl;
}

 int main(){
    int n = 6;
    int arr[n] = {4,5,5,25,7,8};
    sort(arr,arr+n); 
    for(auto v : arr){cout<<v<<" ";}
    cout<<endl;
    lower_bounde(arr,arr+n,1) ;
    lower_bounde(arr,arr+n,4) ;
    lower_bounde(arr,arr+n,5) ;
    lower_bounde(arr,arr+n,6) ;
    lower_bounde(arr,arr+n,28) ;
    for(auto v : arr){cout<<v<<" ";}
    cout<<endl;
    upper_bounde(arr + 3,arr+n,1) ;
    upper_bounde(arr,arr+n,3) ;
    upper_bounde(arr,arr+n,4) ;
    upper_bounde(arr,arr+n,5) ;
    upper_bounde(arr,arr+n,24) ;
    upper_bounde(arr,arr+n,25) ;
    upper_bounde(arr,arr+n,89) ;
    // both have same time complexcity = O(log(n)).

    vector<int> v = {4,5,5,25,7,8};
    sort(v.begin(),v.end()); 
    for(auto c : v){cout<<c<<" ";}
    cout<<endl;
    auto ib = lower_bound(v.begin(),v.end(),7) ;
    cout<<(*ib) <<endl;
    auto it = lower_bound(v.begin(),v.end(),25) ;
    cout<<*it<<endl;
    auto ir = upper_bound(v.begin(),v.end(),5) ;
    cout<<*ir<<endl;
    auto is = upper_bound(v.begin(),v.end(),25) ;
    cout<<*is<<endl;

 }