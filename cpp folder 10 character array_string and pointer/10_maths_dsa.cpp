#include<bits/stdc++.h>
using namespace std;

int main(){
    // count prime no. that are less than or equal to n;
    int n;
    cin>>n;
    vector<int>v(n+1,1);
    v[0] = 0;
    v[1] = 0;
    int c = 0;
    for(int i = 2;i<=n;i++){
        if(v[i]){c++;
        for(int j = 2*i;j<=n;j+=i){
            v[j] = 0;
        }
        }
    }
    cout<<c<<endl;

    //Find gcd of two no.??
    /* gcd(a,b) = gcd(a-b,b) || gcd(a,b) = gcd(a%b,b) 
    untill any of them is zero ;*/
    int a,b;
    cin>>a>>b;
    while(a!=0 && b!=0){
        if(a>b){a-=b;}
        else{b-=a;}
    }
    if(a==0){cout<<b<<endl;}
    else{cout<<a<<endl;}
    // LCM(a,b)*GCD(a,b) = a*b;

    /* *** %(modulo Operator) ***
    1. (a+b) % m = a%m + b%m
    2. (a-b) % m = a%m - b%m
    3. (a*b) % m = a%m * b%m
    */
    
    // find (x^y) % m ??
    // TC = O(log(b));
    long long int x,y,m;
    cin>>x>>y>>m;
    long long int ans = 1;
    while(y>0){
        //for odd.
        if(y&1){
            ans = ((ans) * ((x)%m))%m;
        }
        x = ((x)%m) * ((x)%m)%m;
        // y = y/2; ye same work hum niche vali line se bhi kr sakte hai.
        y = y>>1 ;
    }
    cout<<ans<<endl;

}

/*  "HW"
1. pigeon hole principle.
2. catelon series.
3. inclusion exclusion principal.
4. factorial of a number by modulo operator;
*/