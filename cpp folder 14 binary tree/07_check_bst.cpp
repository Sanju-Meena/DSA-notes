#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>

using namespace std;
/*
Q1; check the tree is valid bst; good question in leet code bcz LLONG_INTMIN and LLONG_INTMAX use karna pada;
Q2: find kth smallest element;
//  for Q3: in gfg we they also give approx answer if key is not present;
Q3: ***** find predesessor and successor of a tree assuming key is present?? **Medium**
Q4: find lca of two nodes;  **easy** by property;
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

node* buildtree(node* root, int d){
    if(root == NULL){ node* temp = new node(d); return temp;}
    if(root->data > d){root->left = buildtree(root->left,d);}
    if(root->data < d){root->right = buildtree(root->right,d);}
    return root;
}

node* buildbst(node* &root){
    int d;
    cin>>d;
    while(d != -1){
        root = buildtree(root,d);
        cin>>d;
    }
    return root;
}

void lot(node* temp){
    queue<node*> q;
    if(temp == NULL){return ;}
    q.push(temp);
    q.push(0);
    while(q.size()){
        temp = q.front();
        q.pop();
        if(temp == NULL){cout<<endl; if(q.size()){q.push(0);}}
        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }cout<<endl;
}


// Q1: check valid bst by me;
bool isvalid(node* root,long long &a){
    if(root == NULL){return 1;}
    bool l = isvalid(root->left,a);
    if(a < root->data && l == true){a = root->data;}
    else{return false;}
    bool r = isvalid(root->right,a);
    return r;
}
// by sir;
bool isvalidbst(node* root,long long min,long long max){
    if(root == NULL){return 1;}
    if(root->data <= min || root->data >= max){return false;}
    bool ch = isvalidbst(root->left,min,root->data);
    bool che = isvalidbst(root->right,root->data,max);
    return ch & che; 
}

// kth small element;
int answ(node* root, int k, int &i){
        if(root == NULL){return -1;}
        int l = answ(root->left,k,i);
        if( l != -1){return l;}
        i++;
        if(i == k){return root->data;}
        int r = answ(root->right,k,i); 
        return r;
 }

//  in gfg we they also give approx answer if k is not present;
//  predesessor and successor of a tree assuming key is present;
pair<int,int> pands(node* root,int k){
    int pre = -1;
    int suc = -1;
    while(root->data != k){
        if(root->data > k){
            suc = root->data;
            root = root->left;
        }else{
            pre = root->data;
            root = root->right;
        }
    }
    node* pred = root->left;
    while(pred != NULL){
        pre = pred->data;
        pred = pred->right;
    }

    node* sucs = root->right;
    while(sucs != NULL){
        suc = sucs->data;
        sucs = sucs->left;
    }

    pair<int,int> p = {pre,suc} ;
    return p;
    
}

void findpands(node* root,int k,node* &pred,node* &succ){
    if(root == NULL){return ;}
    node* nod = NULL;
    while(root != NULL){
        if(root->data == k){nod = root; break;}
        else if(root->data > k){ succ = root; root = root->left; }
        else{pred = root; root = root->right;}
    }
    if(nod == NULL){return ;}
    
    if(nod -> left != NULL){pred = nod->left;
     while(pred->right != NULL){pred = pred->right;}
    }
    if(nod->right != NULL){ succ = nod ->right;
     while(succ->left != NULL){succ = succ->left;}
    }
}

void ps(node* root,int k,node* &pred,node* &succ,node* prev,bool &ch ){
    if(ch){succ = root; return ;}
    if(root == NULL){return ;}
    ps(root->left,k,pred,succ,root,ch);
    if(ch)return ;
    if(root->data == k){
        pred = prev;
        ch == true;
    }
    ps(root->right,k,pred,succ,root,ch);

}


int main(){
    node* root = NULL;
    buildbst(root);
    lot(root);
    // check valid bst;
    cout<<isvalidbst(root,LLONG_MIN,LLONG_MAX)<<endl;
    long long z = LLONG_MIN;
    cout<<isvalid(root, z)<<endl;


    // find kth samllest element;
    int i = 0,k = 3;
    cout<< answ( root, k,i) <<endl;

    // find predesessor and successor of a tree?
    pair<int ,int> p = pands(root,k);
    cout<<p.first<<" "<<p.second<<endl;
    // by me;
    node* pred = NULL;
    node* succ = NULL;
    node* prev = NULL;
    int key = 4;
    findpands(root,key,pred,succ);
    cout<<pred->data<<" "<<succ->data<<" ";
    // method second;
    bool ch = false;
    ps(root,key,pred,succ,prev,ch);

    
    // lca of two nodes ;
    int a = 3,b = 6;
    while(root != NULL){
        if(root->data > a && root->data > b){root = root->left;}
        else if(root->data < a && root->data < b){root = root->right;}
        else{cout<<root->data<<endl; break;}
    }

}
// input is = 10 8 9 21 7 27 25  24 26 5 6 4 3 30 -1