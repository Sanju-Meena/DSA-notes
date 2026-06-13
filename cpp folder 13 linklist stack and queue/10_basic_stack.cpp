#include<iostream>
#include<stack>
using namespace std;
/*HW: 1. Implementation of stack using Linklist;

*/
// class Stack{
//     private:
//     int Size;
//     int *arr;
//     int Top ;

//     public:
//     Stack(int size){           // Constructor is used to inilize the parameter generally;
//         this->Size = size;
//         arr = new int[size];
//         Top = -1;
//     }
    
//     ~Stack(){delete[] arr;}    // Distructor;

//     void push(int d){
//         if(Size > Top+1){
//             Top++;
//             this->arr[Top] = d; 
//         }else{cout<<"Stack is full;\n";}
//     }

//     void pop(){
//         if(Top > -1){Top--;}
//         else{cout<<"Stack is  already empty;\n";}
//     }   
    
//     int top(){
//        if(Top > -1){int  a = arr[Top];
//         return a;
//        }else{ return -1;}
//     }

//     int size(){
//         if(Top > -1){int ans = Top+1;  return ans;}
//         else{return 0;}
//     }
//     bool empty(){
//         if(Top == -1){return true;}
//         else{return false;}
//     }
// };

// 2 Stack implementation using single array means we can push and pop the element from both side of array;
class Twostack{
    public:
    int *arr;
    int Size1;
    int Top1 ;
    int Top2 ;
    Twostack(int size){           // Constructor is used to inilize the parameter generally;
        arr = new int[size];
        Size1 = size;
        Top1 = -1;
        Top2 = size; 
    }
    
    ~Twostack(){delete[] arr;}    // Distructor;

    void push1(int d){
        if(Top2>(Top1+1)){
            Top1++;
            this->arr[Top1] = d; 
        }else{cout<<"Stack is full;\n";}
    }
    void push2(int d){
        if(Top1 < (Top2 - 1)){  //same condition as previous one;
            Top2--;
            this->arr[Top2] = d; 
        }else{cout<<"Stack is full;\n";}
    }

    void pop1(){
        if(Top1 > -1){Top1--;}
        else{cout<<"Stack is  already empty;\n";}
    }   
    void pop2(){
        if(Top2 < Size1){Top2++;}
        else{cout<<"Stack is  already empty;\n";}
    }   

    int top1(){
        if(Top1 >-1){int a = arr[Top1]; return a;}
        else{cout<<"stack is empty;\n";return -1;}
    }
    int top2(){
        if(Top2 < Size1){int a = arr[Top2]; return a;}
        else{cout<<"stack is empty;\n";return -1;}
    }
    void print(){
        for(int i = 0;i<Size1;i++){cout<<arr[i]<<" ";}cout<<endl;
    }
};

int main(){
    // stack is a type of LIFO(Last in first out) data structure that. 
    // stack<int> s;
    // if(s.empty()){cout<<"\nStack is empty.\n";} //1 mtlb empty;
    // else{cout<<"Stack is not empty\n.";}
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // cout<<"top element is "<< s.top()<<"."<<endl;
    // cout<<"Size of stack is "<<s.size()<<"."<<endl;
    // s.pop();
    // cout<<"Size of stack is "<<s.size()<<"."<<endl;
    // cout<<"Now top element "<< s.top()<<endl;
    // if(s.empty()){cout<<"Stack is empty.\n";}
    // else{cout<<"Stack is not empty.\n";}
    // cout<<endl;

    // 2 Stack implementation in a one array;
    cout<<endl;
    Twostack s1(8) ;
    s1.push1(2);
    s1.push1(4);
    s1.push1(6);
    s1.push1(8);
    s1.push1(10);
    cout<<"Top element is "<<s1.top1()<<"."<<endl;
    s1.pop1();
    cout<<"Top element is "<<s1.top1()<<"."<<endl;
    cout<<endl;

    s1.push2(3);
    s1.push2(6);
    s1.push2(9);
    s1.push2(12);
    cout<<"Top element is "<<s1.top2()<<"."<<endl;
    s1.pop2();
    cout<<"Top element is "<<s1.top2()<<"."<<endl;
    s1.push2(18);
    cout<<"Top element is "<<s1.top2()<<"."<<endl;
    cout<<endl;
    s1.print();
}