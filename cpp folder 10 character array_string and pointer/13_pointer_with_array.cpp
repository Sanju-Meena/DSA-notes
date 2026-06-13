#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {2,87,23,98,76,90,34,90,234,900};
    cout<<"Address of first element of array is "<<arr<<endl;
    int *pt =  &arr[0];
    cout<<pt<<endl;
    // Hame niche vala use karna chaiyea bcz chota hai.
    int *ptr = arr;
    cout<<ptr<<endl;
    cout<<*arr<<endl; //arr address ko store karta hai pahele element ki or aage * laga diya too value return karega.
    cout<<arr+1<<" "<<*arr+1 <<" "<<*(arr + 1)<<endl;
    //arrey ka index 0 se start kiyu hota hai ans is it create a difference btw an array and calling an array.
    // bcz array give ans like this arr[2] = *(arr + 2);
    int i = 2;
    cout<<arr[i]<<" "<<*(arr+i)<<endl;
    cout<<i[arr]<<" "<<*(i+arr)<<endl;
    cout<<endl;

    cout <<sizeof(arr)<<" "<<sizeof(pt)<<endl;
    cout <<sizeof(*arr)<<" "<<sizeof(*pt)<<endl;
    cout <<sizeof(&arr)<<" "<<sizeof(&pt)<<endl;

    int a[20] = {1,2,3,4};
    // a = a+1; ye nahi kr sakte error ayega ;
    int *p = a;
    cout<<a<<endl<<&p<<endl;
    p++;
    cout<<p<<" "<<*p<<endl;
      
     
}