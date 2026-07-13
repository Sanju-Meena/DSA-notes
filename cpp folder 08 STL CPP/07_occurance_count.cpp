#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<int> v1;
    set<int> s;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
        s.insert(v[i]);
    }
    
    for (auto it : s){
        int a = count(v.begin(), v.end(), it);
        v1.push_back(a);
    }
    int i = 0;
    for (auto it : s){
        // it++;
        cout << it << " " << v1[i] << endl;
        i++;
    }
}