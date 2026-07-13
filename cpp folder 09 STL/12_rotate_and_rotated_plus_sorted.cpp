#include<bits/stdc++.h>
using namespace std;

int main(){
    // vector<int> v;
    // vector<int> v1;
    // int n;
    // cin>>n;
    // for(int i = 0;i<n;i++){
    //     int a; cin>>a;
    //     v.push_back(a);
    // }
    // int k;
    // cin>>k;
    // copy array of v on v1 and rotate at k th element; 
    //  for(int i = 0;i<n;i++){
    //     int a = (i+k)%n;
    //     int t = v[a] ; 
    //     v1.push_back(t);
    // }
    // for(auto it : v1){cout<<it<<" ";}

    vector<int> arr;
    int s;
    cin>>s;
    for(int i = 0;i<s;i++){
        int a; cin>>a;
        arr.push_back(a);
    }
    auto ma = max_element(arr.begin(),arr.end());
    cout<<*ma<<endl;
    int id = 0;
    for(int i = 0;i<s;i++){
        if(arr[i] == *ma){id = i; cout<<id<<endl;break;}
    }

    int ch = 0,sh = 0;
    int i;
    for(i = 0;i<s-1;i++){
       if( arr[i] <= arr[i+1]){continue;}
       else if(i == id ){if(i == s-1){sh = 0; break;} sh = 1 ;continue;}
       else if( arr[i] > arr[i+1]){cout<<"false"<<endl; ch =1;sh = 1; break;}
    }
    if(ch == 0 && arr[i]){cout<<"true"<<endl;}
}