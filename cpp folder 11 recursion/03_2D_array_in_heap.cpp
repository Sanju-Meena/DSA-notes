#include<iostream>
using namespace std;
// Abhi itna clear nahi hai vapis video dekhni padegi.
int main(){
    int n,m;
    cin>>n>>m;
    int **ptr = new int *[n];
    for(int i = 0;i<m;i++){
        ptr[i] = new int[n];
    }

    for(int i = 0 ;i<n;i++){
        for(int j = 0 ; j<m;j++){
            cin>>ptr[i][j];
        }
    }
    for(int i = 0 ;i<n;i++){
        for(int j = 0 ; j<m;j++){
            cout<<ptr[i][j]<<" ";
        }cout<<endl;
    }
    // Releasing Heap memory;
    for(int i = 0 ; i < n;i++){
        delete []ptr[i];
    }
    delete []ptr;

}
// homework --> Create jaggered array dynamically;