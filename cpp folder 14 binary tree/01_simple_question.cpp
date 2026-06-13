#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>
using namespace std;
/*
// EASY QUESTIONS;
Q1: Find height of tree ?(height of tree is the farthest node from root;)
Q2: Find diameter of tree? (longest path btw any two node)
Q3: Find tree is balanced or not?
(difference btw height of left and right subtree is not more than one for all nodes of tree;)
Q4: Check tree is identical or not?
Q5: Check tree is sum tree or not?
(Every node is the sum of all the left nodes and all the right nodes in a tree except leaf node;)
*/

class node{
    public:
    int data ;
    node* left;
    node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* tree){
    int d;
    cin>>d;
    if(d == -1){return NULL;}
    tree = new node(d);
    tree->left = buildtree(tree->left);
    tree->right = buildtree(tree->right);
    return tree;
}
void lot(node* root){
    queue<node*> q;
    q.push(root);
    q.push(0);
    while(q.size()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(q.size()){q.push(0);}
        }else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
}

int leafnode(node* root){
    queue<node*> q;
    q.push(root);
    int c = 0;
    while(q.size()){
        node* temp = q.front();
        q.pop();
        if(temp->right == NULL && temp->left == NULL){c++;}
        else{
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
    return c;
    }
/*Solution of question 1*/
int sirhot(node* root){
    node* temp = root;
    if(temp == NULL){return 0;}
    int left = sirhot(temp->left);
    int right = sirhot(temp->right);
    int ans = max(left,right) + 1;
    return ans;      
}

// ans 2;
int diameter(node* root,int &ans){
    node* temp = root;
    if(temp == NULL){ return 0;}
    int left = diameter(temp->left,ans);
    int right = diameter(temp->right,ans);
    int sum = left + right +1  ;
    ans = max(sum,ans)  ;
    return max(left,right) + 1;   
}

// answer of 3rd question:
pair<int, bool> balanced_tree(node* temp){
    pair<int,bool> p = {0,1};
    if(temp == NULL){return p ;}
    pair<int , bool> left = balanced_tree(temp->left);
    if(left.second == false){return p;}
    pair<int, bool> right = balanced_tree(temp->right);
    if(right.second == false){return p;}

    int diff = abs (right.first - left.first);
    int sum =  max(left.first,right.first) + 1;       
    if(diff > 1){return p = {sum,false};}
    else{return p = {sum,true};}
}

// answer of 4th question;
bool identical(node* t,node* r){
    if(t == NULL && r == NULL){return true;}             
    if(t == NULL || r == NULL){return false;}
    if(t->data != r->data){return false;}                
    
    bool c = identical(t->left,r->left);                 
    if(c == false){return false;}                            
    bool che = identical(t->right,r->right);             
    if(che == false){return false;}                      
    return true;    
}

// answer of 5th question;
pair<int,bool> sum_tree(node* root){
    pair<int,bool> p = {0,true} ;
    if(root == NULL){return p;}
    if(root->left == NULL && root->right == NULL){p.first = root->data; return p;}
    pair<int,bool> l = sum_tree(root->left);
    if(l.second == false){return l;}
    pair<int,bool> r = sum_tree(root->right);
    if(r.second == false){return r;}

    if(root->data == p.first + l.first + r.first ){
        p.first = 2*root->data ;  cout<<" "<<p.first<<endl;
    }
    else{p.second = false;}
    return p;
}


int main(){
    node* root = NULL;
    root = buildtree(root);
    lot(root);
    
    int count_leafnode = leafnode(root);
    cout<<"No. of leaf node in the tree is "<<count_leafnode<<".\n";
    // q1: find height?
    int hei = sirhot(root);
    cout<<"The height of tree is "<<hei<<".\n";
    
    // Q2: find diameter??
    int answ = 0;
    diameter(root,answ);
    cout<<"The diameter or width of tree is "<<answ<<".\n";

    // Q3:Check tree is balanced or not??
    pair<int,bool> p = balanced_tree(root);
    if(p.second == true){cout<<"Tree is balanced.\n";}
    else{cout<<"Tree is not balanced.\n";}
    
    // Q4: Check tree is identical or not?
    // node* tree = NULL;
    // tree = buildtree(tree);
    // lot(tree); 
    // lot(root);   
    // bool ch = identical(tree,root);
    // if(ch == true){cout<<"Identical\n";}
    // else{cout<<"Not identical\n";}
    
    // Q5: Check tree is sum tree or not?
    pair<int,bool> che = sum_tree(root);
    if(che.second == true){cout<<"Tree is sum tree;\n";}
    else{cout<<"Tree is not sum tree;\n";}
}
// for question no. 1
// 1 3 7 -1 -1 11 -1 -1 5 17 19 -1 -1 -1 20 -1 -1 

// for question no. 2;
// 1 2 3 4 -1 -1 5 6 7 -1 -1 8 -1 -1 -1 9 -1 10 13 -1 -1 11 -1 12 -1 -1 14 -1 15 -1 -1
// 1 2 3 4 -1 -1 5 -1 -1  9 -1 10 13 -1 -1 -1 15 16 -1 -1 17 -1 -1

// for question no. 3;
// 1 2 -1 -1 3 -1 -1

// for question no. 5;
// 38 9 3 2 -1 -1 1 -1 -1 3 -1 -1   10 4 4 -1 -1 -1 1  0 -1 -1 1 -1 -1 