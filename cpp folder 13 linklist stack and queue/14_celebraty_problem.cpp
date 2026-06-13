#include<iostream>
#include<vector>
#include<stack>

using namespace std;
// // Q1: easy ::celebrity problem : everyone knows celebrity but celebrity known noone;
// // Q2 : max rectangle in binary matrix;
void nextsmaller(vector<int> v,stack<int> s,int n,vector<int> &ns){
    for(int i = n-1;i>=0;i--){
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){s.pop();}
        ns.push_back(s.top());
        s.push(i);
    }
}

void prevsmaller(vector<int> v,stack<int> s,int st,vector<int> &ps){
    for(int i = 0;i<v.size();i++){
        int curr = v[i];  
        while(s.top() != -1 && v[s.top()] >= curr){s.pop();}
        ps.push_back(s.top());
        s.push(i);
    }
}
int histoarea(vector<int> arr){
     int n = arr.size();  
    vector<int> ns;
    stack<int> s;
    s.push(-1);
    nextsmaller(arr,s,n,ns);
    // for(auto i: ns){cout<<i<<" ";}cout<<endl;
    
    stack<int> p;
    p.push(-1);
    vector<int> ps;
    prevsmaller(arr,p,0,ps);
    // for(auto i: ps){cout<<i<<" ";}cout<<endl;
    int answ = 0;

    for(int i = 0;i<n;i++){
        int nsi = ns[n-i-1];
        if(nsi == -1){nsi = arr.size();}
        int width = nsi - ps[i] - 1;
        int area = arr[i]*width ;
        // cout<<area<<" ";
        answ = max(area,answ);
    }
    return answ;


}
int main(){
//     // ans -1 by me;
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> v;
//     for(int i = 0;i<n;i++){
//         vector<int> temp;
//         for(int j = 0;j<m;j++){
//             int a ;
//             cin>>a;
//             temp.push_back(a);
//         }
//         v.push_back(temp);
//     }
//     int c = 0,in = 0,ch = 0;
//     for(int i = 0;i<n;i++){
//         c = 0;
//         for(int j = 0;j<m;j++){
//             if(v[i][j] == 0 || i == j ){c++; }
//             else{break;}
//         }
//         if(c == m){in = i; ch = 1; break;}
//     }
    
//     if(ch == 1){
//         int d = 0;
//         for(int i = 0;i<n;i++){
//             if(v[i][in] == 1 || c == i){d++;}
//         }
//         if(d == n){return in;}
//         else{return -1;}
//     }
//     else{return -1;}
    
//     // ans -2 by me;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    for(int i = 0;i<n;i++){
        vector<int> temp;
        for(int j = 0;j<m;j++){
            int a ;
            cin>>a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }

    int maxarea = 0;
    vector<int > tem(m,0);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(v[i][j] == 0){tem[j] = 0;}
            else{
                tem[j] = v[i][j] + tem[j];
            }                   
        }
        int area = histoarea(tem);    
        cout<<area<<" ";                       
        maxarea = max(area,maxarea);
    }
    cout<<endl;
    
    cout<<maxarea<<endl;
}

// 4 4
// 0 1 1 0
// 1 1 1 1 
// 1 1 1 1 
// 1 1 0 0 