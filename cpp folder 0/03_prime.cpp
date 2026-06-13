#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<bool> v(1000000,false);
    v[0] = true;
    v[1] = true; 
    for(int i = 2;i<v.size();i++){
        if(v[i] == 0){
            for(int j = 2*i;j<=v.size();j+=i){
                v[j] = 1;
            }
        }
    }
    cout<<"enter x and k\n";
    while(t--){
        int x,k;
        cin>>x>>k;
        if(k>1){
            if(x == 1 && k == 2){
                cout<<"Yes\n";
            }
            else{cout<<"no\n";}
        }
        else{
            if(x == 2 || x==3||x==5){cout<<"Yes\n";}
            else if(x%2 == 0 || x == 1){cout<<"no\n";}
            else if(x<v.size()){
                if(v[x] == 0){cout<<"Yes\n";}
                else{cout<<"No\n";}
            }
            else{
                int ch = 0;
                for(int i = 2;i*i<=x;i++){
                    if(x%i == 0){ch = 1; break;}
                }
                 if(ch == 0){cout<<"Yes\n";}
                 else{cout<<"no\n";}
            }
        }

        
    }
}