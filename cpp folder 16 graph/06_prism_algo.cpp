#include<bits/stdc++.h>
using namespace std;
/* PRISM ALGORITHM: To find the minimum spanning tree;
   spanning tree: It is a subset of a graph that includes all the vertices of the original graph,
    connected together with the minimum possible number of edges, without forming any cycles.

    Key Properties:
    If a graph has V vertices, a spanning tree for that graph must satisfy these conditions:
    1.Vertices: It must contain all V vertices.
    2. Edges: It must contain exactly V - 1 edges.
    3. Connectivity: It must be connected to every node, and not have any cycles.  
*/


int main(){
    int V,m;
    cin>>V>>m;
    vector<vector<pair<int,int>>> vec(V);
    for(int i = 0;i<m;i++){
        int pare,node,dis;
        cin>>pare>>node>>dis;
        vec[pare].push_back({node,dis});
        vec[node].push_back({pare,dis});
    }
    
    unordered_map<int,bool> isvisited;
    unordered_map<int,int> pa;
    vector<int> dis(V,INT_MAX);
    set<pair<int,int>> s;
    pa[0] = -1;
    dis[0] = 0;
    s.insert({0,0});
    
    while(s.size()){
        
        auto it = s.begin();
        int top = it->second;
        s.erase(it);
        if(isvisited[top]) continue;
        isvisited[top] = 1;
        
        for(auto i:vec[top]){
            if(isvisited[i.first] == false && dis[i.first] > i.second){
                if(dis[i.first] != INT_MAX){
                        s.erase({dis[i.first], i.first});
                    }
                    pa[i.first] = top;
                    dis[i.first] =  i.second;
                    s.insert({i.second,i.first});
                }
            }
            
        }
        
        int cost = 0;
        for(int i = 1;i<V;i++){cost+=dis[i];}
        cout<<cost<<" ";
}
/*
5 6
0 1 2
0 3 6 
1 3 8
1 4 5 
1 2 3 
2 4 7

*/