#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>

using namespace std;
// Q1; make a tree from the given array of inorder and preorder;
// Q2; make a tree from the given array of inorder and postorder;
// Q3: Minimum time to burn a tree??

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int v){
        this->data = v;
        this->left = NULL;
        this->right = NULL;
    }
};

node* maketree(node* root){
    int d;
    cin>>d;
    if(d == -1){return NULL;}
    root = new node(d);
    root->left = maketree(root->left);
    root->right = maketree(root->right);
    return root;
}

void lot(node* root){
    if(root == NULL){return ;}
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
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
    cout<<endl;
}                        

void post(node* root){
    if(root == NULL){return ;}
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}

node* buildtree(node* root,int in[],int pre[],int s,int e,int &k){
    if(s>e ){return NULL;}
    int index = 0;
    for(int i = s;i<=e;i++){
        if(pre[k] == in[i] ){index = i; break;}
    }
    
    root = new node(pre[k]);
    k++;
    root->left = buildtree(root->left,in,pre,s,index-1,k);
    root->right = buildtree(root->right,in,pre,index+1,e,k);
    return root;
}

node* build(node* root,int in[],int post[],int s,int e,int &k){
    if(s>e ){return NULL;}
    int index = 0;
    for(int i = s;i<=e;i++){
        if(post[k] == in[i] ){index = i; break;}
    }
    // cout<<post[k]<<" ";
    root = new node(post[k--]);
    root->right = build(root->right,in,post,index+1,e,k);
    root->left = build(root->left,in,post,s,index-1,k);
    return root;
}

// Minimum time to burn a tree:

int mt(node* root,int t){
    if(root == NULL){return 0;}
    map<node*,node*> m;
    m[root] = NULL;
    queue<node*> fq;
    fq.push(root);
    node* fd_n = NULL;
    // child ko parent se link kiya;
    while(fq.size()){
        node* temp = fq.front();
        fq.pop();
        cout<<temp->data<<" ";
        if(temp->data == t){fd_n = temp;}
        if(temp->left){fq.push(temp->left); m[temp->left] = temp;}
        if(temp->right){fq.push(temp->right);m[temp->right] = temp;}
    }cout<<endl;

    map<node*,bool> ma ;
    ma[fd_n] = true;
    queue<node*> q;
    q.push(fd_n);
    int time = 0;
    while(q.size()){
        // node* temp = q.front();
        // q.pop();
        int size = q.size();
        // cout<<temp->data<<" ";
        bool flag = 0;
        for(int i = 0;i<size;i++){
            node* temp = q.front();
            q.pop();
            if(temp->left){ if(ma.find(temp->left) == ma.end()){flag = 1; ma[temp->left] = true; q.push(temp->left);} }
            if(temp->right){ if(ma.find(temp->right) == ma.end()){flag = 1; ma[temp->right] = true; q.push(temp->right);} }
            node* pa = m[temp] ;
            if(pa){if(ma.find(pa) == ma.end()){flag = 1; ma[pa] = true; q.push(pa);} }
        }
        if(flag == 1){time++;}
    }
    cout<<endl;
    return time;
}

int main(){
    // int in[8] = {7,3,11,1,19,17,5,20};
    // int pre[8] = {1,3,7,11,5,17,19,20};
    // node* root = NULL;
    // int k = 0;
    // root = buildtree(root,in,pre,0,7,k);
    // post(root); cout<<endl;
    // lot(root);
    
    // int post[8] = {7,11,3,19,17,20,5,1};
    // k = 7;
    // node* tree = NULL;
    // tree = build(tree,in,post,0,7,k);
    // lot(tree); 

    // Minimum time to burn a tree:
    node* ro = maketree(ro);
    lot(ro);
    int target = 1;
    int time = mt(ro,target);
    cout<<"Minimum time to burn tree from node value "<<target <<" is "<<time<<endl;
//    1 2 3 4 5 -1 -1 -1 -1 -1 -1


}