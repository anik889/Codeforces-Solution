   /*-------------------------*\
   |~Codeforces--problem--263A~|
   \*-------------------------*/
#include<stdio.h>
#define abs(a) (a<0)?(-(a)):(a)
int main()
{
    int i,j,k,l;
    int a[5][5];
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            if(a[i][j]==1) {
                k=abs(3-(i+1));
                l=abs(3-(j+1));
            }
            else    continue;
        }
    }
    printf("%d",(k+l));
    return 0;
}