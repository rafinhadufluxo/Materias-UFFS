#include<stdio.h>
#include<string.h>
int main()
{
    int i,n;
    char ch[35];
    strcpy(ch, "LIFE IS NOT A PROBLEM TO BE SOLVED");
    while(scanf("%d",&n)!=EOF){
        for(i = 0;i < n;i++){
            printf("%c",ch[i]);
        }
        printf("\n");
    }
    return 0;
}