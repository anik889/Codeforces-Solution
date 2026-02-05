#include <stdio.h>
int main()
{
    int n,i,j,k,ans=0;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    /*check*/
    for(i=0; i<n; i++) {
        if(arr[i]>0 && arr[i]>=arr[k-1]) {
            ans=ans+1;
        }
    }
    printf("%d",ans);
    return 0;
}
