/* ****** TREE ******
Tree is a non-linear datastructure consist of nodes, where each node stores data and links to the child nodes;
1. binary tee having 2 or less than 2 children ;
2. N-ary Tree : each node can have N children;
3. leaf node -> node that have 0 children;
4. Siblings -> having same parent;
*/

// HW: 1 to print reverse level order traversal;
// HW: 2 to print in, pre, and post order using loop;

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

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
    root = new node(d);
    if(d == -1){return NULL;}
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);
    return root;
}

void lot(node* root){
    queue<node*> q;
    q.push(root);
    q.push(0); // insert separator; 

    while(q.size() != 0){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(q.size() != 0){q.push(0);}
        }
        else{ 
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
}

void inorder(node* root){ //LNR
    if(root == NULL){return ;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){ //NLR
    if(root == 0){return ;}
    cout<<root->data<<" ";
    if(root->left != 0){preorder(root->left);}
    if(root->right != 0){preorder(root->right);}
}

void pastorder(node* root){ //LRN
    if(root == 0){return ;}
    if(root->left != 0){pastorder(root->left);}
    if(root->right != 0){pastorder(root->right);}
    cout<<root->data<<" ";
}

node* buildtree_from_lot(node* tree){
    int d;
    cin>>d;
    if(d == -1){return NULL;}
    tree = new node(d);
    queue<node*> q;
    q.push(tree);
    while(q.size() != 0){
        node *temp = q.front();
        q.pop();
        if(temp == NULL){;}
        else{
            int a,b;
            cout<<"Enter data of left node of "<<temp->data<<" : ";
            cin>>a;
            if(a != -1){temp->left = new node(a); q.push(temp->left);}
            cout<<"Enter data of right node of "<<temp->data<<" : ";
            cin>>b;
            if(b != -1){temp->right = new node(b); q.push(temp->right);}
        }
        
    }
    return tree;
    
}


int main(){
    node* root = NULL;
    cout<<"Enter data of tree : ";
    root = buildtree(root);
    cout<<"sizeof node is "<<sizeof(node)<<endl;
    cout<<"size of node* is "<<sizeof(node*)<<endl;
    cout<<"size of root->data is "<<sizeof(root->data)<<endl;
    cout<<"size of root->left is " <<sizeof(root->left)<<endl;
    cout<<"size of root->right is " << sizeof(root->right)<<endl;
    // 1 3 7 -1 -1 11 -1 -1 5 17 19 -1 -1 -1 20 -1 -1 
    // 1 2 3 4 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1 9 10 12 -1 -1 13 -1 -1 11 14 -1 -1 15 -1 -1
    // Level Order Traversal is a way to visit all nodes of a binary tree level by level, from top to bottom- 
    // and left to right within each level.
    lot(root);
    /*  lot is 1 3 5 7 11 17 -1.    
    ***Three type of traversal;
    Preorder: 1,3,7,11,5,17(NLR)
    Inorder:  7,3,11,1,17,5(LNR)
    Postorder: 7,11,3,17,5,1(LRN)
    */
    
    cout<<endl<<"Print tree in inorder way\n";
    inorder(root); 
    cout<<endl<<"\nPrint tree in preorder way\n";
    preorder(root); cout<<endl<<endl;
    cout<<"Print tree in pastorder way\n";
    pastorder(root);cout<<endl<<endl;
    

    // from level order traversal build tree;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1  
    node* tree = NULL;
    cout<<"Enter data of tree node : ";
    tree = buildtree_from_lot(tree);
    cout<<endl;
    lot(tree);
    
}