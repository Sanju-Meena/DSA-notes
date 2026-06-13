#include <iostream>
using namespace std;
// ptr store address and *ptr means value at address ptr;

void update(int **ptr1){ 
    // ptr1++;
    // kuch change hoga - No.

    // (*ptr1)++;
    // kuch change hoga - Yes.

    // (**ptr1)++;
    // kuch change hoga - Yes.
}

int main()
{
    int i = 5;
    int *ptr = &i;
    int **ptr1 = &ptr;

    cout <<"i = "<< i << endl <<"Address of i = "<< &i << endl;
    cout <<"ptr = "<< ptr << endl <<"Address of ptr = "<< &ptr << endl;
    cout <<"ptr1 = "<< ptr1 << endl <<"Address of ptr1 = "<< &ptr1 << endl;
    // cout << i << " " << ptr << endl;
    // cout << ptr1 << " " << &ptr1 << endl;
    // cout << *ptr1 << " " << **ptr1 << endl;
    // // i ki value 5 address 8;
    // // ptr ki value 4 address 0;
    // // ptr1 ki value 0 address 00;

     int ***ptr2 = &ptr1; //* ko pass likho int k ya ptr k pass likho dono same baat hai;
    // cout << ptr2 << endl;

    // // How many ways u can print the value of i;
    // cout << i << " " << *ptr << " " << **ptr1 << " " << ***ptr2 << endl;

    // // How many ways u can print the address of i;
    // cout << &i << " " << ptr << " " << *ptr1 << " " << **ptr2 << endl;
    cout<<endl;
    
    cout<<"Now goes to update function "<<endl;
    cout<<i<<" "<<ptr<<" "<<ptr1<<" "<<ptr2<<endl;
    update(ptr1);
    cout<<i<<" "<<ptr<<" "<<ptr1<<" "<<ptr2<<endl;

}