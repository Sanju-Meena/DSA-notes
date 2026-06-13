#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    // constructor;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~node(){
        cout<<"Memory is free for value of "<<this->data<<endl;
    } 
};

void print(node* tail){
    if(tail == NULL){cout<<"List is empty\n";}
    else{
        node* temp = tail;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != tail);
        cout<<endl;
    }
}

void insert(node* &tail,int ip,int element){
    if(tail == NULL){
        node* n1 = new node(ip);
        n1->next = n1;
        tail = n1;
    }
    else{
        // given element k aage value daal doo;
        // last k aage daloge too front mai aayega;
        node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
            if(curr == tail){ cout << "element not found\n"; return ;}
        
        }

        node* temp = new node(ip);
        temp->next = curr->next;
        curr->next = temp;
        
    }
}

void delete_at_list(node* &tail,int element){
    node *back = tail;
    node* temp = tail->next;
    if(back == temp){ temp->next = NULL; delete tail;tail = NULL;}
    else{
        while(temp->data != element){
            back = temp;
            temp = temp->next; 
        }
        back->next = temp->next;
        if(tail->data == temp->data){tail = back;}
        temp->next = NULL;
        delete temp;
    }
    
}

int main(){
    
    node* tail = NULL;
    int ip = 1,element = 5 ;
    insert(tail,ip,element);
    print(tail); 
    
    element = 1,ip = 3;
    insert(tail,ip,1);
    print(tail);
    
    element = ip ,ip = 5;
    insert(tail,ip,element);
    print(tail);
    
    element = 3 ,ip = 2;
    insert(tail,ip,element);
    print(tail);
    
    element = 5 ,ip = 4;
    insert(tail,ip,element);
    print(tail);
    
    element = 1 ,ip = 0;
    insert(tail,ip,element);
    print(tail);
    
    // delete element in the cll;
    delete_at_list(tail,1);
    print(tail);

    delete_at_list(tail,0);
    print(tail);

    delete_at_list(tail,4);
    print(tail);

    delete_at_list(tail,2);
    print(tail);

    delete_at_list(tail,5);
    print(tail);

    delete_at_list(tail,3);
    print(tail);
}