#include<bits/stdc++.h>
using namespace std;
// list is implemented by doubly linked list;
// only operation valid that are implemented by dll;

void print(list<int> l){
    // cout<<"print list\n";
    for(auto i:l){cout<<i<<" ";}cout<<endl<<endl;    
}

int main(){
    cout<<endl;
    list<int> l = {20,80,40,30};
    print(l);  
    cout<<"front element is "<<l.front()<<endl;
    cout<<"last element is "<<l.back()<<endl;
    print(l);  
    cout<<"insert element 10, 50 at front and end\n";
    l.push_front(10);
    l.push_back(50);
    print(l);  

    //  delete element from back and then front
    cout<<"\ndelete element from back and then front\n";
    l.pop_back();
    print(l);  
    l.pop_front();
    print(l);  
    cout<<"remove 30 from list\n";
    l.remove(30);    
    print(l);  
    cout<<"Size of list is "<<l.size()<<endl;
    cout<<"list is empty or not : "<<l.empty()<<endl;
    l.push_front(50);
    print(l);  

    // sort a list;
    l.sort();
    print(l); 

    // sort a list in decending order;
    l.sort(greater<int>());
    print(l);  

    l.push_back(35);
    print(l);  

    // reverse a list;
    l.reverse();
    print(l);  

    // how we traverse directly an element;
    auto it = l.begin();
    auto it_to_3th = next(it, 3);
    cout<<"it point to "<<*it<<" \n";
    cout<<"it_to_3th point to next(it,3) "<<*it_to_3th<<endl<<endl;

    // Get an iterator to the beginning
    auto its = l.begin(); 
    cout<<"Original 'its' points to: "<<*its<<endl; 
    
    // Advance 'its' by 2 positions
    advance(its, 2); 
    cout<<"advance(its,2) points to: "<<*its<<endl; 
    cout<<"When we use advance function it modify its iterator\n\n";
     cout<<"Print l\n";
    print(l); 

    cout<<"Print list: m\n";
    list<int> m = { 1,2,3,1,2,5};
    print(m);

    // unique and merge function implemented;
    m.sort();
    cout<<"unique function use karne se pahele sort karna padhta hai\n";
    m.unique();
    print(m);
    
    m.merge(l);
    cout<<"after using merge function print list: l and m\n";
    cout<<"Print l\n";
    print(l); 
    cout<<"Print m\n";
    print(m);
    
    // clear a list;
    m.clear();
    print(m);
    return 0;
}