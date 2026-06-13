#include<bits/stdc++.h>
using namespace std;
// make graph , do bfs and dfs traversal and check cycle present in undirected graph using bfs and dfs;

class graph{
    public:
    unordered_map<int,list<int>> m;

    void insert(int u, int v,int dir){
        m[u].push_back(v);
        if(dir == 0){m[v].push_back(u);}
    }

    void print(){
        for(auto i:m){
            cout<<i.first<<" -> ";
            for(auto j:i.second){cout<<j<<" ";}cout<<endl;
        }
    }

    void bfs(int n,unordered_map<int,bool> &isvisited){
        queue<int> q;
        q.push(n);
        isvisited[n] = 1;
        while(q.size()){
            int t = q.front();
            q.pop();
            cout<<t<<" "; 
            for(auto i:m[t]){
                if(isvisited[i] == 0){ isvisited[i] = 1; q.push(i);}
            }
        }
    }

    void dfs(int n,unordered_map<int,bool> &isvisited){
        if(isvisited[n] == 0){cout<<n<<" "; isvisited[n] = 1;
            for(auto i:m[n]){
                if(isvisited[i] == 0){dfs(i,isvisited);}
            }
        }
    }
 
    bool cycle_using_bfs(int n,unordered_map<int,bool> &isvisited,unordered_map<int,int> &pa){
        queue<int> q;
        q.push(n);
        isvisited[n] = 1;
        while(q.size()){
            int t = q.front();
            q.pop();
            for(auto i:m[t]){
                if(isvisited[i] == 0){
                    isvisited[i] = 1;
                    q.push(i);
                    pa[i] = t;
                }else{
                    if(i != pa[t]){return 1;}
                }
            }
        }
        return 0;
    }
 
    bool cycle_using_dfs(int n,unordered_map<int,bool> &isvisited,unordered_map<int,int> &pa){
        isvisited[n] = 1;
        for(auto i:m[n]){
            if(isvisited[i] == 0){
                isvisited[i] = 1;
                pa[i] = n;
                bool ch = cycle_using_dfs(i,isvisited,pa);
                if(ch == 1){return 1;}
            }else{
                if(i != pa[n]){return 1;}
            }
        }
        return 0;
    }
};

int main(){
    graph g;
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.insert(u,v,0);
    }
    
    unordered_map<int,bool> isvisited;
    for(int i = 0;i<n;i++){
        if(isvisited[i] == 0){g.bfs(i,isvisited);}
    }cout<<endl;
    
    unordered_map<int,bool> visited;
    for(int i = 0;i<n;i++){
        if(visited[i] == 0){g.dfs(i,visited);}
    }cout<<endl;

    unordered_map<int,bool> visit;
    unordered_map<int,int> pa;
    bool ch = 0 ;
    for(int i = 0;i<n;i++){
        pa[i] = -1;
        if(visit[i] == 0){
            ch = g.cycle_using_bfs(i,visit,pa);
            if(ch == 1){break;}
        }
    }cout<<endl;
    cout<<ch<<" ";
    
    unordered_map<int,bool> vis;
    unordered_map<int,int> par;
    bool che = 0 ;
    for(int i = 0;i<n;i++){
        par[i] = -1;
        if(vis[i] == 0){
            che = g.cycle_using_dfs(i,vis,par);
            if(che == 1){break;}
        }
    }cout<<endl;
    cout<<"che  = "<<che<<endl;
}
// 8 8 0 1 1 2 3 4 4 5 5 6 6 7 7 3 4 6

// 5 4 0 1 0 2 0 3 3 4