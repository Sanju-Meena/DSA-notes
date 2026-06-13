#include<bits/stdc++.h>
using namespace std;
// CHECK BRIDGE PRESENT :
//  Bridge-> In a graph , it is an edge if we remove edge,then the graph increases it's connected component;
// it is an edge,if we remove it than the graph divided into two graph(that are disconnected);

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
        } cout<<endl;
    }
    void dfs(int node,unordered_map<int,bool> &isvisited,int pa,vector<int> &low,vector<int> &disc,vector<vector<int>> &v,int timer){
        isvisited[node] = 1;
        low[node] = timer;
        disc[node] = timer;
        timer++;

        for(auto neighbour:m[node]){
            if(neighbour == pa){continue;}
            if(!isvisited[neighbour]){
                dfs(neighbour,isvisited,node,low,disc,v,timer);
                low[node] = min(low[node],low[neighbour]);
                // to check bridge;
                if(low[neighbour] > disc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(neighbour);
                    v.push_back(ans);
                }
            }
            
            else{
                // backedge;
                low[node] = min(low[node],disc[neighbour]);
            }
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
        g.insert(u,v,1);
    }
    g.print();

    unordered_map<int,bool> isvisited;
    int pa = -1;
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    int timer = 0;
    vector<vector<int>> v;
    
    for(int i = 0;i<n;i++){
        if(isvisited[i] == 0){g.dfs(i,isvisited,pa,low,disc,v,timer);}
    }
    for(auto i:v){
        for(auto j:i){cout<<j<<" ";}cout<<endl;
    }

}
/*

10 11
0 1  1 2  2 3 2 4  3 4  4 5  5 7  5 6  8 6  8 7  9 8

*/