#include<iostream>
using namespace std ;
// homework;
int main()
{
    int n = 10,k=0;
    int zx[n] = {0,2,1,2,0,0,2,0,1,1};
   int l = n-1;
   while(k<l){
       while(zx[k] == 0 ){ k++;}
       while(zx[l]==1 && k<l){l-- ;}
       while(zx[k] == 1 && zx[l]==0 && k<l){
        swap(zx[k],zx[l]);
        k++;
        l--;
   }
    for(int i = 0;i<n;i++){cout<<zx[i]<<" " ; }

   }
}