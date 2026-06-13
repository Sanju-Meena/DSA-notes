#include<bits/stdc++.h>
using namespace std;

void bfs_Tra(int node, vector<bool> &isvisited,vector<int> adj[],vector<int> &ans){
    queue<int> q;
    q.push(node);
    ans.push_back(node);
    isvisited[node] = 1;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i: adj[temp]){
            if(!isvisited[i]){
                q.push(i);
                ans.push_back(i);
                isvisited[i] = 1;
            }
        }
    }   
}


void dfs_Tra(int node, vector<bool> &isvisited,vector<int> adj[],vector<int> &ans){
    isvisited[node] = 1;
    ans.push_back(node);
        for(int i: adj[node]){
            if(!isvisited[i]){
                dfs_Tra(i,isvisited,adj,ans);
            }
        }

}
// 5 6 0 1 1 2 2 3 3 1 4 3 0 4

int main(){
    int n, m;
    cin>>n>>m;
    // adjacency matrix for graph representation;
    // int arr[n+1][m+1]; // 1 base indexing;

    // for(int j = 0;j<m;j++){
    //     int u , v;
    //     cin>>u>>v;
    //     arr[u][v] = 1; // if weight given than put weight if not than put 1;
    //     arr[u][v] = 1;
    // }
    // // SC = n^2;
    // we cannot use this bcz most of the place remain empty or it store zero in it ;

    // We use Adjacency list for graph representation ;
    vector<int> adj[n+1];
    // fixed size array of vector have grow and shrink while pushing element in list;
    for(int j = 0;j<m;j++){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v); // if weight given than make vector<pair<int,int>> vec[n+1];
        adj[v].push_back(u);
    }
    // sc = V + E;
    // if directed graph than sc = E;

    // BFS traversal ;
    vector<int> ans;
    vector<bool> isvisited(n+1,0);
    for(int i = 0;i<n;i++){
        if(isvisited[i] == 0){bfs_Tra(i,isvisited,adj,ans);}
    }
    for(auto i: ans)cout<<i<<" ";
    
    // dfs traversal;
    ans.clear(); cout<<endl; 
    isvisited.assign(n+1, 0);

    for(int i = 0;i<n;i++){
        if(isvisited[i] == 0){dfs_Tra(i,isvisited,adj,ans);}
    }
   for(auto i: ans)cout<<i<<" ";
    ans.clear(); cout<<endl;
    



}