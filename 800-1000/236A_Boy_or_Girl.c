/*------------------------*\
|~Codeforces--problem-236A~|
\*------------------------*/
#include<stdio.h>
#include<string.h>
int main()
{
    char s[101];
    int count[26]={0},sum=0;
    scanf("%s",s);//input of string
    //cheackig if the given string contains even letters
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='a' && s[i]<='z') 
/*taking count of the latter of string 
by subtracting the character with a,we got
the ascii value of that latter and then we 
increment it as the count array is initialized as 0*/
          count[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){            
        if(count[i]>=2)    sum=sum+(count[i]/count[i]);
        else    sum=sum+count[i];
    }    
    if(sum%2==0)   printf("CHAT WITH HER!");
    //else condition of if
    else    printf("IGNORE HIM!");
    return 0;
}
