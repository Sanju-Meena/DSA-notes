#include<iostream>
#include<map>
using namespace std;
// remove dublicate from sorted list ;
// 2nd is remove dublicate from unsorted list :
// 1. first sorted then use 1 code;
// 2. by using loop having TC = n2;
// 3. by using map ;
// do any two method;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for "<<value<<"."<<endl;
    }
};
void print(node* head){
    if(head == NULL){cout<<"list is empty.\n";}
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insert(node* &head,node* &tail,int a){
    if(head == NULL){node* n1 = new node(a); head = n1; tail = n1;}
    else{
        node* temp = new node(a);
        tail->next = temp;
        tail = temp;
    }
}
void remove_dublicate(node* head,node *&tail){
    node* temp = head;
    node* curr = temp;
    temp = temp->next;
    node* back = temp;
    while(temp != NULL){
        while( temp != NULL && temp->data == curr->data){
            back = temp;
            temp = temp->next;
            back->next = NULL;
            delete back;
        }
        if(temp == NULL){
            curr->next = NULL;
            tail = curr;
            break;
        }
        else{
            curr->next = temp;
            curr = temp;
            temp = temp->next;
        }
    }
    cout<<endl;
}
void sorted_list(node* &head,node *&tail){
    node* temp = head;
    node* ch = head->next;
    while(temp != tail){
        node* cat = ch;
        while(ch != NULL){
            if(temp->data > ch->data){
                int back = temp->data;
                temp->data = ch->data;
                ch->data = back;
            }
            ch = ch->next;
        }
        if(temp->next == NULL){tail = temp;}
        temp = temp->next;
        ch = cat->next;
    }
}

void map_use_sort(node* head,node* tail){
    node* temp = head;
    map<int,int> m;
    int n = 1;
    while(temp != NULL){
        m[temp->data] = n;
        temp  = temp->next;
    }

    node* curr = head;
    node* prev = head;
    for(auto val : m){
        curr->data = val.first;
        prev = curr;
        curr = curr->next;
    }
    node *next_node_de = prev;
    prev = prev->next;
    tail = next_node_de; 
    next_node_de->next = NULL;
    delete prev;
}

int main(){
    int a;
    cin>>a;
    node* head = NULL;
    node* tail= NULL;
    while(a!= -1){
        insert(head,tail,a);
        cin>>a;
    }

    sorted_list(head,tail);
    print(head);

    // remove_dublicate(head,tail);
    // cout<<head->data<<" "<<tail->data<<endl;
    // print(head);
    
    // // sort and remove dublicate by map;
    // map_use_sort(head,tail );
    // print(head);
}