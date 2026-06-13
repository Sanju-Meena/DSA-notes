#include<iostream>
using namespace std;
// Question 1: reversr a linklist ; 
// ip = 1 2 3 4 5 0;
// op = 5 4 3 2 1 ;

// Question 2: find the middle node of linklist: if list have 4 no. of list then no. 3 is the middle for 4 node 
class node{
    public: 
    int d;
    node* next;
    node(int data){
        this->d = data;
        this->next = NULL;
    }
    ~node(){
        int value = this->d;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for "<<value<<endl;
    }
};

void insert(node* &head,node *&tail ,int d){
    node* temp = tail;
    if(d != 0){
        node* fix = new node(d);
        temp->next = fix;
        tail = fix;
    }
}

void print(node* &head){
    node* temp = head;
    if(head == NULL){cout<<"No node is present\n";}
    else{
        cout<<"Printing the node data :-"<<endl;
        while(temp->next != NULL){
            cout<<temp->d<<" ";
            temp = temp->next;
        }
        cout<<temp->d<<endl;
    }
}

// iterative solution; 
void reverse(node *&head){
    if(head->next == NULL){cout<<"Reverse is same as previous one."<<endl;}
    else{
        node* temp = head;
        node* back = NULL;
        node *add = temp;
        while(temp != NULL){
            add = temp;
            temp = temp->next;
            add->next = back;
            back = add;
            if(temp == NULL){head = back;}
        }
    }
}

// recursive reverse solution;
void recursiverev(node* &head,node *curr,node *prev){
    if(curr == NULL){ head = prev; return ;} 
    curr = curr->next;
    head->next = prev;
    prev = head;
    head = curr;
    recursiverev(head,curr,prev);
}

// reverse1;
node* reverse1(node* head){
    if(head->next == NULL || head == NULL){return head;}
    node* chotahead = reverse1(head -> next);
    head->next->next = head;// head ka next ka next mtlb prev ka next;
    head->next = NULL;

    return chotahead;
}

//find middle node code in 2 way;  
int length_of_linklist(node* head){
    int c = 1;
    while(head->next != NULL){
        head = head->next;
        c++;
    }
    return c;
}

node* middlenode(node *&head,int l){
    node *temp = head;
    int c = 1;
    while(c != l){
        temp = temp->next;
        c++;
    }
    return temp;
}

node* m_2_mid(node* fast_runner){

    node *slow_runner = fast_runner;
    while(fast_runner != NULL && fast_runner->next != NULL){
        fast_runner = fast_runner->next->next;
        slow_runner = slow_runner->next;
    }
    return slow_runner;

}

int main(){
    int d ;
    cin>>d;
    node* n1 = new node(d);
    node* head = n1;
    node* tail = n1;
    if(d == 0){head = NULL; tail = NULL;}
    while(d != 0){
        cin>>d;
        insert(head,tail,d);
    }
    print(head);
    cout<<head->d<<" "<<tail->d<<endl;
    // itreative solution;
    // reverse(head);
    
    // Recursive solution;
    // node* curr = head;
    // node* prev = NULL;
    // tail = head;
    // recursiverev(head,curr,prev);
    // print(head);
    // cout<<head->d<<" "<<tail->d<<endl;

    // reverse by recursive different reverse tecqnie;
    reverse1(head);
    node *start = tail;
    tail = head;
    head = start;
    print(head);
    cout<<head->d<<" "<<tail->d<<endl;
    
    // find the middle node of linklist: if list have 4 no. of list then no. 3 is the middle for 4 node 
    // int l = length_of_linklist(head);
    // cout<<"length is "<<l<<"."<<endl;
    // l = (l/2) +1 ;
    // node* mid = middlenode(head,l);
    // cout<<mid->d<<endl;

    // node* ans = m_2_mid(head);
    // if(ans == NULL){cout<<"NULL\n";}
    // else{
    //     cout<<"Mid node is "<<ans->d<<endl;
    // }
    
}