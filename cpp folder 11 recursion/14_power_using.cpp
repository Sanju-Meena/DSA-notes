#include<iostream>
#include<string>
#include<vector>
using namespace std;

// int power(int a,int b,int &sum){
//     if(b == 0){return sum;}
//     sum = sum*a;
//     b--;
//     int ans = power(a,b,sum);
//     return ans;
// }

int spower(int a ,int b){
    if(b == 1){return a;}
    if(b % 2 == 0){
        int c = b/2;
        int answ = spower(a,c);
        return answ * answ;
    }
    else{
        int c = b/2;
        int ans = spower(a,c);
        return ans*ans *a;
    }
}

int main(){
    int a,b,ans = 1;
    cin>>a>>b;
    cout<<spower(a,b);

    // int op = power(a,b,ans);
    // cout<<op<<endl;
}