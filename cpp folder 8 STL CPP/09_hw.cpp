#include <bits/stdc++.h>
using namespace std;
//given t test case that represent no. of candys bags;
// given b-->no. of candy in first bags;
// given k-->no. of candy in each packet;
// cout << "enter the value of  : ";
// take packet that maximum no. of candy and put half candy in it after eaten all;
// find maximum no. of candy eaten ;
int main(){
    int t;
    cout << "enter the value of t : ";
    cin >> t;
    int s = 0;
    while (t--){
        int b, k;
        cout << "enter the value of b and k : ";
        cin >> b >> k;

        multiset<int> m;
        cout << "enter the value of candy in each packet : ";
        for (int i = 0; i < b; i++){
            int l;
            cin >> l;
            m.insert(l);
        }

        int cou = 0;
           for (int i = 0; i < k; i++){
            auto it = (--m.end()) ;
            cou = *it ;
            s = s + cou;
            m.erase(it);
            m.insert(cou/2) ;
        }
    }
    cout<<s<<endl;
}
