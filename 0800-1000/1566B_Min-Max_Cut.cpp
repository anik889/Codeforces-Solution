#include <stdio.h>
#include<string.h>
int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}  
int main() {
    int t,a,b;  
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {  
        char str[100001];    
        scanf("%s",str);
        a=0,b=0;       
        for (int i=0;i<strlen(str);i++){
            if (str[i] == '0') 
                a=1;
            else if (str[i] != '0' && a == 1) {
                b++;
                a=0;
            }
        }
        if (str[strlen(str)-1] == '0') {
            b++;
        }
        printf("%d\n",min(b,2));
    }
    return 0;
}
