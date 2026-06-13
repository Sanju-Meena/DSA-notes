#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>

using namespace std;
/*
Q1: print reverse lot;
Q2: do all three traversal using loop; ****very good question****
Q3: make tree from lot;
Q4: count leaf node:
// various traversal lec hw
01: print tree in diagonal order way; also done in gfg;
*/

/* solution hint;
1; store in stack while traversal lo and store first right and then left and after that print s.top();
2; pre: two while loop used, use stack store all left node including root node and prit s.top and after go temp k right portion pr, (2nd while loop mai condition hai s.size() != 0  || temp != nullptr);
3; post: stack used for store node in lot way and vector used for store ans in opposite order of postorder;
*/
class node{
    public:
    int data;
    node* left;
    node* right ;
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
    root = new node(d);
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);
    return root;    
}

void lot(node* root){
    queue<node*> q;
    if(root == NULL){return ;}
    q.push(root);
    q.push(NULL);
    while(q.size()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){cout<<endl; if(q.size()){q.push(NULL);}}
        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
    cout<<endl;
}

void reverse_lot(node* root){
    stack<node*> s;
    queue<node*> q;
    if(root == NULL){return ;}
    q.push(root);
    q.push(NULL);
    while(q.size()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){ if(q.size()){q.push(NULL); s.push(NULL);}}
        else{
            s.push(temp);
            if(temp->right){q.push(temp->right);}
            if(temp->left){q.push(temp->left);}
        }
    }
    while(s.size()){
        if(s.top()){cout<<s.top()->data<<" ";}
        else{cout<<endl;}
        s.pop();
    }cout<<endl<<endl;
}

void pre(node* temp){if(temp == NULL){return;}
    cout<<temp->data<<" ";    pre(temp->left);     pre(temp->right); }

void in(node* temp){if(temp == NULL){return;}
     in(temp->left); cout<<temp->data<<" "; in(temp->right);  }

void post(node* temp){if(temp == NULL){return;}
    post(temp->left);  post(temp->right); cout<<temp->data<<" "; }

void l_pre(node* root){
    stack<node*> s;
    s.push(root);
    while(s.size()){
        node* temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right){s.push(temp->right);}
        if(temp->left){s.push(temp->left);}

    }cout<<endl;
}


void l_in(node* root) {
    stack<node*> s;
    node* temp = root;
    while (temp != nullptr || !s.empty()) {
        while (temp != nullptr) {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

void l_post(node* root){
    if(root == NULL){return ;}
    stack<node*> s;
    s.push(root);
    stack<int> v;
    while(s.size()){
        node* temp = s.top();
        s.pop();
        v.push(temp->data);
        if(temp->left){s.push(temp->left);}
        if(temp->right){s.push(temp->right);}
    }
    while(v.size()){cout<<v.top()<<" "; v.pop();}
}

// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1  
void build_tree_from_lot(node* &temp){
    int d;
    cin>>d;
    if( d == -1){return ;}
    temp = new node(d);
    queue<node*> q;
    q.push(temp);
    while(q.size()){
        node* temp = q.front();
        q.pop();
        cin>>d;
        if(d != -1){
            temp->left = new node(d);
            q.push(temp->left);
        }
        cin>>d;
        if(d != -1){
            temp->right = new node(d);
            q.push(temp->right);
        }   
    }
}

int cln(node* temp,int &c){
    if(temp == NULL){return c;}
    cln(temp->left,c);
    cln(temp->right,c);
    if(temp->left == nullptr && temp->right == nullptr){c++;}
    return c;    
}

void dt(node* root,map<int, vector<int>> &m,int lvl){
    if(root == NULL){return ;}
    m[lvl].push_back(root->data);
    dt(root->left,m,lvl+1);
    dt(root->right,m,lvl);
}


int main(){
    node* root = NULL;
    root = buildtree(root);
    lot(root);
    pre(root) ; cout<<endl;
    in(root);   cout<<endl;
    post(root); cout<<endl<<endl;
    // q1 start;
    reverse_lot(root);

    // q2 start;
    l_pre(root);
    l_in(root);
    l_post(root);

    // Q3 start;
    node* tree = NULL;
    build_tree_from_lot(tree);
    lot(tree);
    
    // Q4 start;
    int ans = 0;
    cln(tree,ans);
    cout<<ans<<endl;

    // diagonal order print;
    int lvl = 0;
    map<int,vector<int>> m;
    dt(root,m,lvl);
    vector<int> v;
    for(auto i: m){
        for(auto j:i.second){
            cout<<j<<" ";
        }
    }
}

//  1 3 7 -1 -1 11 -1 -1 5 17 19 -1 -1 -1 20 -1 -1 
// for q3 ;
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1  