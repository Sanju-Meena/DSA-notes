#include<iostream>
using namespace std;

void reverse(string &st,int l){
    int i = st.length() - 1 - l;
    if(i>l){return ;}
    swap(st[i],st[l]);
    reverse(st,l-1);
    // reverse(st,i++,l--); This is not work properly;
    return ;   
}

bool checkpalindrome(string &st,int l,int i){
    if(i > l){return true;}
    else if(st[i] == st[l]){
       return checkpalindrome(st,l-1,i+1);
    }
    else{return false;}
}

int main(){
    string st;
    cin>>st;
    int l = st.length();
    reverse(st,l-1);
    cout<<st<<endl;

    int i = 0;
    cout<<checkpalindrome(st,l-1,i)<<endl; 
    //method second is to compare reverse and actual string.
    
}