#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>

using namespace std;
//  Morris traversal in a binary search tree;
// flat a bst and make a linked list whose left pointer point 
// null and right point on next element and don't use any data structure;
class node{
    public:
    int data;
    node* left ;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->left = NULL;
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
void lot(node* temp){
    queue<node*> q;
    q.push(temp);
    q.push(0);
    while(q.size()){
        temp = q.front();
        q.pop();
        if(temp == NULL){cout<<endl; if(q.size()){q.push(0);}}
        else{cout<<temp->data<<" ";
             if(temp->left){q.push(temp->left);}
             if(temp->right){q.push(temp->right);}
            }
    }cout<<endl;
}

void in(node* root){
    if(root == 0){return ;}
    if(root->left){in(root->left);}
    cout<<root->data<<" ";
    if(root->right){in(root->right);}
}

node* findpred(node* curr){
    node* temp = curr->left;
    while(temp->right != NULL && temp->right != curr)temp = temp->right;
    return temp;
}
void morris_traversal(node* root){
    if(root == 0){return ;}
    node *curr = root , *pre = NULL;
    while(curr != NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            pre = findpred(curr);
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }else{
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}


int main(){
    // morris traversal;
    node* root = NULL;
    root = buildtree(root);
    lot(root);
    in(root);cout<<endl;
    morris_traversal(root);cout<<endl;

    // flat a tree into a linked list and don't use any data structure;
    node* curr = root,*pred = NULL;
    while(root != NULL){
        if(root->left != NULL){
            pred = findpred(root);
            pred->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
            root = root->right;
    }

    while(curr){cout<<curr->data<<" "; curr = curr->right;}
}

// 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1