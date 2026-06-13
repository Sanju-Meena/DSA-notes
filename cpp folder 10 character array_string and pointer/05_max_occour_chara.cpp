#include <iostream>
using namespace std;

int main(){
    string st;
    cin>>st;
    int l = st.length();
    int ans = 0,c,id;
    for(int i =0;i<l;i++){
         c = 0;
        for(int j = 0;j<l;j++){
            if(st[i] == st[j]){
                c++;
            }
        }
     id = max(c,ans);
    ans = id;

    }
    cout<<st[id];
}