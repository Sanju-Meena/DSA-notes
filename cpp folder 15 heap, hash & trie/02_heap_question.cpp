
// Q1: find kth smallest element in an array using heap property;
// Q2: *****check binary tree is max heap or not; ******
// Q3: Minimum cost of ropes;
// Q4: Convert bst to min heap;
// Q5: Find kth largest sum of a subarray;
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>
using namespace std;

class node{
    public :
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
void lot(node* root,vector<int> &v){
    if(root == NULL){return ;}
    queue<node*> q;
    q.push(root);
    while(q.size()){
        node* temp = q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left){q.push(temp->left);}
        if(temp->right){q.push(temp->right);}
    }
}

bool checkmaxheap(vector<int> v,node* root){
    if(root == NULL)return true;
    queue<node*> q;
    q.push(root);
    int n = v.size() -1;
    for(int i = 1;i<=n/2;i++){
        node* temp = q.front();
        q.pop();
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
        
        if(i<n){
            int l = 2*i,r = l+1;
            if((n >= l && temp->left != NULL) || (n<l && temp->left == NULL)){
                if(n>=l){if(v[i] < v[l])return false;}
            }
            else return false;
          
            if((n >= r && temp->right != NULL) || (n<r && temp->right == NULL)){
                if(n>=r ){if(v[i] < v[r])return false; }
            }
            else return false;  
        }
        else return false;
    }   
    return true;
}

// by iscbt and max heap;
int countnode(node* root){
    if(root == NULL){return 0;}
    return countnode(root->left) +  countnode(root->right) + 1;
}

bool iscbt(node* root,int in,int tc){
    if(root == NULL)return 1;
    if(in >= tc){return 0;}
    else{
        bool l = iscbt(root->left,2*in + 1,tc);
        bool r = iscbt(root->right,2*in + 2,tc);
        return r & l;
    }
}
bool ismaxheap(node* root,int tc){
    if(root == NULL)return true;
    if(root->left == NULL && root->right == NULL)return true;
    else if(root->right == NULL){return (root->data > root->left->data);}
    else{
        bool l = ismaxheap(root->left,tc);
        bool r = ismaxheap(root->right,tc);
        return r && l && (root->data > root->left->data) && (root->data > root->right->data);
    }
}

void inorder(vector<int> &vec , node* t){
    if(t == NULL)return ;
    inorder(vec,t->left);
    vec.push_back(t->data);
    inorder(vec,t->right);
}

void changebst(vector<int> v, node* &t){
    if(t == NULL)return ;
    queue<node*> q;
    q.push(t);
    int i = 0;
    while(q.size()){
        node* temp = q.front();
        q.pop();
        temp->data = v[i++];
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }

}

void printpre(node* t){
    if(t == NULL)return ;
    cout<<t->data<<" ";
    printpre(t->left);
    printpre(t->right);
}

int main(){
    // kth smallest element using heap;
    vector<int> v = {7, 10, 4, 3, 20, 15};
    int k = 3 ;
    priority_queue<int> pq;
    for(int i = 0;i<k;i++){
        pq.push(v[i]);
    }
    for(int i = k;i<v.size();i++){
        if(pq.top() > v[i]){pq.pop(); pq.push(v[i]);}
    }
    cout<<"\nKth smallest element is "<<pq.top()<<endl;

    // is binary tree is max heap;
    // by me;
    node* root = NULL;
    root = buildtree(root);
    v.clear();
    v.push_back(-1);
    lot(root,v);
    bool ch = checkmaxheap(v,root);
    if(ch == 1){cout<<"Binary tree is max heap\n\n";}
    else{cout<<"Binary tree is not max heap\n\n";}

    // by sir; this method is good because it does'nt take any space and it is efficient;
    node* tree = root;
    // tree = buildtree(tree);
    int tc = countnode(tree);
    bool ans = iscbt(root,0,tc) && ismaxheap(root,tc);
    if(ans == 1){cout<<"Binary tree is max heap\n\n";}
    else{cout<<"Binary tree is not max heap\n\n";}   

    // minimum cost of ropes;
    vector<int> vec = {4,3,2,6};
    priority_queue<int,vector<int> , greater<int> > p;
    for(int i = 0;i<vec.size();i++){
        p.push(vec[i]);
    }
    int answ = 0;
    while(p.size() != 1){
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        answ = answ + a + b;
        p.push(a+b);

    }
    cout<<"ans = "<<answ<<endl;

    // convert bst to min heap;
    node* t = tree;
    // t = buildtree(t);
    vec.clear();
    inorder(vec,t);
    changebst(vec,t);
    printpre(t);
    cout<<endl;

    // kth largest sum of a subarray;
    int kth = 3;
    // cin>>kth;
    priority_queue<int,vector<int> , greater<int> > prq;
    vector<int> arr = {2,6,4,1};
    for(int i = 0;i<arr.size();i++){
        int sum = 0;
        for(int j = i;j<arr.size();j++){
            sum +=arr[j];
            if(prq.size() < kth){prq.push(sum);}
            else{
                if(prq.top() < sum){prq.pop(); prq.push(sum);}
            }
        }
    }
    cout<<prq.top()<<endl;

}
// 91 46 12 6 -1 -1 9 -1 -1 3 -1 -1 37 7 -1 -1 31 -1 -1

// 97 46 12 -1 -1 3 2  -1 -1 4 -1 -1 37 7 -1 -1 31 -1 -1

// for question to convert bst to min heap;
// 50 25 10 -1 -1 35 -1 -1 100 75 -1 -1 120 -1 -1