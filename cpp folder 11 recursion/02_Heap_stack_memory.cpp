#include<bits/stdc++.h>
using namespace std;

int sum(int *ptr, int n){
    int s = 0;
    for(int i = 0;i<n;i++){
        s+=ptr[i];
    }
    return s;
}
int main(){
    // int n;
    // cin>>n;
    // int arr[n]; //it's a bad practise bcz hame program ki size compile time pr pata honi chaiyea.
    // Size run time pr pata lagna aachi practise nahi hai.

    /* Memory is of two type - stack & Heap.
    1. stack small memory as compare to heap.
    2. stack se memory allot hoti hai program ko.
    3. Now we have to learn how to use heap memory with 'new' keyword.
    4. When u use stack memory then it is called static memory allocation.
    5. When u use heap memory then it is called dynamic memory allocation.
    6. Heap memory mai hum always address return karenge name nahi.
    7. Heap memory hame always variable ya array ka kaam hone k baad free kr deni chaiyea by using delete keyword.
    */
     
    // new int-->hamne heap mai int size ki memory le li.
    char ch  = 'a';
    char *pt = &ch;
    cout<<sizeof(ch)<<endl;
    cout<<sizeof(pt)<<endl;

    int *i = new int; //Ye hamne heap memory mai int ki size store karai hai;
    *i = 50;
    cout<<*i<<endl;

    int size;
    cin>>size;
    int *ptr = new int[size]; //it's a good practise when we have unknown size array;
    for(int i = 0 ;i<size;i++){
        cin>>ptr[i];
    }

    for(int i = 0 ;i<size;i++){
        cout<<ptr[i]<<" ";
    }cout<<endl;

    cout<<sum(ptr,size)<<endl;

    /* Q. Difference btw static and dynamic memory?
       Ans : 1. In static, stack memory is used while in dynamic Heap memory is used;
             2. In Heap, memory is not clear when function is done their work;
             ex:- while(true){int *ptr  = new int;}
             3. delete keyword is used to cleared a Heap memory. 
    */
   int *numb = new int;
   cin>>*numb;
   cout<<*numb<<endl;
   delete numb;
   cout<<" Numb is = "<<*numb<<endl;

    // How to delete an array in heap memory;
    delete []ptr;


}
// void pointer and address type casting hame padhna hai.