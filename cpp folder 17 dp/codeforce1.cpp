#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int v[n];
        long long ans = 0;

        for(int i = 0; i < n; i++){
            cin>>v[i];
        }
        
        for(int i = 0; i < n - 1; i++){
            ans += abs(v[i] - v[i+1]);
        }

        long long maxsav = 0;      
        maxsav = max(maxsav, (long long)abs(v[0] - v[1]));    
        maxsav = max(maxsav, (long long)abs(v[n-2] - v[n-1]));
        
      
        for(int i = 1; i < n - 1; i++){
            long long cc = abs(v[i] - v[i-1]) + abs(v[i] - v[i+1]);
            long long nc = abs(v[i-1] - v[i+1]);
            long long sav = cc - nc;

            if(sav > maxsav){
                maxsav = sav;
            }
        }

        cout << ans - maxsav << endl;
    }
}