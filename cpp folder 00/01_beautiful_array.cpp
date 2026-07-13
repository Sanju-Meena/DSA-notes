#include <bits/stdc++.h>
using namespace std;

int findind(vector<int> v,int s,int e,int k){
    while(s<=e){
    int m = s+(e-s)/2;
    if(k == v[m]){return m;}
    else if(k < v[m]){e = m-1;}
    else {s = m+1;}
    }

}
int fun(int i){
    return i++;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--){
    //     int n;
    //     cin>>n;
    //     vector<int> v;
    //     for(int i = 0;i<n*n;i++){
    //             int a;
    //             cin>>a;
    //             v.push_back(a);
    //         }
    //         for(int i= 0;i<2*n;i++){
    //             cout<<i+1<<" ";
    //         }
    //     // sort(v.begin(),v.end());
    //     // int le = v[v.size()-1];
    //     // for(int i = 0;i<=le;i++){
    //     //     cout<<v[i]<<" ";
    //     // }
    //     cout<<endl;
    // }
    int a = 4;
    fun(a);
    cout<<a<<endl;
}

