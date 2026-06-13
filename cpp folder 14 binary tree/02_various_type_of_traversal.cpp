// HW diagonal order traversal;
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<sort>

using namespace std;
/*
Q1: zig-zag traversal or spiral traversal;
Q2: Boundary traversal; 
Q3: vertical traversal; *** Very Good Question ***
Q4: Top view of a binary tree;
Q5: Bottom view of binary tree;
Q6: Left side view of binary tree; // hame isse aise assume karna hai ki root ka right mai joo part aa rha hai voo hamesha right mai rhega left vala part use overlap  nhi kr sakta;
Q7: Right side view of binary tree;
*/

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* root){
    int d;
    cin>>d;
    if(d == -1){return NULL;}
    root= new node(d);
    root ->left = buildtree(root->left);
    root ->right = buildtree(root->right);
    return root;
}
void lot(node* t){
    if(t == NULL){return ;}
    queue<node*> q;
    q.push(t);
    q.push(0);
    while(q.size() != 0){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){cout<<endl; if(q.size()){q.push(0);}}
        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }cout<<endl;
}

// ans 1 zigzag traversal;
void zigzag_traversal(node* root){
    if(root == NULL){return ;}
    queue<node*> q;
    q.push(root);
    q.push(0);
    bool ltr = true;
    vector<int> v;
    while(q.size() != 0){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            if(ltr == true){for(auto i:v){cout<<i<<" ";}}
            else{for(int i = v.size()-1;i>=0;i--){cout<<v[i]<<" ";}}
            cout<<endl;
            v.clear();
            ltr = !ltr;
            if(q.size()){q.push(0);}
        }
        else{
            v.push_back(temp->data);
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }          
    }cout<<endl;   
}     
void zigzag(node* root){
    if(root == NULL){return ;}
    queue<node*> q;
    q.push(root);
    bool ltr = true;
    
    while(q.size() != 0){
        int n = q.size();
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            node* temp = q.front();
            q.pop();
            int index = ltr ? i:n-1-i;
            ans[index] = temp->data;
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
        ltr = !ltr;
        for(auto i:ans){cout<<i<<" ";}cout<<endl;
    }cout<<endl;
}

// boundary traversal;
node* pln(node* temp,vector<int> &v){
    if(temp == nullptr){return nullptr;}
    pln(temp->left,v);
    pln(temp->right,v);
    if(temp->left == nullptr && temp->right == nullptr ){ v.push_back(temp->data);}
    return temp;
}

void bt(node* root,vector<int> &v){
    if(root == NULL){return ;}
    node* temp = root;
    if(temp->left){
         while(temp != NULL){
             if(temp ->right == nullptr && temp->left == nullptr){break;}
             v.push_back(temp->data);
             if(temp->left){temp = temp->left;}
             else{temp = temp->right;}
         }
    }else{v.push_back(temp->data);}
    temp = root;
    if(temp->left != NULL || temp->right != NULL){pln(root,v);}
    temp = root;
    if(temp->right){
           stack<int> s;
            while(temp != NULL){
            if(temp ->right == nullptr && temp->left == nullptr){break;}
            s.push(temp->data);
            if(temp->right){temp = temp->right;}
            else{temp = temp->left;}
    }
    while(s.size()){ v.push_back(s.top()); s.pop();}
    v.pop_back();
    }
}

void vt(node* temp, int c,int lvl, map<int,vector<pair<int,int>>> &m){
    if(temp == NULL){return ;}
    m[c].push_back({lvl,temp->data});
    if(temp->left){vt(temp->left,c-1,lvl+1,m);}
    if(temp->right){vt(temp->right,c+1,lvl+1,m);}
    return ;
}

void top_view(map<int,int> &m,node* root,int hd){
    if(root == NULL){return ;}
    queue<pair<node*,int>> q;
    q.push({root,hd});
    while(q.size()){
        node* temp = q.front().first;
        hd = q.front().second ;
        q.pop();
        if(m.find(hd) == m.end()){
              m[hd] = temp->data;
        }
        if(temp->left){q.push({temp->left,hd-1});}
        if(temp->right){q.push({temp->right,hd+1});}   
    }
}

void bottom_view(node* temp,map<int,int> &m,int hd){
     if(temp == NULL){return ;}
        queue<pair<node*,int>> q;
        q.push({temp,0});
        while(q.size()){
            node* temp = q.front().first;
            hd = q.front().second;
            q.pop();
            m[hd] = temp->data;
            if(temp->left){q.push({temp->left,hd-1});}
            if(temp->right){q.push({temp->right,hd+1});}
        }
}

void left_view(node* temp,vector<int> &m,int lvl){
    if(temp == NULL){return ;}
    if(m.size() == lvl){m.push_back(temp->data);}
    if(temp->left){left_view(temp->left,m,lvl+1);}
    if(temp->right){left_view(temp->right,m,lvl+1);}
    return ;
}

void r_view(node* temp,vector<int> &m,int lvl){
    if(temp == NULL){return ;}
    if(m.size() == lvl){m.push_back(temp->data);}
    if(temp->right){r_view(temp->right,m,lvl+1);}
    if(temp->left){r_view(temp->left,m,lvl+1);}
    return ;
}

// 0 1 -1 3 -1 5 -1 6 -1 -1 2 4 9 10 -1 -1 -1 -1 -1 
int main(){
    node* root = NULL;
    root = buildtree(root);
    cout<<endl<<"Level order traversal\n";
    lot(root); 
    // Zig-Zag traversal;
    cout<<"Print zigzag traversal \n";
    // zigzag_traversal(root);
    zigzag(root);
    
    // Boundary traversal;
    vector<int> v ;
    bt(root,v);
    cout<<"Boundary traversal"<<endl;
    for(int i:v){cout<<i<<" ";}cout<<endl<<endl;

    // vertical traversal;
    cout<<"vertical traversal\n";
    int c = 0;
    map<int,vector<pair<int,int>>> m;
    vt (root,c,0,m);
    for(auto &p : m){
        stable_sort(p.second.begin(),p.second.end(), [](auto &a, auto &b){ return a.first < b.first; });
        // sort(p.second.begin(), p.second.end()); 
        // isse pair ka first element same raheta too pair k second element k according sort hoo jata 
        // or ye hum nhi chahete issliye stable sort ka use kiya hai;
        for(auto i : p.second){cout<<i.second<<" ";}
        cout<<endl;
    }

    // bottom and top view ko ham easily lot se kr sakte hai;
     // Top view of binary tree;
    cout<<endl<<"Top view of binary tree;\n";
    map<int ,int> tv;
    top_view(tv,root,0);
    for(auto i: tv){
        cout<<i.second<<" ";
    }cout<<endl;

     // Bottom view of binary tree;
    cout<<endl<<"Bottom view of binary tree;\n";
    map<int,int> n;
    bottom_view(root,n,0);
    for(auto &i: n){
        cout<<i.second<<" ";
    }cout<<endl;

     // Left view of binary tree;
    cout<<endl<<"Left view of binary tree;\n";
    vector<int>lv;
    left_view(root,lv,0);
    for(auto i: lv){
        cout<<i<<" ";
    }cout<<endl;

     // right view of binary tree;
    cout<<endl<<"right view of binary tree;\n";
    vector<int> rv;
    r_view(root,rv,0);
    for(auto i: rv){
        cout<<i<<" ";
    }cout<<endl;
}
// 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1 

// 38 9 5 2 -1 -1 1 -1 -1 3 -1 -1   10 4 4 -1 -1 -1 1  0 -1 -1 1 -1 -1 

// 1 3 5 -1 9 4 8 -1 -1 -1 6 -1 -1 7 -1 -1 5 3 -1 -1 2 9 6 -1 -1 7 -1 -1 -1

// especially for vertical traversal;
// 1 2 3 -1 -1 4 7 8 9 -1 -1 -1 8 -1 -1 -1   5 6 -1 -1 9 11 12 -1 -1 10 -1 -1 13 -1 -1

// left view of binary tree;
// 1 2 3 -1 -1 4 7 8 9 -1 -1 -1 18 -1 -1 -1   5 6 -1 -1 19 11 15 -1 -1 13 -1 16  17 -1 -1 18 -1 -1  10 -1 -1 