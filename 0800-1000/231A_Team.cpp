#include<stdio.h>
int main()
{
    int n,a,b,c,sum,count=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=i; j++) {
            scanf("%d %d %d",&a,&b,&c);
            sum=a+b+c;
        }
        if(sum>1)
            count=count+1;
        else
            continue;
    }
    printf("%d\n",count);
}
