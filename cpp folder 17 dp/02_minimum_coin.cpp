#include<bits/stdc++.h>
using namespace std;
/*
Q1> minimum no. of coin required to make a amount; gog pr all 3 solution hai;
used two approach : 1st rec+memo , 2nd LOOP;

Q2> maximum sum of non adjacent element?  gog pr all 3 solution;
if element in circle than solution is (take out ans form the vector 0 to n-2 and than take out the ans from 1 to n -1 by doing nums[0] = 0;)
This problem is in leetcode;

Q3. Cut the rod in 3 segment x,y,z only, find the maximum no. of segment that can be cut so that no rod is left;

Q4. Dearrangement of n element :  ans = n-1 * (d[n-1] + dp[n-2]);
Q5. Painting n fench with k colours done on gog by all method; 
*/


// 1st minimum no. of coins;
// rec + mem
int solve(int amount,vector<int> &v){
    vector<int> dp(amount+1,INT_MAX );
    dp[0] = 0;
    for(int i = 1;i<=amount;i++){
        for(int j = 0;j<v.size();j++){
            int ra = i - v[j];
            if(ra >= 0 && dp[ra] != INT_MAX){
                dp[i] = min(dp[i],1+dp[ra]);
            }
        }
    }

    if(dp[amount] == INT_MAX)return -1;
    else return dp[amount];
}

int solverec(int amount,vector<int> &v,vector<int> &dp){
    if(amount == 0)return 0;
    if(amount < 0)return INT_MAX;
    if(dp[amount] != -1)return dp[amount];

    int mini = INT_MAX;
    for(int j = 0;j<v.size();j++){
        if(amount - v[j] >=0){
            int ans = solverec(amount - v[j],v,dp);
            if(ans != INT_MAX){mini = min(mini,1+ans); }
        }
    }
    dp[amount] = mini;
    return mini;
}

// solution 2;
// isko mai variable lekr bhi solve kr sakta hu method 1 ko;
void solve(vector<int> &arr,vector<int> &dp){
    dp[0] = arr[0];
    if(arr.size() >= 2){dp[1] = arr[1];}
    if(arr.size() >= 3){dp[2] = arr[0] + arr[2];}
    for(int i = 3;i<arr.size();i++){
        dp[i] = arr[i] + max(dp[i-2],dp[i-3]);
    }
}

int aa(vector<int> &arr,int i,vector<int> &dp){
     if(i < 0 )return 0;
     if(dp[i] != -1)return dp[i];

     int inc = arr[i] + aa(arr,i-2,dp);
     int ex = aa(arr,i-1,dp);
     
     int ans = max(inc,ex);
     dp[i] = ans;
     return ans;
}

// solution 3;
// by dp 
int rodcut(int n,int x,int y,int z,vector<int> &dp){
    int cm = min(x,min(y,z)) ;
    for(int i = 1;i<=n;i++){
        int a = -1,b = -1,c = -1;
        if(i < cm)dp[i] = -1;
        else{
            if(i-x >= 0)a = dp[i - x];
            if(i-y >= 0)b = dp[i - y];
            if(i-z >= 0)c = dp[i - z];
            int mm = max(a,max(b,c)) ;
            if(mm != -1) dp[i] = 1 + mm;
        }
    }
    if(dp[n] == -1)return 0;
    return dp[n] ;
}

// by rec and ismai hum memorization bhi use kr sakte hai usse tc km ho jayegi;
int rec_rodcut(int n,int x,int y,int z){
    if(n == 0)return 0;
    if(n < 0) return INT_MIN;
    
    int a = rec_rodcut(n-x,x,y,z);
    int b = rec_rodcut(n-y,x,y,z);
    int c = rec_rodcut(n-z,x,y,z);
    int aa = max(a,max(b,c));
    
    if(aa == INT_MIN)return INT_MIN;
    return 1 + aa;
    
}
int main() {
    int amount = 6249;
    // cin>>amount;
    int n = 4;
    // cin>>n;
    vector<int> coins = {83, 186,419,408};
    // for(int i = 0;i<n;i++){int a ; cin>>a ; coins.push_back(a);}
    // Question no. 1;
    // by loop;
    int ans = solve(amount,coins);
    cout<<"coin required = "<<ans<<endl;

    // second by recursion + memoization
    vector<int> dpe(amount+1,-1);
    dpe[0] = 0;
    int answ = solverec(amount,coins,dpe);
    if(answ == INT_MAX){cout<<-1<<endl;}
    else{cout<<answ<<endl<<endl;}


    // solution of 2;
    // method 1;
    vector<int> vec = {12,11,1,24};
    // for(int i = 0;i<n;i++){int a ; cin>>a ; vec.push_back(a);}
    n = vec.size() ;
    if(n == 1)cout<< vec[0]<<endl;
    else if(n == 2)cout<< max(vec[0],vec[1])<<endl;
    else{
        vector<int> dp(vec.size()+1, -1);
        solve(vec,dp);
        
        int maxi = max(dp[n-1],dp[n-2]);
        cout<<maxi<<endl;
    }

    // method 2 rec + mem;
    vector<int> dep(vec.size() + 1,-1);
    dep[0] = vec[0];
    dep[1] = max(vec[0],vec[1]);
    int anw = aa(vec,vec.size() -1,dep);
    cout<<anw<<endl;


    //solution 3;
    n = 22;
    int x = 7, y = 4, z = 13;
    vector<int> ddp(n+1,-1);
    ddp[0] = 0;
    cout<< rodcut(n,x,y,z,ddp)<<endl;

    // 2nd solution by recursion;
    ans = rec_rodcut(n,x,y,z);
    if(ans == INT_MIN)cout<<0<<endl;
    else cout<<ans<<endl;
    
}
/*
for q1.
11   3 
1 2 5

6 3
4 3 1
*/

/*
for q2 ex: 12 11 1 24;
// 15 5 10 100 10 5
*/