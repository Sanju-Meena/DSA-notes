#include<bits/stdc++.h>
using namespace std;

int main(){ 
pair<float,string> pa;
// pa = make_pair(2.45,"abc") ;//is type se values dalte hai.
pa = {2.765,"Kajal"} ;
cout<<pa.first<<" "<<pa.second<<endl ;

pair<int , string> p1 = pa; // pa ki copy jayegi p1 mai.
p1.second = "meena" ;
cout<<p1.first<<" "<<p1.second<<endl;
cout<<pa.first<<" "<<pa.second<<endl;

pair<float,string> &c = pa; // pa ki actual value jayegi p1 mai.
c.first = 6.98;
cout<<c.first<<" "<<c.second<<endl;
cout<<pa.first<<" "<<pa.second<<endl;

// int crr[3] = {1,2,3};
// int brr[3] = {2,3,4};
// upar do line ki gajah neche ki ek line likho.
pair<int,int> array[3];
array[0] = {1,2};
array[1] = {5,6};
// array[2] = {3,4};
cin>>array[2].first>>array[2].second ;
swap(array[0],array[2]) ;
for(int i = 0;i<3;i++){
    cout<<array[i].first<<" "<<array[i].second<<endl;
}
pair<int , string> d ;
cin>>d.first>>d.second;
cout<<d.first<<" "<<d.second<<endl;

}