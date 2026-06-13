#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a,b;
        cin>>a>>b;
        string st;
        cin>>st;
        vector<char> v;
        vector<int> xc;
        vector<int> yc;
        for(int i = 0;i<n;i++){
            char z = st[i];
            v.push_back(z);
        }
        int x = 0,y=0,ch = 0;
        for(int i = 0;i<n;i++){
            if(v[i] == 'E'){x++;}
            else if(v[i] == 'W'){x--;}
            else if(v[i] == 'N'){y++;}
            else if(v[i] == 'S'){y--;}
            xc.push_back(x);
            yc.push_back(y);
            if(x == a && y == b){cout<<"yes\n";ch = 1;break;}
            if(i == n-1){if(x == 0 && y == 0){cout<<"No\n";ch =1;break;}}
            // if(x > (a+6) || y > (b+6)){cout<<"no\n";break;}
        }

        if(ch == 0){
            int xcd = xc[n-1], ycd = yc[n-1];
            int vd ,s,e;
            for(int i = 0;i<n;i++){
                vd = yc[i] - xc[i];
                s = xc[i],e=yc[i];
                while(s < 11 || e < 11){
                    s = s + xcd; e = e + ycd;
                    if(s == a && e == b){cout<<"Yes\n"; ch = 1; break;}
                }
                if(ch == 1){break;}
                
            }
            if(ch == 0){cout<<"No\n";}
        }
        // cout<<endl;
    }
}
