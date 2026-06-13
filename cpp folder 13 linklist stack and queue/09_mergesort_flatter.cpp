// Hw: why prefer mergesort in linklist and quick sort in array;
#include<iostream>
using namespace std;
//   Question 1: merge sort perform in linklist;
// flatter a linklist;
class node{
    public:
    int data;
    node* next;
    node* rand;
    node(int d){
        this->data = d;
        this->next = NULL;
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


// Question 1 ka  ans;
node* mergelinks(node* fh,node* sh){
    node* head = NULL;
    node* tail = NULL;
     if(sh == NULL){return fh;}
    if(fh == NULL){return sh;}
    while(fh != NULL && sh != NULL){
        if(fh ->data > sh->data){insert(head,tail,sh->data); sh = sh->next;}
        else{insert(head,tail,fh->data); fh = fh->next;}
    }
    while(fh != NULL){insert(head ,tail,fh->data); fh = fh->next;}
    while(sh != NULL){insert(head ,tail,sh->data); sh = sh->next;}
    return head;
}

node* mergesort(node* head){
    if(head == NULL || head->next == NULL){return head;}
    node* sr = head;
    node* fr = head->next;
    while(fr != NULL && fr->next != NULL){
        sr = sr ->next; fr = fr->next->next;
    }
    node* mid = sr;    
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;    
    left = mergesort(left);
    right = mergesort(right);       

    return mergelinks(left,right);
}

// flatter question;
void sort(node* &head,node *&tail){
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
int main(){
    /*Solution of merge sort given below:-*/
    // node* head = NULL;
    // node* tail = NULL;
    // int a;
    // cin>>a;
    // int l = 0;
    // while(a!= 0){
    //     l++;
    //     insert(head,tail,a);
    //     cin>>a;
    // }
    // print(head);
    // if(l>1){head = mergesort(head);}
    // print(head);

    // flatter a linklist;
    node* head = NULL;
    node* tail = NULL;
    int a;
    cin>>a;
    int l = 0;
    while(a!= -1){
        l++;
        insert(head,tail,a);
        cin>>a;
    }
    print(head);

    node* temp = head;
    node* kemp = head;
    
        temp->rand->data = 4;
        temp = temp->rand;
        temp->rand->data = 6;
        kemp = kemp->next;
        temp = kemp;
        temp->rand->data = 11;
        temp = temp->rand;
        temp->rand->data = 14;
        kemp = kemp->next;
        temp = kemp;
        temp->rand->data = 25;
        kemp = kemp->next;
        temp = kemp;
        temp->rand->data = 28;
        kemp = kemp->next;
        temp = kemp;
        temp->rand->data = 42;

        
       
   
//    3 5 22 26 39 -1

    print(head);

    node* s = NULL;
	node* e = NULL;
    temp = head;
	while(temp!= NULL){
        int a = temp->data;
		insert(s,e,a);
		kemp = temp;
		while(kemp != NULL){
		    a = kemp->rand->data;
			insert(s,e,a);
			kemp = kemp->rand;
		}
	}

	if(s != NULL && s->next != NULL){sort(s,e);}
	print(s);
}