#include<bits/stdc++.h>
using namespace std;
// Q1; find the shortest distance in directed weighted acyclic graph; 
// hint : topological sort used;

class graph{
    public:
    unordered_map<int,list<pair<int,int>> > m;
    void insert(int u,int v,int cost,int dir){
        m[u].push_back({v,cost});
        if(dir == 0){m[v].push_back({u,cost});}
    }
    void print(){
        for(auto i:m){
            cout<<i.first<<" -> ";
            for(auto j:i.second){cout<<"[ "<<j.first<<" "<<j.second<<" "<<"],";}cout<<endl;
        } 
    }
    // shortest path using bfs;
    void shortest_path(int i,unordered_map<int,bool> &isvisited,stack<int> &ans){
        isvisited[i] = 1;
        for(auto i:m[i]){
            if(!isvisited[i.first]){shortest_path(i.first,isvisited,ans);}
        }
        ans.push(i);
    }

    void update_distance_array(vector<int> &dis,int source_node,stack<int> ans){
        dis[source_node] = 0;
        while(ans.size()){
            int top = ans.top();
            ans.pop();
            if(dis[top] != INT_MAX){
                for(auto j:m[top]){
                    int a = j.first, b = j.second;
                    if(dis[top] + b < dis[a]){dis[a] = dis[top] +  b;}
                }
            }
        }
        for(auto i: dis){cout<<i<<" ";}cout<<endl;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    graph g;
    for(int i = 0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        g.insert(u,v ,cost, 1);
    }
    g.print();

    unordered_map<int,bool> isvisited;
    stack<int> ans;                     
    g.shortest_path(0,isvisited,ans);   //stack<int> an = ans ; while(an.size()){cout<<an.top()<<" "; an.pop(); }cout<<endl;
    
    vector<int> dis(n,INT_MAX);
    int source_node;
    cin>>source_node;
    g.update_distance_array(dis,source_node,ans);
}

/*

6 9
0 1 5  0 2 3  1 2 2  1 3 6  2 3 7  2 4 4  2 5 2  3 4 -1  4 5 -2

*/