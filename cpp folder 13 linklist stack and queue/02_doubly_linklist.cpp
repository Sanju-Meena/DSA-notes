#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* previous;
    // Constructor bn gaya; 
    node(int data){
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }
    // destructor;
    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the value "<<value<<"." <<endl;
    }
};

// void insertattail(node *&head,int data,node* &end){
//     if(head == NULL){node*temp = new  node (data); head = temp; end = temp;}
//     else{
//         node* temp = new node(data);
//         end->next = temp;
//         temp->previous = end;
//         end = temp;
//     }
// }

void insertathead(node* &head,int ip,node *&tail){
    if(head == NULL){node* temp = new  node (ip); head = temp; tail = temp;}
    else{
        node* temp = new node (ip);
        temp->next = head;
        head->previous = temp->next;
        head = temp;
    }
}

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// insertion;
void insert_at_any_position(node* &head,int pos,int ip,node* &tail){
    node* fix = new node(ip);
    node* temp = head;
    if(pos == 1){
        fix -> next = head;
        head->previous = fix;
        head = fix;
    }
    else{
        int count = 1;
        while(count < pos-1){
            temp = temp->next;
            count ++;
        }
        fix->next = temp->next;
        fix ->previous = temp;
        temp ->next = fix;
        if(fix->next == NULL){tail = fix;}
    }
}
 
    // deletion;
    void delete_at_pos(node *&head,node *&tail,int pos){
        node *temp = head;
        node *back = NULL;
        if(pos == 1){
            head = head ->next;
            temp->previous = NULL;
            temp->next = NULL;
            head->previous = NULL;
            delete temp;
        }else{
            int c = 1;
            while(c < pos ){
                back = temp;
                temp = temp->next;
                c++;
            }
            back->next = temp->next;
            if(temp->next == NULL){tail = back;}
            temp->next = NULL;
            temp->previous = NULL;
            delete temp;
        }
}

int main(){
    /* Doubly linked list:
    A Doubly Linked List (DLL) is a type of linked list in which each node contains three fields:
    (i) Data – stores the actual data.
    (ii) Prev – pointer – pointer contain the address of previous node.
    (iii) next – pointer – pointer contain the address of next node.
    This allows bi-directional traversal — from head to tail and tail to head.
    */
//    node *n1 = new node(50);
   node *head  = NULL;
   node *tail  = NULL;
//    cout<<n1->data<<" "<<n1->next<<" "<<n1->previous<<endl;
//    cout<<n1<<" "<<&(n1->data)<<endl;
   cout<<head<<" "<<tail<<endl;

   int ip = 50;
   insertathead(head,ip,tail);
   ip = 40;
   insertathead(head,ip,tail);
   ip = 30;
   print(head);
   insertathead(head,ip,tail);
   print(head);
   ip = 20;
   insertathead(head,ip,tail);
   print(head);
   cout<<head->data<<" "<<tail->data<<" "<<endl;
   cout<<endl;
   
   // insertattail;
   // node* n2 = new node(10);
   //    node *start = NULL;
   //    node *end = NULL;
   //    ip = 10;
   //    insertattail(start,ip,end);
   //    ip = 20;
   //    insertattail(start,ip,end);
   //    print(start);
   //    ip = 30;
   //    insertattail(start,ip,end);
   //    print(start);
   //    cout<<start->data<<" "<<end->data<<" "<<endl;
   //    cout<<endl;
   
   // insert_at_any_position ;
   int pos = 1;
   ip = 10;
   insert_at_any_position(head,pos,ip,tail);
   print(head);
   cout<<head->data<<" "<<tail->data<<" "<<endl;
   ip = 25,pos = 3;
   insert_at_any_position(head,pos,ip,tail);
   print(head);
   cout<<head->data<<" "<<tail->data<<" "<<endl;
   ip = 60,pos = 7;
   insert_at_any_position(head,pos,ip,tail);
   print(head);
   cout<<head->data<<" "<<tail->data<<" "<<endl;
   cout<<endl;
   
   // deletion of any node;
   pos = 1;
   delete_at_pos(head,tail,pos);
   cout<<head->previous<<endl;
   print(head);
   cout<<head->data<<" "<<tail->data<<" "<<endl;
   pos = 2;
   delete_at_pos(head,tail,pos);
   print(head);
   cout<<head->data<<" "<<tail->data<<" "<<endl;
   pos = 5;
   delete_at_pos(head,tail,pos);
   print(head);
   cout<<head->data<<" "<<tail->data<<" "<<endl;
   cout<<endl;

}