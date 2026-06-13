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
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int findparent(vector<int> &pa,int node){
    if(pa[node] == node){return node;}
     return pa[node] = findparent(pa,pa[node]);
}
// int findparent(vector<int> &pa,int node){
//     if(pa[node] == node){return node;}
//     int ans = findparent(pa,pa[node]);
//     pa[node] = ans;
//     return ans;
// }

void make_union(int u,int v,vector<int> &pa,vector<int> &rank){
    if(rank[u] > rank[v]){pa[v] = u ; }
    else if(rank[u] < rank[v]){pa[u] = v ; } 
    else {pa[v] = u; rank[u]++;}
}

int main(){
    int V,m;
    cin>>V>>m;
    vector<vector<int>> edges;
    for(int i = 0;i<m;i++){
        int pare,node,dis;
        cin>>pare>>node>>dis;
        vector<int> vt;
        vt.push_back(pare);
        vt.push_back(node);
        vt.push_back(dis);
        edges.push_back(vt);
        vt.clear();
    }
    sort(edges.begin(),edges.end(),cmp);
    
     vector<int> pa;
        for(int i = 0;i<V;i++){
            pa.push_back(i) ;
        }
        vector<int> rank(V, 0);
        
        int cost = 0;
        
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int we = edges[i][2];
            
            int pu = findparent(pa,u);
            int pv = findparent(pa,v);
            if(pu != pv){
                make_union(pu,pv,pa,rank);
                cost+=we;
            }
        }
        
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