#include<bits/stdc++.h>
using namespace std;
/*
Q1; cycle detection in directed graph using dfs;
Q2; topological sort print; 
Topological Sort is a linear ordering of vertices in a Directed Acyclic Graph (DAG).
#RULE: For every directed edge from vertex u to vertex v, vertex u must come before vertex v in the ordering.
Q3; cycle detection using kahns algorithm;

*/

class graph{
    public:
    map<int,list<int>> m;
    void insert(int u,int v,int dir){
        m[u].push_back(v);
        if(dir == 0){m[v].push_back(u);}
    }
    
    void print(){
        for(auto i:m){
            cout<<i.first<<" -> ";
            for(auto j : i.second){cout<<j<<" ";}  cout<<endl;
        }cout<<endl;
    }

    // solution using dfs;
    bool dfs( unordered_map<int,bool> &isvisited,int n,unordered_map<int,bool> &dfscall){
            isvisited[n] = 1;
            dfscall[n] = 1;
            for(auto i:m[n]){
                if(isvisited[i] == 0){
                    bool flag = dfs(isvisited,i,dfscall);
                    if(flag == 1){return 1;}
                }else{
                    if(dfscall[i] == 1){return true;}
                }
            }
            dfscall[n] = 0;
            return 0;
    }

    // solution of topological sort using dfs;
    void topo_sort( unordered_map<int,bool> &isvisited,int n,stack<int> &s){
            isvisited[n] = 1;
            for(auto i:m[n]){
                if(isvisited[i] == 0){topo_sort(isvisited,i,s);}
            }
            s.push(n);
    }

    // find topological order using  khans algo;
    void topo_using_kahns(int n){
        unordered_map<int,int> ind;
        for(auto i:m){
            for(auto j:i.second){ind[j]++;}
        }

        stack<int> s;
        for(int i = 0;i<n;i++){
            if(ind[i] == 0){s.push(i);}
        }
        while(s.size()){
            int t = s.top();
            s.pop();
            cout<<t<<" ";
            for(auto i:m[t]){ind[i]--; if(ind[i] == 0){s.push(i);}}
        }
    }

    // cycle detection using  khans algo;
    int iscycle_present(int n){
        unordered_map<int,int> ind;
        for(auto i:m){
            for(auto j:i.second){ind[j]++;}
        }
        int count = 0;
        stack<int> s;
        for(int i = 0;i<n;i++){
            if(ind[i] == 0){s.push(i);}
        }
        while(s.size()){
            int t = s.top();
            s.pop();
            count++;
            for(auto i:m[t]){ind[i]--; if(ind[i] == 0){s.push(i);}}
        }
        return count;
    }
    

};

int main(){
    graph g;
    int n,m;
    cin>>n>>m;
    unordered_map<int,list<int>> vec;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
        g.insert(u,v,1);
    }
    g.print();

    // solution 1st using dfs;
    unordered_map<int,bool> isvisite;
    unordered_map<int,bool> dfscall;
    bool fla = 0 ;
     for(int i = 0;i<n;i++){
            if(isvisite[i] == 0){
                fla = g.dfs(isvisite,i,dfscall);
                if(fla == 1){break;}
            }
    }
    if(fla == 1){cout<<"cycle is present\n";}
    else{cout<<"cycle is not present\n";}

    // find valid topological sort;
    stack<int> s;
    unordered_map<int,bool> isvisited;
     for(int i = 0;i<n;i++){
            if(isvisited[i] == 0){
                g.topo_sort(isvisited,i,s);
            }
    }
    while(s.size()){cout<<s.top()<<" "; s.pop();}cout<<endl;


    // find topological sort using kahn's algo;
    g.topo_using_kahns(n);
    cout<<endl;

    // cycle detection using khan's algo;
    int count = g.iscycle_present(n);
    if(count == n){cout<<"NO cycle present;\n";}
    else{cout<<"Cycle present\n";}
}

/*
9 10   0 1  1 2  2 4  4 5  5 6  6 4  2 3  3 7  3 8  8 7
// for 2nd question;
4 3 0 1 2 1 2 3

// for 3rd;
5 5 0 1 0 2 1 4 2 4 4 3

*/