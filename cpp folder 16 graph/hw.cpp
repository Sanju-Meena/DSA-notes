#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> &ans,vector<int> adj[],int node,vector<bool> &isvisited){
    queue<int> q;
    q.push(node);
    isvisited[node] = 1;
    ans.push_back(node);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto i: adj[temp]){
            if(!isvisited[i]){
                q.push(i);
                isvisited[i] =1;
                ans.push_back(i);
            }
        }

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    vector<bool> isvisited(n+1,0);
    for(int i = 0;i<n;i++){
        if(!isvisited[i]) bfs(ans,adj,i,isvisited);
    }
    for(auto i: ans)cout<<i<<" ";
    cout<<endl;

}
// 5 6 0 1 1 2 2 3 3 1 4 3 0 4
