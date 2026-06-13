//  ***HEAP**
// Heap : it is a complete binary tree that comes with a heap order property;
// CBT -> every level is completely filled expect the last level, and nodes always added from the left;
// heap are of two type -> (i) max heap , (ii) min heap;
// max heap -> it child node data is always less than parent node ;
// min heap -> it child node data is always greater than parent node ;
// insertion : it is implemented by an array it means we make heap as an array and it hold some property;
// (i) we cannot fill 0 index of an array generally;
// (ii) if a node is in nth index then it's left child is 2*n index and right child is 2n+1 index;
// (iii) if a node is in mth index then it's parent is always lie on m/2 index;
// (iv) in a CBT, leaf node lie from index n/2 + 1 se too nth index tk;
// delete hamesha root node he karte hai heap mai;
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>

using namespace std;

class heap{
    public:
    int size;
    int arr[100];
    
    heap(){
        this->size = 0;
        arr[0] = -1;
    }
    void insert(int val){
         if(size + 1 < 100){
            size++;
            arr[size] = val;
            int in = size;
            while(in > 1){
                int parent = in/2;
                if(arr[parent] < arr[in]){swap(arr[parent],arr[in]);}
                else{return ;}
                in = parent;
            }
         } 
    }

    // delete hamesha root node he karenge;
    // pahele arr[i] mai last element store karayenge and then fir size koo km karenge and then jisse first element delete 
    // hoo jaye and then first element koo right place pr layenge acc. to which type of heap we try to make;
    void deleteheap(){
        if(size == 0){cout<<"Heap is already empty\n"; return ;}
        arr[1] = arr[size];
        size--;
        int i = 1;

        while(2*i <= size){
            // left index lin, right index rin,largest child index lci;
            int lin = 2*i,rin = 2*i+1;
            int lci = lin;
            if(rin <= size  && arr[lin] < arr[rin]){
                lci = rin;       
            }
            
            if(arr[lci] > arr[i]){
                swap(arr[i],arr[lci]);
                i = lci;
            }
            else{return ;}
        }
    }

    void  print(){
        int n = size;
        for(int i = 1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

// kisi bhi element koo correct place pr put karne k liye;
void heapify(int arr[],int n,int i){
    int left = 2*i,right = 2*i+1;
    int lar = i;
    if(left <= n && arr[i] < arr[left]){
        lar = left;
    }
    if(right <= n && arr[lar] < arr[right]){
        lar = right;
    }
    if(lar != i ){
        swap(arr[i],arr[lar]);
        heapify(arr,n,lar);
    }
    return ;
}

void min_heapify(vector<int> &arr,int n,int i){
    int l = 2*i + 1;
    int r = l + 1;
    int min = i;
    if(l <= n && arr[min] > arr[l] ){
        min = l;
    }
    if(r <= n && arr[min] > arr[r] ){
        min = r;
    }
    if(min != i){
        swap(arr[i],arr[min]);
        min_heapify(arr,n,min);
    }
}

int main(){
    heap h1;
    h1.insert(10);
    h1.insert(20);
    h1.insert(30);
    h1.insert(40);
    h1.insert(50);
    // h1.print();   
    h1.insert(25);
    h1.print();
    h1.deleteheap();
    h1.print();
    h1.deleteheap();
    h1.print();
    
    int n = 6;
    int arr[6] = {-1,54,53,55,52,50};
    n--;
    // heapify algo element koo log(n) tc mai right position pr paucha deti hai;
    for(int i = n/2;i>0;i--){
        heapify(arr,n,i);
    }
    for(int i = 1;i<=n;i++){cout<<arr[i]<<" ";} cout<<endl;
    
    // make min heap;
    vector<int> v = {9,3,2,6,7};
    n = v.size() - 1;
    for(int i = n/2;i>=0;i--){
        min_heapify(v,n,i);
    }
    for(int i = 0;i<=n;i++){cout<<v[i]<<" ";} cout<<endl;
    
    // heap sort: heap sort use karne se pahele heap apni property satisfy karna chaiyea min ya max heap vali ;
    int ar[6] = {-1,70,60,55,45,50}; //this is a max heap given;
    // apply heap sort;
    n = 5;
    while(n>1){
        swap(ar[1],ar[n]);
        n--;
        heapify(ar,n,1);
    }

    for(int i = 1;i<=5;i++){cout<<ar[i]<<" ";} cout<<endl;

    // priority queue always build max heap;
    priority_queue<int> he;
    he.push(4);
    he.push(5);
    he.push(1);
    he.push(10);
    he.push(2);
    he.push(9);
    he.push(6);
    cout<<"Top element in priority queue is "<<he.top()<<".\n";
    he.pop();
    cout<<"Top element in priority queue is "<<he.top()<<"."<<endl;
    cout<<"Size of heap is "<<he.size()<<".\n";
    if(he.empty()){cout<<"heap is empty;\n";}
    else{cout<<"Heap is not empty;\n";}
    n = he.size();
    // for(int i = 0;i<n;i++){
    //     cout<<he.top()<<" ";
    //     he.pop();
    // }cout<<endl;

    // min heap;
    cout<<"\n***Min heap start***\n";
    priority_queue<int,vector<int>, greater<int> >minheap;
    minheap.push(4);
    minheap.push(5);
    minheap.push(1);
    minheap.push(10);
    minheap.push(2);
    minheap.push(9);
    minheap.push(6);
    cout<<"Top element in priority queue is "<<minheap.top()<<".\n";
    minheap.pop();
    cout<<"Top element in priority queue is "<<minheap.top()<<"."<<endl;
    cout<<"Size of heap is "<<minheap.size()<<".\n";
    if(minheap.empty()){cout<<"heap is empty;\n";}
    else{cout<<"Heap is not empty;\n";}
}  

