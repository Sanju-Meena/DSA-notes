#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>
using namespace std;
/*
Q1: Maximum sum of longest path btw root and leaf node?
// for second question we assume that both node is present or both is absent??
Q2: Lowest common ancester of given two nodes ??
Q3: Find k sum path ??
Q4: Find kth ancestor of node ??
Q5: Maximum sum of non-adjacent nodes ??
*/
class node{
    public:
    int data;
    node* left ;
    node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* temp){
    int d;
    cin>>d;
    if(d == -1){return NULL;}
    temp = new node(d);
    temp->left = buildtree(temp->left);
    temp->right = buildtree(temp->right);
    return temp;
}

void lot(node* temp){
    if(temp == NULL){return ;}
    queue<node*> q;
    q.push(temp);
    q.push(0);
    while(q.size()){
        node* tem = q.front();
        q.pop();
        if(tem == NULL){cout<<endl;if(q.size()){q.push(0);}}
        else{
            cout<<tem->data<<" ";
            if(tem->left){q.push(tem->left);}
            if(tem->right){q.push(tem->right);}
        }
    }
}                        

pair<int,int> max_sum(node* temp,int sum,int l,pair<int,int> &pa){
    pair<int,int> p ;
    if(temp == NULL){return p ={l,sum} ;}
    sum = sum + temp->data;

    pair<int,int> la = max_sum(temp->left,sum,l+1,pa);
    if(pa.first == la.first){pa.second = max(la.second,pa.second);}
    else if(pa.first < la.first){pa = la;}
    
    pair<int,int> ra = max_sum(temp->right,sum,l+1,pa);
    if(pa.first == ra.first){pa.second = max(ra.second,pa.second);}
    else if(pa.first < ra.first){pa = ra;}
    
    // cout<<pa.first<<" "<<pa.second<<" Hello"<<endl;
    // 3 9 -1 -1 9 6 -1 -1 2 -1 -1
    return pa;
}

void max_sum_by_sir(node* temp,int sum,int l,int &maxsum ,int &maxlen){
    pair<int,int> p ;
    if(temp == NULL){
        if(l > maxlen){maxsum = sum; maxlen = l;}
        if(l == maxlen){maxsum = max(maxsum,sum);}
        return;
    }
    sum = sum + temp->data;
    max_sum_by_sir(temp->left,sum,l+1,maxsum,maxlen);
    max_sum_by_sir(temp->right,sum,l+1,maxsum,maxlen);
    
    // cout<<maxlen<<" "<<maxsum<<endl;
    // 3 9 -1 -1 9 6 -1 -1 2 -1 -1
}

// ans 2;
int f_c_e(vector<int> v,vector<int> v1){
    for(int i = v.size()-1;i>=0;i--){
        for(int j = v1.size()-1;j>=0;j--){
            if(v[i] == v1[j]){return v[i];}
        }
    }
    return -1;
    }
// this code give right answer in every case;
int lca(vector<int> &q1,vector<int> &q2,node* temp,int a,int b,bool &ch1,bool &ch2,int &ans){
    if(temp == NULL){return 0;}
    if(ch1 == 0){q1.push_back(temp->data);}
    if(ch2 == 0){q2.push_back(temp->data);}
    if(a == temp->data){ch1 = true;}
    if(b == temp->data){ch2 = true;}
    if(ch1 == 1 && ch2 == 1){ans = f_c_e(q1,q2); return ans;}
    
    
    if(temp->left){lca(q1,q2,temp->left,a,b,ch1,ch2,ans);}
    if(ch1 == 1 && ch2 ==1){return ans;}
    if(temp->right){lca(q1,q2,temp->right,a,b,ch1,ch2,ans);}
    if(ch1 == 1 && ch2 ==1){return ans;}

    if(ch2 == 0){q2.pop_back();}
    if(ch1 == 0){q1.pop_back();}
    return ans;
}

// sir code give right answer when both node present or both are absent;
node* sir_lca(node* temp,int n1,int n2){
    if(temp == NULL){return NULL;}
    if(temp->data == n1 || temp->data == n2){return temp;}
    node* la = sir_lca(temp->left,n1,n2);
    node* ra = sir_lca(temp->right,n1,n2);
    if(la != NULL && ra != NULL){return temp;}
    if(la == NULL && ra != NULL){return ra;}
    if(la != NULL && ra == NULL){return la;}
    else return NULL;
}

// for k sum path;
void count_sum_check(vector<int> &v,int k ,int &c){
    int sum = 0;
    for(int i = v.size()-1;i>=0;i--){
        sum = sum + v[i];
        if(sum == k){c++;}
    }
}
void sum_path(node* temp,int k,int &c,vector<int> &v){

    if(temp == NULL){return; }
    v.push_back(temp->data);
    // cout<<temp->data<<" ";
    count_sum_check(v,k,c);
    if(temp->left){sum_path(temp->left,k,c,v);}
    if(temp->right){sum_path(temp->right,k,c,v);}
    v.pop_back();
    
}

// ans 4 find kth ancestor;
void find_kth_ances(node* temp,int &k,int n,node* &ances,int &c){
    if(temp == NULL){return ;}
    // cout<<temp->data<<" ";
    if(temp->data == n){c = 1; return ;}

    if(temp->left){find_kth_ances(temp->left,k,n,ances,c);}
    if(c != 0 ){ k--; if(k == 0){ances = temp;} return ;}
    if(temp->right){find_kth_ances(temp->right,k,n,ances,c);}
    if(c != 0 ){ k--; if(k == 0){ances = temp;} return ;}
    return ;
}

// adjacent nodes sum;
pair<int,int> adjacent_node_sum(node* temp,pair<int,int> &p){
    pair<int,int> pa = {0,0};
    if(temp == NULL){return pa;}
    // pair<include,exclude> p;
    pair<int,int> l = adjacent_node_sum(temp->left,p);
    pair<int,int> r = adjacent_node_sum(temp->right,p);
    p.first = temp->data + l.second + r.second;
    p.second = max(l.first,l.second) + max(r.first,r.second);
    return p;

}


int main(){
    node* root = NULL;
    root = buildtree(root);
    lot(root);
    cout<<endl;
    // Q1; Max sum btw root and leaf node??
    int a = 0,l = 0;
    pair<int,int> pa = {l,a} ;
    max_sum(root,0,0,pa);
    cout<<"Max sum in longest path is "<<pa.second<<endl;
    // by sir
    int maxsum = 0,maxlen = 0;
    max_sum_by_sir(root,0,0,maxsum,maxlen);
    cout<<"Max sum in longest path is "<<maxsum<<endl<<endl;
    // pair<maxlen,maxsum> lekr gfg pr bhi solution uplabdh hai;

    // ans 2 LCA of 2 node;
    int n1 = 2 ,n2 = 5, ans = -1;
    bool ch1 = 0,ch2 = 0;
    cout<<"Enter 2 nodes\n";
    vector<int> q1,q2;
    lca(q1,q2,root,n1,n2,ch1,ch2,ans); 
    if(ans == -1){cout<<"No common ancestor exist\n";}
    else{cout<<"Common ancestor is "<<ans<<endl;}
    
    node* answ = sir_lca(root,n1,n2); //space complexity good ;
    if(answ == NULL){cout<<"No common ancestor exist\n";}
    else{cout<<"Common ancestor is "<<answ->data<<endl<<endl;}

    // ans 3 for k sum path;
    int k = 0,c = 0;
    // cin>>k;
    vector<int>v ;
    sum_path(root,k,c,v);
    cout<<"Path of k sum is "<<c<<endl;
    
    // ans 4 for kth ancestor of a node;
    // M-1: store all ancestor of given node and find answer;
    // int t;  cin>>t; while(t--){
        int n ;
        // cin>>n>>k;
        n = 2,k = 1;
        node* ances = NULL;
        c = 0;
        find_kth_ances(root,k,n,ances,c);
        if(k <= 0 && ances != NULL){cout<<"\nKth ancestor is "<<ances->data<<endl;}
        else{cout<<"\nKth ancestor is not present\n";}
    // }
    
    // ans 5 of Maximum sum of non-adjacent nodes .
    pair<int,int> p = {0,0} ;
    adjacent_node_sum(root,p);
    int mxsum = max(p.first,p.second);
    cout<<"Maximum sum of adjacent nodes is "<<mxsum<<endl;
    




    
    }
    // 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1 
// for lca;
// 1 2 3 -1 -1 4 7 8 9 -1 -1 -1 18 -1 -1 -1   5 6 -1 -1 19 11 12 -1 -1 -1 10 -1 -1 
// for k sum path;
// 1 2 1 1 -1 5 -1 -1 2 -1 -1 -1 3 4 -1 -1 1 3 1 -1 -1 -1 1 1 -1 -1 2 -1 -1
// for max sum of adjacent nodes.
// 1 3 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 2 6 -1 -1 7 12 -1 -1 13 -1 -1
