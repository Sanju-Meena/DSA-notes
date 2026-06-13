#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
// Q1: check in a tree, where sum of two nodes value is equal to target value or not;
// Q2; flat the tree and preapare a linklist which is sorted;
// Q3: ****normal bst convert into balance bst;
// Q4: ***make bst from preorder;
// Q5: merge 2 bst and make one bst;

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

node* buildbst(node* &root,int d){
    if(root == NULL){root = new node(d); return root;}
    if(root->data > d){root->left = buildbst(root->left,d);}
    if(root->data < d){root->right = buildbst(root->right,d);}
    return root;
}

void takedata(node* &root){
    int d;
    cin>>d;
    while(d != -1){
        root = buildbst(root,d);
        cin>>d;
    }
}

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
    }cout<<endl;
}

void in(node* root){
    if(root == NULL){return ;}
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}


void inorder(node* root,vector<int> &v){
    if(root == NULL){return ;}
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

// node* balancedbst(node* &root,int d){  
//     root->left = new node(d);
//     return root->left;
    
// }

node* takein(vector<int> v,node* root,int s,int e){
    if(s>e){return NULL;}
    int mid = (s+e)/2;
    root = new node(v[mid]);
    root->left = takein(v,root->left,s,mid-1);
    root->right = takein(v,root->right,mid+1,e);
    return root;
}

node* designtree(node* root,int v[],int min,int max,int &s,int e){
    if(s > e){return NULL;}
    cout<<v[s]<<" ";
    if(v[s] > min && v[s] < max){root = new node(v[s++]);}
    else return NULL;
    root->left = designtree(root->left,v,min,root->data,s,e);
    root->right = designtree(root->right,v,root->data,max,s,e);
    return root;
}

node* makebst(node* root,vector<int> v,int s,int e){
    if(s>e){return NULL;}
    int mid = (s + e)/2;
    root = new node(v[mid]);
    root->left = makebst(root->left,v,s,mid-1);
    root->right = makebst(root->right,v,mid+1,e);
    return root;
}

void flat(node* &root){
    
}

int main(){
    node* root = NULL;
    takedata(root);
    lot(root);
    
    // // Q1: 2sum in bst;
    vector<int> v;
    // inorder(root,v);
    // int tar; cin>>tar;
    // int i = 0,j = v.size()-1,ch = 0;
    // while(i<j){
    //     if( v[i] + v[j] == tar){cout<<v[i]<<" "<<v[j]<<" present\n"; ch = 1; break;}
    //     else if( v[i] + v[j] < tar){i++;}
    //     else{j--;}
    // } 
    // if(ch == 0){cout<<"Absent\n";}

    // // flat the tree and preapare a linklist which is sorted;
    // node* head = NULL;
    // node* tail = NULL;
    // for(int i = 0;i<v.size();i++){
    //     if(head == NULL){head = new node(v[i]); tail = head;}
    //     else{tail->right = new node(v[i]);
    //     tail = tail->right;}
    // }
    // node* temp = NULL;
    // temp = head;
    // while(temp != NULL){cout<<temp->data<<" "; temp = temp->right;} cout<<endl;

    // // normal bst ko convert karo balanced bst mai;
    // node* tree = NULL;
    // tree = takein(v,tree,0,v.size()-1);
    // lot(tree);

    // make bst from preorder;
    cout<<"ans 4\n";
    int preord[11] = {20,10,5,15,13,18,16,19,35,30,42};
    node* tree = NULL;
    int s = 0;
    tree = designtree(tree,preord,INT_MIN,INT_MAX,s,10);
    cout<<endl;
    lot(tree);

    // merge 2 bst make 1 bst;
    v.clear();
    in(root);cout<<endl;
    in(tree);cout<<endl;
    inorder(root,v);
    inorder(tree,v);
    sort(v.begin(),v.end());
    for(int i:v){cout<<i<<" ";}cout<<endl;
    node* newroot = makebst(newroot,v,0,v.size()-1);
    lot(newroot);

    // method second;
    flat(root);



    

}

// input is = 11 8 9 21 7 27 25  24 26 6 4 3 33 -1