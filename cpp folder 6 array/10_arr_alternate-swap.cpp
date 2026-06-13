#include <iostream>
using namespace std;

void print_array(int array[],int n){
    for(int i = 0;i<n;i++){
      cout<<array[i]<<" " ;
    }
    cout<<endl;
}

int main()
{
    int asdf[5] = {1, 2, 3, 4, 5};
    // 2,1,4,3,5 ;
    int a = sizeof(asdf) / 4;
    cout<<a<<endl;
    int b = 0;
    while (b < a - 1)
    {
        swap(asdf[b],asdf[b+1]);
        b+=2 ;
    }
    print_array(asdf,a) ;

    int asd[6] = {1, 2, 3, 4, 5, 6};
    // 2,1,4,3,6,5 ;
    int e = (sizeof(asd) / 4);
    int s = 0;
    while (s <= e)
    {
        swap(asd[s],asd[s+1]);
        s+=2;
    }
    print_array(asd,e) ;

}