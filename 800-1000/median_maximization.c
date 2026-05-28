#include<stdio.h>
#include<math.h>
int main() {
    int n,s,t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        scanf("%d %d",&n,&s);
        int ans=s/((n/2)+1);
        printf("%d\n",ans);
    }
}
