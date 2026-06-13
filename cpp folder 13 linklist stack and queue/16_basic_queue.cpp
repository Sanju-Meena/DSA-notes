#include<iostream>
using namespace std;
// // Queue is a FIFO data structure and all operation happen of TC O(1) but if we pop then it loss free space ;
// // To used free space we have used circular queue;

// // Linear queue implementation;
// // class Queue{
// //     public:
// //     int *arr;
// //     int size;
// //     int top;
// //     int fro;
// //     Queue(int s){
// //         this->top = -1;
// //         this->fro = -1;
// //         this->size = s;
// //         arr = new int[s];
// //     }
// //     ~Queue(){delete []arr;}

// //     bool push(int d){
// //         if(top == size-1){cout<<"Queue is full;\n"; return false;}
// //         else{
// //             top++;
// //             if(fro == 0){fro = fro +1;}
// //             arr[top] = d;
// //             return true;
// //         }
// //     }
// //     void pop(){
// //         if(top == -1){cout<<"Queue is already empty;\n"; }
// //         else if(top == fro){cout<<arr[fro]<<" is deleted\n"; fro = -1; top = -1;}
// //         else{
// //             cout<<arr[fro]<<" is deleted.\n";
// //             fro++;
// //         }
// //     }
// //     int front(){
// //         if(top == -1){return  -1;}
// //         else{int ab = arr[fro]; return ab;}
// //     }
// //     bool empty(){
// //         if(top == -1){return  1;}
// //         else{ return 0;}
// //     }
// //     int Size(){
// //         if(top == -1){return 0;}
// //         else{
// //             int si = top - fro +1;
// //             return si;
// //         }
// //     }
// // };

// // Circular queue implementation;
class Queue{
    public:
    int *arr;
    int size;
    int rear;
    int fro;

    Queue(int s){
        this->rear = -1;
        this->fro = -1;
        this->size = s;
        arr = new int[s];
    }
    ~Queue(){
        delete []arr;
    }

    bool push(int d){
        if(rear == -1 && fro == -1){rear++; fro++;}
        else if((rear+1)%size == fro ){
            cout<<"Queue is full\n"; return false;
        }
        // else if(rear == size-1 && fro !=0){rear = 0;} 
        else{
            rear = (rear+1)%size ;
        }
        arr[rear] = d;
        return true;
        
    }

    void pop(){
        if(rear == -1){cout<<"Queue is already empty;\n"; }
        else if(rear == fro){cout<<arr[fro]<<" is deleted\n"; fro = -1; rear = -1;}
        // else if(fro == size-1 ){fro = 0;}
        else{
            cout<<arr[fro]<<" is deleted\n"; 
            fro = (fro+1)%size; //upar vali condition ismai he check hoo jayegi;
        }
    }

    int front(){
        if(rear == -1){return  -1;}
        else{return arr[fro];}
    }

    bool empty(){
        if(rear == -1){return  1;}
        else{ return 0;}
    }

    int Size(){
        if(rear == -1){return 0;}
        else{
            if(rear >= fro){int si = rear - fro +1; return si;}
            else{int si = size - fro + rear + 1; return si;}
        }
    }
};

// // deque implementation;
class Deque{
    public:
    int Size;
    int fro;
    int rear;
    int *arr;
    
    Deque(int s){
        this->Size = s;
        arr = new int[s];
        this->fro = -1;
        this->rear = -1;
    }
    ~Deque(){delete[]arr;}

    bool push_front(int d){
        if(rear == -1 && fro == -1){rear++; fro++;}
        else if((rear+1)%Size == fro ){
            cout<<"Queue is full\n"; return false;
        }
        else{
            rear = (rear+1)%Size ;
        }
        arr[rear] = d;
        return true;
        
    }

    bool push_back(int d){
        if(rear == -1 && fro == -1){rear++; fro++;}
        else if((rear+1)%Size == fro ){
            cout<<"Queue is full\n"; return false;
        }
        else{
            fro = (fro-1)%Size ;
            if(fro == -1){fro = Size-1;}
        }
        arr[fro] = d;
        return true;
        
    }
    
    void pop_back(){
        if(rear == -1){cout<<"Queue is already empty;\n"; }
        else if(rear == fro){cout<<arr[fro]<<" is deleted\n"; fro = -1; rear = -1;}
        // else if(fro == size-1 ){fro = 0;}
        else{
            cout<<arr[fro]<<" is deleted\n"; 
            fro = (fro+1)%Size; //upar vali condition ismai he check hoo jayegi;
        }
    }

    void pop_front(){
        if(rear == -1){cout<<"Queue is already empty;\n"; }
        else if(rear == fro){cout<<arr[fro]<<" is deleted\n"; fro = -1; rear = -1;}
        // else if(fro == size-1 ){fro = 0;}
        else{
            cout<<arr[rear]<<" is deleted\n"; 
            rear = (rear-1)%Size; //upar vali condition ismai he check hoo jayegi;
            if(rear == -1){fro = -1;}
            }
    }

    int back(){
        if(rear == -1){return  -1;}
        else{return arr[fro];}
    }

    int front(){
        if(rear == -1){return  -1;}
        else{return arr[rear];}
    }

    bool empty(){
        if(rear == -1){return  1;}
        else{ return 0;}
    }

    int size(){
        if(rear == -1){return 0;}
        else{
            if(rear >= fro){int si = rear - fro +1; return si;}
            else{int si = Size - fro + rear + 1; return si;}
        }
    }
    
};


int main(){
    // linear queue;
    // int arr[1000000000];
    // queue<int> q;
    // q.push(5);
    // q.push(10);
    // q.push(15);
    // cout<<"\nFront element is : "<<q.front()<<endl;
    // q.pop();
    // cout<<"Front element is : "<<q.front()<<endl;
    // cout<<"Size of queue is : "<<q.size()<<endl;
    // cout<<"Is Queue empty : "<<q.empty()<<endl;
    // cout<<endl;
    
    // Circular queue;
    Queue q(5);
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(15);
    q.push(20);
    q.push(20);
    cout<<"\nFront element is : "<<q.front()<<endl;
    cout<<"Size of queue is : "<<q.Size()<<endl;
    q.pop();
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Size of queue is : "<<q.Size()<<endl;
    q.pop();
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Size of queue is : "<<q.Size()<<endl;
    cout<<"Is Queue empty : "<<q.empty()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    
    q.push(100);
    q.push(10);
    cout<<"\nFront element is : "<<q.front()<<endl;
    cout<<"Size of queue is : "<<q.Size()<<endl;
    q.pop();
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Size of queue is : "<<q.Size()<<endl;
    q.pop();
    cout<<"Front element is : "<<q.front()<<endl;
    cout<<"Size of queue is : "<<q.Size()<<endl;
    cout<<endl;



    // Deque;
    // deque<int> d;
    // d.push_front(12);
    // d.push_front(13);
    // d.push_front(14);
    
    // cout<<"First is : "<<d.back()<<endl;
    // cout<<"Last is : "<<d.front()<<endl;

    // d.push_back(11);
    // cout<<"First is : "<<d.back()<<endl;
    // cout<<"Last is : "<<d.front()<<endl;

    // d.pop_back();
    // cout<<"First is : "<<d.back()<<endl;
    // cout<<"Last is : "<<d.front()<<endl;

    // d.pop_front();
    // cout<<"First is : "<<d.back()<<endl;
    // cout<<"Last is : "<<d.front()<<endl;

    // if(d.empty()){cout<<"deque is empty;\n";}
    // else{cout<<"deque is not empty;\n";}
    // d.pop_back();
    // d.pop_back();
    // if(d.empty()){cout<<"deque is empty;\n";}
    // else{cout<<"deque is not empty;\n";}

    Deque d(8);
    d.push_front(12);
    d.push_front(13);
    d.push_front(14);
    
    cout<<"First is : "<<d.back()<<endl;
    cout<<"Last is : "<<d.front()<<endl;

    d.push_back(11);
    cout<<"First is : "<<d.back()<<endl;
    cout<<"Last is : "<<d.front()<<endl;

    d.pop_back();
    cout<<"First is : "<<d.back()<<endl;
    cout<<"Last is : "<<d.front()<<endl;

    d.pop_front();
    cout<<"First is : "<<d.back()<<endl;
    cout<<"Last is : "<<d.front()<<endl;

    if(d.empty()){cout<<"deque is empty;\n";}
    else{cout<<"deque is not empty;\n";}
    d.pop_back();
    d.pop_back();
    if(d.empty()){cout<<"deque is empty;\n";}
    else{cout<<"deque is not empty;\n";}




}

// /*Now theory start;
// 1. Input restricted queue: like normal queue but pop operation done from both side;
// 2. Output restricted queue: like normal queue but push operation done from both side;
// 3. Doubly ended queue: like normal queue but push and pop operation done from both side;
// */