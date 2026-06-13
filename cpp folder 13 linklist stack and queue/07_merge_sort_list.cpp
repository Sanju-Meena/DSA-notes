#include<iostream>
using namespace std;
/*Question 1: you have no. 0 to 2 (in any order and in any repeated time) you have to make list of each number and then 3 list is prepare then you
  have to merge this list;
  Question 2: you have to given two sorted linklist and print them;
  Question 3: check palindrome by reversing the element and compare it;
  M-(ii): take value of linklist in array and check palindrome;
  Question 4: add two no.from linklist;
*/
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

void insert(node* &head,node* &tail,int a){
    if(head == NULL){node *fix = new node(a); head = fix; tail = fix;}
    else{
        node* temp = new node(a);
        tail ->next = temp; 
        tail = temp;
    }
}
void print(node* head){
    if(head == NULL){cout<<"Empty list.\n";}
    else{
        while(head != NULL){
            cout<<head->data<<" ";
            head = head ->next;
        }
        cout<<endl;
    }
}

node* mergeboth(node* &head,node* &tail,node* fh,node* sh){
     if(sh == NULL){return fh;}
    if(fh == NULL){return sh;}
    if(sh == NULL && fh == NULL ){return NULL;}
    while(fh != NULL && sh != NULL){
        if(fh ->data > sh->data){insert(head,tail,sh->data); sh = sh->next;}
        else{insert(head,tail,fh->data); fh = fh->next;}
    }
    while(fh != NULL){insert(head ,tail,fh->data); fh = fh->next;}
    while(sh != NULL){insert(head ,tail,sh->data); sh = sh->next;}
    return head;
}

node* mergesecond_in_first(node *&fh,node *&ft,node *&sh,node *&st){
    if(sh == NULL){return fh;}
    if(fh == NULL){fh = sh; return sh;}
    if(sh == NULL && fh == NULL ){ return NULL;}
    if(fh->next == NULL){
        node* kemp = fh;fh = sh;sh = kemp;
    }

    while(fh->data >= sh->data){
        node* t = new node(sh->data); t->next = fh;fh = t; sh = sh->next;
    }
    node* temp = fh ;node* remp ;node* kemp; node* prev;
    while(sh!= NULL && temp!= NULL){
        prev = temp;
        if(temp->data <= sh->data && temp->next->data >= sh->data){
            remp = sh; sh = sh->next;  kemp = temp->next;
            temp->next = remp; remp->next = kemp; temp = remp;            
            print(fh); cout<<endl;
        } 
        else{temp = temp->next;}
        if(temp ->next == NULL){break;}
    }  
    while(sh != NULL){
        node* chemp = new node(sh->data);
        temp->next = chemp; temp = chemp; sh = sh->next;
    }
    return fh;
}

/* Solution 3 Question start ;*/
bool checkpalindrome(node* head,int mid,int l){
    if(l <= 1){return true;}
    // else if(l == 2){ if(head->data == head->next->data){return true;} return false;}
    // else if(l == 3){ if(head->data == head->next->next->data){return true;} return false;}
    else{
        node* temp = head;
        node* prev = temp;;
        // int c = 1;
        // while(c!= mid+1){
        //     prev = temp;
        //     temp = temp->next;
        //     c++;
        // }
        // node* back = NULL;
        // node *curr = temp; //yaha pr curr mid node hai and  back previous  node hai;

        // method 2 to find mid node;
        node* fast = head; //temp slow runner hai and fast fastrunner hai;
        while(fast!=NULL && fast->next!= NULL){
            fast = fast->next->next;
            prev = temp;
            temp = temp->next;
        }
        if(l%2 == 1){prev = temp; temp = temp->next;}
        node* back = NULL;
        node*curr = temp;
        while(temp != NULL){
            temp = temp->next;
            curr->next = back;
            back = curr;
            curr = temp;
        }
        prev ->next = back;
        // compare;
        prev = prev->next;
        temp = head;
        while(prev->data == temp->data){
            prev = prev->next;
            temp = temp->next;
            if(prev == NULL){return true;}
        }
        return false;
    }
}

// add two list  ;
int given_no(node* start,node* he){
    int ans1 = 0,i = 1;
    int ans2 = 0,j = 1;
    int fa_he,fa_start;
    while(start != NULL || he != NULL){
        if(start != NULL){
            ans1 = ans1*i + start->data;
            start = start->next;
        }
        if(he != NULL){
            ans2 = ans2*j + he->data;
            he = he->next;
        }
        i = 10,j = 10;
    }
    return ans1+ans2 ;
}
void reverse(node* &he,node* &ta){
    node* temp = he;
    node* curr = he;
    node* back = NULL;

    while(temp != NULL){
        temp= temp->next;
        curr->next = back;
        back = curr;
        curr = temp;    
    }
    ta = he;
    he = back;
}

int main(){
    // node* zh = NULL; node* oh = NULL;node* th = NULL;
    // node* zt = NULL; node* ot = NULL;node* tt = NULL;
    // int a;
    // cin>>a;
    // while(a != -1){
    //     if(a == 0){insert(zh,zt ,a);}
    //     else if(a == 1){insert(oh,ot ,a);}
    //     else{insert(th,tt ,a);}
    //     cin>>a;
    // }
    // zt->next = oh;
    // ot->next = th;
    // print(zh);
    
    /* Second question answer; */
    // node* fh = NULL;
    // node* sh = NULL;
    // node* ft = NULL;
    // node* st = NULL;
    // int b,c;
    // cin>>b;
    // while(b != 0){
    //     insert(fh,ft,b);
    //     cin>>b;
    // }
    // // print(fh);
    // cout<<"Enter the data of second ll.\n";
    // cin>>b;
    // while(b != 0){
    //     insert(sh,st,b);
    //     cin>>b;
    // }
    // // print(sh);

    // // make another list and put values in sorted way by comparision,but it take more space;
    // // node* head = NULL;
    // // node* tail = NULL;
    // // mergeboth(head,tail,fh,sh);
    // // print(head);

    // // method second;
    // mergesecond_in_first(fh,ft,sh,st);
    // print(fh);

    // // check palindrome;
    // node* start = NULL;
    // node* end = NULL;
    // int n, l = 0;
    // cin>>n;
    // while(n != 0){
    //     l++;
    //     insert(start,end,n);
    //     cin>>n;
    // }
    // int mid ;
    // if(l%2 == 0){mid = l/2 + 1;}
    // else{mid = l/2 + 2;}

    // bool ch = checkpalindrome(start,mid,l);
    // if(ch == 1){cout<<"palindrome hai.\n";}
    // else{cout<<"not palindrome.\n";}

    /* add two no. from linklist;*/
    // node* start = NULL;
    // node* end = NULL;
    // int n, l = 0;
    // cin>>n;
    // while(n != 0){
    //     l++;
    //     insert(start,end,n);
    //     cin>>n;
    // }

    // node* h = NULL;
    // node* t = NULL;
    // l = 0;
    // cin>>n;
    // while(n != 0){
    //     l++;
    //     insert(h,t,n);
    //     cin>>n;
    // }

    // int ans = given_no(start,h);
    // node* he = NULL;
    // node* ta = NULL;
    // while(ans != 0){
    //     int num = ans%10;
    //     ans = ans/10;
    //     insert(he,ta,num);
    // } 
    // // print(he);
    // reverse(he,ta);
    // print(he);

    
    



}