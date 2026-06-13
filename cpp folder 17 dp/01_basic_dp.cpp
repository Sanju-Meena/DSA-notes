#include<bits/stdc++.h>
using namespace std;
// 1; fabonacchi series;
// 2> cost of climb a stairs?

int fibo(int n,vector<int> &v){
    if(n <= 1)return n;
    if(v[n] != -1){return v[n];}
    return v[n] = fibo(n-1,v) + fibo(n-2,v);
}

int solve(vector<int> &cost,int n,vector<int> &v){
    if( n == 0 || n == 1 )return cost[n];
    if(v[n] != -1)return v[n];
    int ans = cost[n] + min(solve(cost,n-1,v),solve(cost,n-2,v));
    v[n] = ans;
    return ans;
}

int main(){

    // fabonacchi series ;
    int n = 5;
    vector<int> v(n+1,-1);
    int ans = fibo(n,v);
    cout<<ans<<endl;
    // it's TC = O(n) and SC = O(n) + O(n) ; fist due to vector and second due to recursive call;
    
    // 1.2 solution;
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<endl;

    // 1.3 solution;
    int curr,prev1 = 0,prev2 = 1;
    if(n == 1 || n == 0){curr = n;}
    for(int i = 2;i<=n;i++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    cout<<curr<<endl<<endl;

    // solution 2;
    // go to leetcode question -> Min Cost Climbing Stairs
    vector<int> cost = {1,100,2,3,4,100,5,1,100,6};
    // vector<int> cost = {0,1,1,2};
    // vector<int> cost = {5,10,20};
    n = cost.size();
    v.clear();
    vector<int> vec(n,-1);
    // method 1;
    ans = min( solve(cost,n-1,vec), solve(cost,n-2,vec) );
    cout<<ans<<endl;
   
    // method 2;
    vector<int> dpe(n+1,-1);
    dpe[0] = cost[0];
    dpe[1] = cost[1];
    for(int i = 2;i<n;i++){
        dpe[i] = cost[i] + min(dpe[i-1],dpe[i-2]);
    }

    ans = min(dpe[n-1],dpe[n-2]);
    cout<<ans<<endl;
   
    // method 3;
    int answ = min(cost[0],cost[1]) , back = cost[0],prev = cost[1];
    for(int i = 2;i<n;i++){
        answ = cost[i] + min(prev,back);
        back = prev;
        prev = answ;
    }

    ans = min(answ,back);
    cout<<ans<<endl;


    
}