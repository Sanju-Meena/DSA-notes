#include <iostream>
#include<climits>
using namespace std;

int main()
{
    int qw[5] = {1,2,2,3,4};
    int as[4] = {2,2,3,3};
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(qw[i] == as[j]){
                cout<<qw[i]<<endl;
             as[j] = -12321 ;
                break;
            }

        }
    }

}