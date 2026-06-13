#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                
            }
        }
        vector<int> v1 = v;
        sort(v1.begin(),v1.end());
        int max = v[n-1];
        int min = v[0];
        for(int i = 0;i<n;i++){
            if(v[i] == max){//saare 1 iske baad}
            else if(v[i] == min){}
        }
        // max k baad min se pahele saare 1 bana sakte hai;


    }
}