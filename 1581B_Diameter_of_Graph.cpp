#include<stdio.h>
#include<math.h>
int main() {
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        long long int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(b>a*(a-1)/2 || b<a-1)
            printf("NO\n");
        else if(a==2 && c<=2)
            printf("NO\n");
        else if(a==1 && c<=1)
            printf("NO\n");
        else if(a>=3&&(b<a-1 || b<a*(a-1)/2&&c<=3 || b>=a*(a-1)/2&&c<=2))
            printf("NO\n");
        else
            printf("YES\n");
    }
}