#include<bits/stdc++.h>
using namespace std;
// given n string : 
//  abc def abc ghj jkl ghj ghj abc
// print unique string only.

void print(set<string> sd){
    for(string it : sd){
        cout<<it<<endl;
    }
}
int main(){
    set<string> sd;
    int n; cout<<"enter the no. of string : ";
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        sd.insert(s);
    }
    print(sd);
}

/*

8
abc def abc ghj jkl ghj ghj abc

*/