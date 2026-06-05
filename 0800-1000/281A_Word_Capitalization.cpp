/*|••••••••••••••••••••••••••••••••••|*/
/*|Simple Programme for  converting a|*/
/*|letter from uppercase to lowercase|*/
/*|••••••••••••••••••••••••••••••••••|*/
#include<stdio.h>
#include<string.h>
int main()
{
    char character[1000];
    scanf("%s",&character);
    if(character[0]>='a' && character[0]<='z')
    {
        character[0]=character[0]+'A'-'a';
        //the sum of ASCII value of given char and 'A' is subtract
        //with 'a' whice provides uppercase letter
        printf("%s",character);
    }
    else{
        printf("%s",character);
    }    
}
