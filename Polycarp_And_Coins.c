#include<stdio.h>
int main()
{
    int k,a,b,n;
    scanf("%d",&k);
    int i;
    for(i=1;i<=k;i++){
        scanf("%d",&n);
        a=n/3;
        b=a+1;
        
        if((n%3)==1){
            printf("%d %d\n",b,a);
        }
        else if((n%3)==2){
            printf("%d %d\n",a,b);
        }
        else{
            printf("%d %d\n",a,a);
        }
    }
    return 0;
}
