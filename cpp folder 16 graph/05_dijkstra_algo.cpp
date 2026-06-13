#include<bits/stdc++.h>
using namespace std;
// find the shortest distance btw source node to every node;
// IMP NOTE: Not valid for negative weight only;

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
            for(auto j:i.second){
                cout<<"[ "<<j.first<<" ,"<<j.second<<" ],";
            }cout<<endl;
        } 
    }

    void update_dis_vector(int sn, vector<int> &dis){
        dis[sn] = 0;
        set<pair<int,int>> s;
        // s.insert({node_dis, node});
        s.insert({0,sn});
        while(s.size() != 0){
            auto pa = s.begin();
            s.erase(pa);
            int node_dis = (*pa).first;
            int node = pa->second;
            for(auto i:m[node]){
                if(dis[node] + i.second < dis[i.first]){
                    // imp logic given below in 3 line;
                    if (dis[i.first] != INT_MAX) {
                        s.erase({dis[i.first], i.first});
                    }
                    dis[i.first] = dis[node] + i.second;
                    s.insert({dis[i.first],i.first});
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
        int u, v,cost;
        cin>>u>>v>>cost;
        g.insert(u,v,cost,0);
    }
    g.print();

    vector<int> dis(n,INT_MAX);
    int sn;
    cin>>sn;
    g.update_dis_vector(sn,dis);
}
/*
4 5 
0 1 5  0 2 8  1 3 2  2 3 6  2 1 9

*/