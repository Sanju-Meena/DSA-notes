#include<iostream>
#include<stack>
using namespace std;
// Q:1 implement n stack in one array;
// Q:2 getmin and pop function work in O(1) time complicity;

// class Stack{
//     public:
//     int n;
//     int s;
    
//     int *arr;
//     int *top;
//     int *next;
//     int freespot;

//     Stack(int n,int size){ 
//         this->s = size;
//         this->n = n;
//         this->freespot = 0;
//         arr = new int[size];
//         top = new int[n];
//         for(int i = 0;i<n;i++){top[i] = -1;}
//         next = new int[size];
//         for(int i = 0;i<size;i++){next[i] = i+1;}
//         next[size-1] = -1;
//     }

//     ~Stack() {
//     delete[] arr;
//     delete[] top;
//     delete[] next;
//     }

/*ans->2 question */
class Stack{
    public:
    int size;
    int *arr;
    // int mini;
    int top;
    // int in;


    Stack(int size){
        this->size = size;
        arr = new int[size];
        // mini = INT_MIN;
        top = -1;
        // in = 0;
    }
    ~Stack(){
        delete[] arr;
    }

    void push(int d){
        if(top <= size){cout<<"stack is full;\n"; return ;}
        else{
            top++;
            arr[top] = d;            
        }
    }

    
    void pop(){
        if(top == -1){cout<<"stack is already empty;\n";}
        else{
            top--;
            return ;
        }
    }

    int Top(){
        if(top == -1){cout<<"stack is empty;\n"; return -1;}
        else{int a = arr[top]; return a;}
    }
};

//     bool push(int x,int m){
//         // check for overflow;
//         // if(freespot >= s){return false;} acc to me;
//         if(freespot == -1){return false;}
//             // find index;
//             int in = freespot;
//             // update freespot ;
//             freespot = next[in];
//             // assign value in array;
//             arr[in] = x;
//             // next update;
//             next[in] = top[m-1];
//             // update top;
//             top[m-1] = in;
//             return true;
//     }

//     int pop(int m){
//         if(m>n || m<=0){cout<<"is no. ka koi stack hai he nahi;\n"; return -1;}
//         else if(top[m-1] == -1){cout<<"already empty;\n";  return -1;}
//         else{
//             int in = top[m-1];
//             top[m-1] = next[in];
//             next[in] = freespot;
//             freespot = in;
//             return arr[in];
            

//         }
//     }

// };

int main(){

    // ans of 2 question;
    int n;
    cout<<"Enter size;\n";
    cin>>n;
    Stack s(5);
    int pus;
    cout<<"Enter no. of element in stack;\n";
    cin>>pus;
    while(pus--){int a ; cin>>a; s.push(a);}




    // cout<<"enter no. of stack and array size;\n";
    // int n,si;
    // cin>>n>>si;
    // Stack s(n,si);
    // cout<<"enter how many time u pushes;\n";
    // int pushq;
    // cin>>pushq;
    // while(pushq--){
    //     int x,m;
    //     cout<<"enter  element and which stack are you pushing this\n";
    //     cin>>x>>m;
    //     bool answer = s.push(x,m);
    //     if(answer == true){cout<<"push hoo gaya\n";}
    //     else{cout<<"space is full\n";}
    // }
    // int popq;
    // cout<<"Enter no. of times u use pop operation;\n";
    // cin>>popq;
    // while(popq--){
    //     int m;
    //     cout<<"enter stack no. where you delete element;\n";
    //     cin>>m;
    //     int delet = s.pop(m);
    //     if(delet == -1){}
    //     else{cout<<delet<<" is delete from stack "<<m<<"."<<endl;}
    // }

    // cout<<"enter how many time u pushes;\n";
    // int pus;
    // cin>>pus;
    // while(pus--){
    //     int x,m;
    //     cout<<"enter  element and which stack are you pushing this\n";
    //     cin>>x>>m;
    //     bool answer = s.push(x,m);
    //     if(answer == true){cout<<"push hoo gaya\n";}
    //     else{cout<<"space is full\n";}
    // }
    // int po;
    // cout<<"Enter no. of times u use pop operation;\n";
    // cin>>po;
    // while(po--){
    //     int m;
    //     cout<<"enter stack no. where you delete element;\n";
    //     cin>>m;
    //     int delet = s.pop(m);
    //     if(delet == -1){}
    //     else{cout<<delet<<" is delete from stack "<<m<<"."<<endl;}
    // } 

}