#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    char a[101];
    for(int i=1; i<=t; i++) {
        scanf("%s",a);
        if(strlen(a)>10) {
            printf("%c%ld%c\n",a[0],(strlen(a)-2),a[strlen(a)-1]);
        }
        else {
            printf("%s\n",a);
        }
    }
    return 0;
}
