#include<bits/stdc++.h>
using namespace std;

int minid(int s ,int e,vector<int> v);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string string;
        cin>>string;
        vector<int> v;
        for(int i = 0;i<n;i++){
            int a = string[i] -'0';
            v.push_back(a);
        }
        vector<int> rev  = v;
        reverse(rev.begin(),rev.end());
        vector<int> so = v;
        sort(so.begin(),so.end());

        int ch = 0;
        // check all element are same or ot;
        if(so[0] == so[n-1]){cout<<"NO\n";}
        else if(k==0 || n==2){
            for(int i = 0;i<n;i++){
                if(v[i] < rev[i]){cout<<"Yes\n";ch =1; break;}
                else if(v[i] > rev[i]){ cout<<"no\n";ch = 1;break;}
            }
            if(ch == 0){cout<<"No\n"; }
        }
        else{

            for(int i = 0;i<n && k>0;i++){
                if(v[i] < rev[i]){cout<<"Yes\n"; ch = 1;break;}
                else if(v[i] == so[i]){}
                else{
                    if(i<n-1){
                        int id = minid(i,n-1,v);
                        if(v[i] != v[id]){
                            swap(v[i],v[id]);
                            k--;
                        }
                        if(v[i] < rev[i]){cout<<"Yes\n";ch = 1;break;}
                    }                    
                }    
            }
            if(ch == 0){cout<<"No\n";}

            
        }


            
    }
}

int minid(int s ,int e,vector<int> v){
    int id = s;
    for(int i = s+1;i<=e;i++){
        if(v[id] > v[i]){id = i;}
    }
    return id;
}