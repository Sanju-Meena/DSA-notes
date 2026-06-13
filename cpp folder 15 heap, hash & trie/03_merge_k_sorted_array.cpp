#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>
using namespace std;
// Q. Given n array you have to merge all array and print an array that are sorted (you don't take space more than o(n) while using any data str.)
// same question for linklist (leetcode pr solution dala hai);

class  node{
    public:
    int data;
    int i;
    int j;
    node(int d,int a,int b){
        this->data = d;
        this->i = a;
        this->j = b;
    }
};

class cmp{
    public:
    bool operator()(node* c, node* d){
        return c->data > d->data ;  
    }
};

int main(){
    vector<vector<int>> mat;
    vector<int> v1 = {1,3,5,7};    mat.push_back(v1) ;
    vector<int> v2 = {2,4,6,8};    mat.push_back(v2) ;
    vector<int> v3 = {0,9,10,11};  mat.push_back(v3) ;

    // make priority queue and it take node having data, row no. and column no. ;
    priority_queue<node*,vector<node*>,cmp> p;
    for(int i = 0;i<mat.size();i++){
        node* temp = new node(mat[i][0],i,0);
        p.push(temp);
    }

    // delete element of nth row and push if next element exist ;
    vector<int>v;
    while(p.size() > 0){
        node* temp = p.top();
        v.push_back(temp->data);
        p.pop();
        
        int i = temp->i;
        int j = temp->j;
        
        if(mat[i].size() - 1  > j ){
            node* kemp = new node(mat[i][j+1],i,j+1) ;
            p.push(kemp);
        }
    }
    
    for(auto i:v){cout<<i<<" ";} cout<<endl;
}