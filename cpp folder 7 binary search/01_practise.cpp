#include<iostream>
using namespace std;

void peak(int qw[],int size){
    int s = 0,e = size -1;
    int m = s+(e-s)/2;
    while(s<e){
        if( qw[0] > qw[m] ){
            e = m ;
        }
        else{
            s = m+1;
        }
        m = s+(e-s)/2;
    }
    cout<<"pivert element is "<<qw[s] ;
}
int main(){
int aws[5]= {6,9,1,2,5};
peak(aws,5) ;

}