#include <iostream>
using namespace std;

int main()
{
    int l = 10 ;
    int qw[l] = {9, 3,9,22,3,3,3,22,22,22};
    int n = 0 ;
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 1;
        for (int j = 0; j < l; j++)
        {
            if (qw[i] == qw[j] && i != j){
                arr[i]++;        }
        } }
   int i = 0 ;
    while(n<l){
        cout<<arr[i]<<endl;
        i++ ;
        n++ ;
    }

int p = 0;
cout<<endl;
    for(int i = 0 ; i<10;i++){
        for(int j = 0;j<10;j++){
          if(i!=j){  
            cout<<"i = "<<i <<" j = "<<j<<endl;
            if (qw[i]!=qw[j] && arr[i] == arr[j] ){
               p=1 ;
               cout<<arr[i]<<endl<<i<<endl<<j<<endl<<endl;
               break ;
            }
          }
        }
        if(p==1){break;}
    }
    if(p==0){
        cout<<"true"<<endl;
    }
    if(p==1){cout<<"false" ;}
}