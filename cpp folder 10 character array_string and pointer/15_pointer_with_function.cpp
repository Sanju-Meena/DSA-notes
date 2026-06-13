#include<iostream>
using namespace std;
void print(int *a,int *b){
    a+=10;
    *b+=4;
    cout<<a<<" "<<b<<endl;
}

void arrayprint(int asd[],int n){ //asd[] ek pointer hai arr+3 ka .
    for(int i = 0;i<n;i++){
        cout<<asd[i]<<" ";
        asd[i]++;
    }
    cout<<endl;
}

// int getsum(int asd[],int n){ //mtlb hum array pass nahi karte hai hum pointer pass karyte hai.
int getsum(int *asd,int n){
    cout<<"Size of asd array is "<<sizeof(asd)<<endl; //Ye hame pointer ki size batayega that is equal to 4 in my laptop .
    int s = 0;
    for(int i = 0;i<n;i++){
        s +=asd[i];
        asd[i]++;
    }
    return s;
}


int main(){
int a = 5,b = 6;
int *p = &a,*pt = &b;
print(p,pt);
cout<<a<<" "<<b<<endl;
cout<<endl;

int arr[5] ={1,2,3,4,5};
int n = sizeof(arr)/4;
cout<<"Size of array is "<<n<<endl;
arrayprint(arr+2,n);
for(auto i : arr){cout<<i<<" ";}cout<<endl;
cout<<"Sum of updated array is "<<getsum(arr,n)<<endl;

   

}