#include <iostream>
#include <list>
using namespace std ;
// elenment not excess directly like l[2] .
int main()
{
    list<int> l = {1, 2, 3};
    //   list<int> l ;
    l.push_back(9);
    l.push_front(7);
    l.push_front(5);

    int size = l.size();
    cout<<"size : "<<size<<endl;

    for(int i: l){ cout<< i <<" " ;}
    cout<<endl;

    l.pop_back() ;
    l.pop_front() ;
    l.push_front(6) ;
    l.push_back(5) ;

    for(int i: l){ cout<< i <<" " ;}
    // i:l --> iska mtlb l ki sari value i mai store and we print i.
    cout<<endl;

    // l.erase(l.begin() , l.begin() + 3) ; ---> not valid ;
    l.erase(l.begin()) ; //only ek he element ko delete kr sakte hoo.

    for(int i: l){ cout<< i <<" " ;}

    cout << "\nFirst  element is " << l.front() << endl;
    // ditect access or at ka use kr k hum access nahi kr sakte.
    cout << "Last   element is " << l.back() << endl;
    cout << "empty or not : " << l.empty() << endl; // written boolean.
    
    list<int> c(5,10);
    for(int i: c){ cout<< i <<" " ;}
    cout<<endl;

}