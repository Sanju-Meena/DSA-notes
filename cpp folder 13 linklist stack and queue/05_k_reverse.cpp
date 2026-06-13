#include<iostream>
#include<map>
using namespace std;
// linklist koo reverse karna hai k ke group mai;
// linklist k ander loop hai ya na

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(node* &head){
    if(head == NULL){cout<<"list is empty;\n";}
    else{
        node *t = head;
        int c = 0;
        while(t != NULL && c<10){
            cout<<t->data<<" ";
            t = t->next;
            c++;
        }
        cout<<endl;
    }
}

void insert(node* &head,node* &tail,int a){
    if(head == NULL){node* fix = new node(a); head = fix; tail = fix;}
    else{
        node* temp = new node(a);
        tail->next = temp;
        tail = temp;
    }
}

node* kreverse(node* &head,int k){
    if(k == 1 || head == NULL || head->next == NULL){return head;}
    int c = 0;
    node* temp = head;
    node* back = NULL;
    node* curr = head;
    while(curr != NULL && c != k ){
        temp = temp->next;
        curr ->next = back;
        back = curr;
        curr = temp;
        c++;
    }
    if(curr != NULL){head->next = kreverse(temp,k);}
    return  back;

}

bool detectLoop(node* head) {
    if( head == NULL ){return false;}
    if(head == head->next ){return true;}
    
    map<node*,bool> m;
    m[head] = 1;
        node* temp = head;
        temp = temp->next;
        while(temp != head){
            if(temp == NULL){return false; }
            else if(temp == head || m[temp] == 1){cout<<"the loop of cycle is start from "<<temp->data<<endl; return true;}
            else{m[temp] = 1;  temp = temp->next; } 
            
            if(temp == head){return true;}
        }
    }
    
// method-2 of detect loop;
// by fastrun and slowrun;
bool floyddetectLoop(node* head){
    if(head == NULL ){return false;}
    if(head == head->next){return true;}
    node* fr = head;
    node* sr = head;
    while(fr != NULL && fr->next != NULL){
        fr = fr->next->next;
        sr = sr->next;
        if(fr == sr){return true;}
    }
    return false;
    
}

// loop ki starting node find by method 1 ;
// ye map lekr bhi aasani se hoo sakti hai but S(1) aayegi space complecity;
node* findsn(node* head){
    if(head == NULL ){return head;}
    if(head == head->next){return head;}
    node* fr = head;
    node* sr = head;
    while(fr != NULL && fr->next != NULL){
        fr = fr->next->next;
        sr = sr->next;
        if(fr == sr){
            sr = head;
            while(fr!= sr){
                if(fr == sr){return fr;}
                fr= fr->next;
                sr = sr->next;
            }
            return fr;

        }
    }
}

// third question is to remove loop in list;
node* removeloop(node* head){
    if(head == NULL ){return head;}
    if(head == head->next){ head->next = NULL; return head;}
    node* fr = findsn(head); 
    node* back = fr->next ;
    while(fr != back->next){
        back= back->next;
    }
    back->next = NULL;
    return back;
}

int main(){
    int a;
    cin>>a;
    node* head = NULL;
    node* tail = NULL;
    while(a != 0){
        insert(head,tail,a);
        cin>>a;
    }
    print(head);
    cout<<head->data<<" "<<tail->data<<endl;
    int k;
    cout<<"enter value of k\n";
    cin>>k;
    // do k reverse;
    node *ptr = kreverse(head,k);
    print(ptr);
    cout<<endl;
    
    // ans 2nd question;
    bool answe = detectLoop(head);
    if(answe == 1){cout<<"Loop is present\n";}
    else{cout<<"Loop is not  present\n";}
    print(head);
    cout<<endl;

    // ans 2nd question;
    tail->next = head->next;
    bool ans = detectLoop(head);
    if(ans == 1){cout<<"Loop is present\n";}
    else{cout<<"Loop is not  present\n";}
    print(head);
    cout<<endl;
    
    tail->next = head->next->next;
    bool answ = floyddetectLoop(head);
    if(answ == 1){cout<<"Loop is present\n";}
    else{cout<<"Loop is not  present\n";}
    print(head);
    cout<<endl;
    
    if(ans == 1){
        node* lfn = findsn(head);
        cout<<lfn->data<<endl;
    }

    tail->next = head;
    print(head);
    node* pt =  removeloop(head);
    print(head);

}

// 1 2 3 4 5 6 0 2