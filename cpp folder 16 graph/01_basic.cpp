// read summery and for code purpose going to file no. 001


#include<bits/stdc++.h>
using namespace std;
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

# Weighted graph:A graph where each edge is assigned a numerical value, called a weight.
# undirected graph : if weight is not given then we assume that the weight of each edge is equal to 1;
# directed graph : if weight is not given then we assume that the weight of each edge is equal to 1;
// node is a entity which store data and edge which is used to connecting a node;

# Path:A path is a sequence of vertices connected by edges. no vertices are repeated.
# Cyclic Graph: A graph that contains at least one cycle. A cycle is a path that starts and ends at the same vertex.
# Acyclic Graph:An acyclic graph is a graph that contains no cycles.
Ex: A tree is a perfect example of an undirected acyclic graph.
A Directed Acyclic Graph (DAG) is a directed graph with no directed cycles.
in directed graph atleast two node require two make cyclic graph, while in undirected graph atleast 3 node require;

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
 
template<typename T> 
class graph{
    public:
    // unordered_map<int,list<int>> m;
    map<T,list<T>> m;
    void insert(T u,T v,bool dir){
        // dir = 0 means undirected graph and dir = 1 means directed from u->v;
        m[u].push_back(v);
        if(dir == 0){m[v].push_back(u);}        
    }

    void print(vector<vector<T>> &vec){
        vector<int> v;
        for(auto i:m){
            cout<<i.first<<"-> "; 
            for(auto j:i.second){cout<<j<<", "; v.push_back(j);}
            cout<<endl;

            // sort(v.begin(),v.end());
            vec.push_back(v);
            v.clear();
        }
    }

    // bfs traversal;
    void bfs(int n,vector<vector<int>> vec, unordered_map<int,bool> &isvisited){
        queue<int> q;
        q.push(n);
        while(q.size()){
            int t = q.front();
            q.pop();
            if(isvisited[t] == 0){cout<<t<<" ";}
            isvisited[t] = 1;
            if(n > vec.size()){break;}
            for(int i = 0;i<vec[t].size();i++){
                if(isvisited[vec[t][i]] == 0){q.push(vec[t][i]);}
            }
        }
    }
    
    // dfs traversal;
    void dfs(int t,vector<vector<int>> vec, unordered_map<int,bool> &visited){
        if(visited[t] == 0){cout<<t<<" ";}
        visited[t] = 1;
        
        if(t <= vec.size()){ //for disconnected nodes;
            for(int i = 0;i<vec[t].size();i++){
                if(visited[vec[t][i]] == 0){dfs(vec[t][i],vec,visited);}
            }
        }
    }
};

int main(){
    int n,m;
    cout<<"enter no. of node(n)  and no. of edge(m)\n";
    cin>>n>>m;

    // graph<char> g; here we define template type char ;
    // graph g; for non-generic graph we define this type of graph;
    graph<int> g;
    // create undirected graph so that dir = 0;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.insert(u,v,0);
    }

    vector<vector<int>> vec;
    g.print(vec);  // yaha se vector of vector create ho gaya ;

    // BFS(breadth first search traversal) traversal;
    cout<<"\nBFS traversal\n";
    unordered_map<int,bool> isvisited;
    for(int i = 0;i<n;i++){
        g.bfs(i,vec,isvisited);
    }
        
    cout<<"\nDFS traversal\n";
    unordered_map<int,bool> visited;
    for(int i = 0;i<n;i++){
        g.dfs(i,vec,visited);
    }cout<<endl;
}
// 5 6 0 1 1 2 2 3 3 1 4 3 0 4

// for char input;
// 5 6 a b b c c d d b e d a e 