#include<stdio.h>
int main(){
    int n,a=0,b=1,c,sum=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        c=a+b;
        a=b;
        b=c;        
        sum=sum+b;
    }
    printf("%d\n",(sum+1));
}
