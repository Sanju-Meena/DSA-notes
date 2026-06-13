#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int main() {
	int t ;
	cin>>t;
while(t--){
    int n;
    cin>>n;
    int x ;
    cin>>x;
    int s= 0 ,c =0;
    int j = n,k=x;
    for(;x>0;x--){
        s = s + (pow(2,n));
        n--;
    }
    cout<<s<<endl;
    for(int i = 1;i <= (j-k);i++){
        c= c+(pow(2,i));
        cout<<c<<endl;
    }
    cout<<c<<endl;
    cout<<s-c;
}
}