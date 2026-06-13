#include<iostream>
using namespace std;
// Question 1: make clone of original list;
// method second is best for exam;

class node{
    public:
    int data;
    node* next;
    node* rand;
    node(int d){
        this->data = d;
        this->next = NULL;
        this ->rand = NULL;
    }
};
void insert(node* &head,node* &tail,int a){
    if(head == NULL){node *fix = new node(a); head = fix; tail = fix;}
    else{node* temp = new node(a);
         tail ->next = temp; 
         tail = temp; }
}

void print(node* head){
    int c = 0;
    if(head == NULL){cout<<"Empty list.\n";}
    else{while(head != NULL && c<11){
            cout<<head->data<<" ";
            head = head ->next; c++;
        }cout<<endl;}
}

// clone 3rd method ;
void mergeclonenode(node* head,node* h){
    node* temp = head;
    node* curr = head;
    node* cn = h;
    node* start = h;
    while(temp != NULL){
        temp = temp->next;
        start = start->next; 
        curr->next = cn;
        cn->next = temp;
        curr = temp;
        cn = start;
    }
}
void clone_rand_value_assign(node* head,node* h){
    node* temp = head;
    node* clonehd = h;
    while(temp != NULL){
        if(temp->rand == NULL){clonehd->rand = NULL;}
        else{clonehd->rand = temp->rand->next;}
        
        if(temp->next != NULL){temp = temp->next->next;}
        if(clonehd->next != NULL){ clonehd = clonehd->next->next;}
    }
}
void retain_original_list(node* head,node* h){
    node* temp = head;
    node* clonend = h;
    node* curr = head;
    node* start = h;
    while(temp != NULL){
        temp = temp->next->next;
        if(clonend->next != NULL){ clonend = clonend->next->next;}
        else{start->next = NULL;}
        curr->next = temp;
        curr = temp;
        start = clonend;
    }
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    int a;
    cout<<"Enter 3 input: \n";
    cin>>a;
    while(a!= 0){insert(head,tail,a); cin>>a;}
    print(head);
    node* temp = head;
    if(head!= NULL){
        temp->rand = head->next->next;
        temp = temp->next;
        temp->rand = NULL;
        temp = temp->next;
        temp->rand = head->next;
    }

    cout<<"\nPreparation for clone forming;\n";
    node* h = NULL;
    node* t = NULL;
    node* temper = head;
    while(temper != NULL){
        insert(h,t,temper->data);
        temper = temper->next;
    }
    print(h);
    
    /*Method - 1 by me;*/
    // vector<int> v;
    // node* camp = head;
    // while(camp != NULL){
    //     if(camp ->rand == NULL){v.push_back(0);}
    //     else{
    //         int a = camp->rand->data;
    //         int s = 1;
    //         node* ram = head;
    //         while(ram->data != a){s++; ram = ram->next;}
    //         v.push_back(s);
    //     }
    //     camp = camp->next;
    // }
    // for(auto i: v){cout<<i<<" ";}cout<<endl;
    
    // node *kam = h;
    // int i = 0;
    // while(kam!=NULL){
    //     node *sam = h;
    //     int a = v[i];
    //     if(a == 0){kam->rand = NULL;}
    //     else{
    //         int c = 1;
    //         while(c!=a){sam = sam->next; c++;}
    //         kam->rand = sam; 
    //     }
    //     kam = kam->next;
    //     i++;
    // }

    /*Method - 2;*/
    // map<node*,node*> m;
    // temp = head;
    // node* remp = h;
    // while(temp != NULL){
    //     m[temp] = remp;
    //     temp = temp->next;
    //     remp = remp->next;
    // }
    
    // remp = h;temp = head;
    // while(temp != NULL){
    /*remp ->rand = temp->rand ; ye galat hai kyuki hum ismai rand pointer ko original copy se attach kr rahe hai , yadi baad 
      mai hum original ko change karenge too hamari dublicate copy bhi change hoo jayegi ;*/
    //     remp->rand =m[temp->rand]; 
    //     temp = temp->next;
    //     remp = remp->next;
    // }
    // space complecity O(n) aa rhi hai ;
    
    /*Method - 3 */
    cout<<"Preparation start\n";
    mergeclonenode(head,h);
    print(head);
    print(h);
    clone_rand_value_assign(head,h);
    retain_original_list(head,h);

    head->rand->data = 100;
    cout<<"paam ka rand ka data\n";
    node* paam = h;
    while(paam != NULL){
        if(paam ->rand == NULL){cout<<0<<" ";}
        else{cout<<paam->rand->data<<" ";}
        paam = paam->next;
    }
}