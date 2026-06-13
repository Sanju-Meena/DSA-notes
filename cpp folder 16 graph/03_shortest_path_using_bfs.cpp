#include<bits/stdc++.h>
using namespace std;
// Q1; shortest path in undirected graph;  hint: with the help of parent mapping;

class graph{
    public:
    unordered_map<int,list<int>> m;
    void insert(int u,int v,int dir){
        m[u].push_back(v);
        if(dir == 1){m[v].push_back(u);}
    }
    void print(){
        for(auto i:m){
            cout<<i.first<<" -> ";
            for(auto j:i.second){cout<<j<<" ";}cout<<endl;
        } 
    }
    // shortest path using bfs;
    void shortest_path(int i,unordered_map<int,int> &pa,unordered_map<int,bool> &isvisited){
        queue<int> q;
        q.push(i);
        isvisited[i] = 1;
        while(q.size()){
            int t = q.front();
            q.pop();
            for(auto i:m[t]){if(!isvisited[i]){q.push(i); isvisited[i] = 1; pa[i] = t;}}
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    graph g;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.insert(u,v , 0);
    }
    g.print();

    unordered_map<int,int> pa;
    unordered_map<int,bool> isvisited;
    for(int i = 1;i<+n;i++){
        pa[i] = -1;
        g.shortest_path(i,pa,isvisited);
    }
    int s, e;
    cin>>s >> e;
    stack<int> st;
    st.push(e);
    while(pa[e] != -1){st.push(pa[e]); e = pa[e];}
    st.push(s);
    while(st.size()){cout<<st.top()<<" "; st.pop();}   
}
/*
8 9
1 2 1 3 1 4 2 5 3 8 4 6 6 7 7 8 5 8
1 8
*/

