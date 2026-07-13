#include<stdio.h>
int main(){
    int a , b ;
    printf("enter the value of a and b\n");
    scanf("%d%d",&a,&b);
    int count = 0 ;
     while(a!=0){
        int c = a&1 ;
        count = count + c;
        a = a/2;
     }
     
while(b!=0){
        int d = b&1 ;
        count = count + d;
        b = b/2;
     }
     printf("count is %d",count);
}