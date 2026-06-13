#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    // constructor: Ye automatically call hota hai agar hum nahi banate too;
    node(int data){
        (*this).data = data;
        this->next = NULL;
    }

    // destructor: ye automatically called hota node k liye yadi static allocation hoo too node k parameter ki or
    //  dynamic allocation hoo too function likhna padhta hai and call karna padhta hai;

    // Recursive Destructor ;
    ~node(){
        int value = this-> data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
    // ~node(){} isse bhi kaam chal sakta hai but isse memory likh ka khatra hoga; ex:- delete head; now memory likh happen;
};


// void insertattail(int data,node *&tail){
//     node *temp = new node(data);
//     tail->next = temp;
//     tail = temp;
// }

void insertathead(node *&head,int data){
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

// How to traverse a linklist;
void print(node* &head){
    node* t = head;
    while(t != NULL){
        cout<<(*t).data<<" ";
        t = t->next;
    }
    cout<<endl;
}

// insert at any position;
void insertatpos(node* &head,int pos,int data,node* &tail){
    node* temp = head;
    int count = 1;
    node *fix = new node(data);
    // insert at top;
    if(pos == 1){
        fix->next = head;
        head = fix;
    }
    else{
        while(count < pos){
            if(count == pos-1){fix->next = temp->next; temp->next = fix; break;}
            temp = temp->next;
            count++;
        }
    }
    if(fix->next == NULL){tail = fix;}
}

// delete the node at any pos;
void deletenode(node* &head,int pos,node* &tail){
    node* temp = head;
    if(pos == 1){
        head = head->next;
        temp->next = NULL;
        delete temp; //iska mtlb pahele temp node koo delete  karo or hamne likha hai distructor k ander ki yadi node ka next 
        // null na ho too delete next mtlb dlete karo agli node ko bhi isliye hum pahele he next ko null point karate hai;
    }
    else{
        int count = 1;
        node* previous = NULL;
        while(count != pos){
            previous = temp;
            temp = temp->next;
            count++;
        }
        previous->next = temp->next;
        temp->next = NULL;
        if(previous->next == NULL){tail = previous;}
        delete temp;
        
    }
}


int main(){
    // allocate a integer value and assign it to 10 in heap memory;
    // int *ptr = new int(10);
    // cout<<*ptr<<endl;
    // cout<<ptr<<endl;
    // delete ptr;

    /*
    Linklist is a linear data structure having collection of nodes(node is a class containing data and address of next node);
    1.Linklist is a dynamic data structure and we can grow and shrink the size during run time;
    2.vector is also a dynamic data structure that create new space and then copy all it's value to new space and
     all space are always not fill and we can waste our storage;
    3. Insertion and deletion are easy to done;
    4. Types of linklist;
    (i)   singly linklist;
    (ii)  doubly linklist;
    (iii) circular linklist;
    (iv)  circular doubly linklist;
    */
    
    // node *n1; This declares a pointer n1 that can point to a node object.
    // new node(10); "Create a new object of class node in heap memory and initialize it with the value 10 using the constructor."
    // creation of node having data and point to null character;
    
    // create a new node;
    node* node1 = new node(10);
    cout<<node1<<" "<<endl;
    cout<<&((*node1).data)<<endl;

    cout<<(*node1).data<<endl;
    cout<<node1->data<<endl;

    cout<<node1->next<<endl;
    cout<<&(node1->next)<<endl;

    node* head = node1; //node1 = head;
    node* tail = node1; //node1 = tail;

    cout<<head<<" "<<tail<<endl;
    insertathead(head,8);  
    insertathead(head,6);
    insertathead(head,2);
    print(head);
    
    // node* node2 = new node(100);
    // node* tails = node2;
    // node* start = node2;
    // insertattail(200,tails);
    // insertattail(300,tails);
    // insertattail(400,tails);
    // print(start);

    // Insert at any position;
    int pos  = 3,input = 7;
    insertatpos(head,pos,input,tail);
    print(head);

    input = 1,pos = 1;
    insertatpos(head,pos,input,tail);
    print(head);

    input = 12,pos = 7;
    insertatpos(head,pos,input,tail);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    
    // deleting the node at any pos;
    pos = 1;
    deletenode(head,pos, tail);
    print(head);
    pos = 3;
    deletenode(head,pos,tail);
    print(head);
    pos = 5;
    deletenode(head,pos,tail);
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;

    return 0;


}