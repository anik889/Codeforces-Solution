#include <stdio.h>
#include<string.h>
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        char s[n];
        scanf("%s",s);
        int ans = 0;
        for(int i=0;i<n;i++) {
            if (s[i] != '0') {
                ans += (s[i] - ('0'));
                if (i != n - 1) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
