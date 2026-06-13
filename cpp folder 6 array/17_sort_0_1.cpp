#include<iostream>
using namespace std ;

int main()
{
    int n = 10,k=0;
    int zx[n] = {0,1,1,1,0,0,0,0,1,1};
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



    // for(int i = 0;i<n;i++){
    //     if(zx[i] == 0){  k++ ;}
    // }
    //  for(int i = 0;i<k;i++){zx[i] = 0; }

    //  for(k;k<10;k++){zx[k] = 1;  }

    // for(int i = 0;i<n;i++){cout<<zx[i]<<" " ; }


// }