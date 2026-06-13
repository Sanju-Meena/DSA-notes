// #include <bits/stdc++.h>
// using namespace std;

// // int index(vector<int> v,int k){
// //     int s = 0,e = v.size()-1;
// //     int m = s+(e-s)/2;
// //     while(s<=e){
// //         if(v[m] == k){return m;}
// //         else if(v[m] < k){s = m+1;}
// //         else{e = m - 1;}
// //         m = s + (e-s)/2;
// //     }
// // }

// int main(){
//     int t;
//     cin >> t;
//     while (t--){
//         string st;
//         cin>>st;
//         int n = st.length();
//         vector<int> v;
//         for(int i = 0; i < n; i++){
//             int a = st[i] - '0';
//             cin >> a;
//             v.push_back(a);
//         }
//         vector<int> v1 = v;
//         sort(v1.begin(),v1.end());
//         for(int i = 0;i<n;i++){
//             if(v[i] == v[i+1]){


//             }
//         }


//     }
// }

// /*
// aea,aaaa,aaee,aabcd type hai too yes.
// */

#include<iostream>
using namespace std;

int main(){
    string st;
    cin>>st;
    swap(st[0],st[1]);
    cout<<st<<endl;

}