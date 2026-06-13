#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>

using namespace std;
// bst insertion ;
// bst mai find min and max vlaue;
// bst deletion;

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

void lot(node* temp){
    queue<node*> q;
    q.push(temp);
    q.push(0);
    while(q.size()){
        temp= q.front();
        q.pop();
        if(temp == NULL){cout<<endl; if(q.size()){q.push(0);}}
        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
}

/* Even if you pass a pointer by value, you're passing a copy of the pointer—but that pointer still 
   points to the same memory as the original node! So you can modify the contents of the node 
   (like its left and right child), and those changes will refelect outside the function  but original pointer cannot change. */
node* sirbuildbst(node* &root,int &d){
    if(root == NULL){
        root = new node(d);
        return root;
    }
    if(root->data > d){root->left = sirbuildbst(root->left,d);}
    else{root->right = sirbuildbst(root->right,d);}
    return root;
}

void takeinput(node* &root){
    int t;
    cout<<"Enter data:\n";
    cin>>t;
    while(t != -1){
        root = sirbuildbst(root,t);
        cin>>t;        
    }
}

void in(node* root){
    if(root == NULL){return ;}
    if(root->left){in(root->left);}
    cout<<root->data<<" ";
    if(root->right){in(root->right);}
}

void preor(node* root){
    if(root == NULL){return ;}
    cout<<root->data<<" ";
    if(root->left){preor(root->left);}
    if(root->right){preor(root->right);}
}

void postor(node* root){
    if(root == NULL){return ;}
    if(root->left){postor(root->left);}
    if(root->right){postor(root->right);}
    cout<<root->data<<" ";
}

bool ispresent(node* root,int k){
    while(root != NULL){
        cout<<root->data<<" ";
        if(root->data > k){root = root->left;}
        else if(root->data < k){root = root->right;}
        else{return true;}
    }
    return false;
}
node* minvalue(node* temp){
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

node* deletion(node* root,int k){
    if(root == NULL){return root;}
    if(root->data == k){
        // 0 child
        if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
        }
        // 1 child
        if(root->right == NULL && root->left != NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        
        // 2 child
        if(root->left != NULL && root->right != NULL){
            node* pred = minvalue(root->right) ;
            root->data = pred->data;
            root->right = deletion(root->right,pred->data);
            return root;
        }

    }
    else if(root->data > k){root->left = deletion(root->left,k);}
    else if(root->data < k){root->right = deletion(root->right,k);}
    return root;
}

int main(){
    node* root = NULL;
    takeinput(root);
    lot(root);
    in(root); cout<<endl;
    preor(root); cout<<endl;
    postor(root);cout<<endl;
    int ele;
    cin>>ele;
    bool ch = ispresent(root,ele);
    if(ch == 1){cout<<"Present hai;\n";}
    else{cout<<"Present nahi hai;\n";}
    // inorder mai sorted order mai print hua hai;
    // INORDER PREDECESSOR-> It’s the node that appears just before the current node during an inorder traversal.
    // INORDER SUCCESSOR-> It’s the node that appears just after the current node during an inorder traversal.
    
    // deletion of a node in a tree;
    int t = 10 ;
    while(t--){
        int dn;
        cin>>dn;
        root = deletion(root,dn);
        in(root); cout<<endl;
    }
}
// input is = 10 8 9 21 7 27 25  24 26 5 6 4 3 30 -1