/*  ***Graph**
defin: Graph is a type of non-linear data structure which is a combination of nodes and edges;
Type of graph:
1. Directed graph;
2. Undirected graph;
3. Disconnected graph : in this graph, atleast one or more than one node is not connected to any edge;

Degree: 
1. for undirected graph:- no. of edges that are originate at nodes and end at other node;
// If you add a self-loop to a node, the degree of that node increases by 2.
2. for Directed graph;
🎯Indegree: Think of it as the number of "incoming" arrows.
🎯 Outdegree: Think of it as the number of "outgoing" arrows.
A self-loop contributes to both: In directed graphs: indegree and outdegree both increases by 1;
** total degree = 2 * no. of edges in a graph;

# Weighted graph:A graph where each edge is assigned a numerical value, called a weight.
# undirected graph & directed graph : if weight is not given then we assume that the weight of each edge is 1;
// node is a entity which store data and edge which is used to connecting a node;

# Path:A path is a sequence of vertices connected by edges. no vertices & edges are repeated.
# Cyclic Graph: A graph that contains at least one cycle. A cycle is a path that starts and ends at the same vertex.
# Acyclic Graph:An acyclic graph is a graph that contains no cycles.
Ex: A tree is a perfect example of an undirected acyclic graph.
A Directed Acyclic Graph (DAG) is a directed graph with no directed cycles.
in directed graph atleast two node require two make cyclic graph if self loop is excluded,
 while in undirected graph atleast 3 node require;

**For graph representation we have two method;
#1 Adjacency Matrix: It is a square VxV square matrix used to represent a graph.
The cell matrix[i][j] stores information about the edge between vertex i and vertex j.
For unweighted graphs: matrix[i][j] = 1 if an edge exists, otherwise 0.
For weighted graphs: matrix[i][j] = weight if an edge exists, and 0 or infinity if it doesn't.
Space Complexity: O(n^2) This is because it always uses a V x V matrix.
Time Complexity: O(1), You just look up matrix[i][j].

#2: Adjacency List: A list represents a graph as an array of lists.The index i correspond to vertex i,
and the list at that index stores all the vertices that i is connected to.
Example: If A is connected to B and C, the list for A would be [B, C].
Space Complexity: O(V + E) This is because you store one entry for each vertex (V) and one entry for each edge (E).
Time Complexity :Check for edge (i, j): O(k), K is the number of neighbors of vertex i.In the worst case, this is O(V).

*/
   

#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

void bfs_Tra(int node, vector<bool> &isvisited,vector<vector<int> > adj,vector<int> &ans){
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


void dfs_Tra(int node, vector<bool> &isvisited,vector<vector<int> > adj,vector<int> &ans){
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
    vector<vector<int>> vec(n+1, vector<int>(m+1,0)); // 1 base indexing;

    for(int j = 0;j<m;j++){
        int u , v;
        cin>>u>>v;
        vec[u][v] = 1; // if weight given than put weight if not than put 1;
        vec[v][u] = 1;
    }
    // TC = O(n);
    // SC = n^2;
    // we cannot use this bcz most of the place remain empty or it store zero in it ;

    // We use Adjacency list for graph representation ;
    vector<vector<int> > adj(n+1);
    // vector<int> adj[n+1]; //work in GCC compiler not in vs code compiler;
    // fixed size array of vector have grow and shrink while pushing element in list;
    for(int j = 0;j<m;j++){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v); // if weight given than make vector<pair<int,int>> vec[n+1];
        adj[v].push_back(u);
    }
    // sc = 2*E;for undirected graph;
    // if directed graph than sc = E; bcz we store one edge only;

    // BFS traversal ;
    vector<int> ans;
    vector<bool> isvisited(n+1,0);
    for(int i = 0;i<n;i++){
        if(isvisited[i] == 0){bfs_Tra(i,isvisited,adj,ans);}
    }
    for(auto i: ans)cout<<i<<" ";
    
    // dfs traversal;
    ans.clear();
    cout<<endl; 
    isvisited.assign(n+1, 0);

    for(int i = 0;i<n;i++){
        if(isvisited[i] == 0){dfs_Tra(i,isvisited,adj,ans);}
    }
   for(auto i: ans)cout<<i<<" ";
   ans.clear(); 
   cout<<endl;
// TC = O(n) + 2*E(summation of no. of degree;)
// SC = O(n) + O(n); 
}