/**Bismillahir Rahmanir Rahim.**/

#include <stdio.h>
#include <string.h>
int main()
{
    int a,b,c;
    char aa[]="tesoura", bb[]="papel", cc[]="pedra", dd[]="lagarto", ee[]="Spock";
    char a1[10],a2[10];
    scanf("%d",&a);
    for(b=1; b<=a; b++)
    {
        scanf("%s%s", a1,a2);
        if(0==strcmp(a1,a2))
            printf("Caso #%d: De novo!\n", b);
        else if(0==strcmp(a1,aa))
        {
            if((0==strcmp(a2,bb)) || (0==strcmp(a2,dd)))
                printf("Caso #%d: Bazinga!\n", b);
            else if((0==strcmp(a2,cc)) || (0==strcmp(a2,ee)))
                printf("Caso #%d: Raj trapaceou!\n", b);
        }
        else if(0==strcmp(a1,bb))
        {
            if((0==strcmp(a2,cc)) || (0==strcmp(a2,ee)))
                printf("Caso #%d: Bazinga!\n", b);
            else if((0==strcmp(a2,aa)) || (0==strcmp(a2,dd)))
                printf("Caso #%d: Raj trapaceou!\n", b);
        }
        else if(0==strcmp(a1,cc))
        {
            if((0==strcmp(a2,aa)) || (0==strcmp(a2,dd)))
                printf("Caso #%d: Bazinga!\n", b);
            else if((0==strcmp(a2,bb)) || (0==strcmp(a2,ee)))
                printf("Caso #%d: Raj trapaceou!\n", b);
        }
        else if(0==strcmp(a1,dd))
        {
            if((0==strcmp(a2,bb)) || (0==strcmp(a2,ee)))
                printf("Caso #%d: Bazinga!\n", b);
            else if((0==strcmp(a2,cc)) || (0==strcmp(a2,aa)))
                printf("Caso #%d: Raj trapaceou!\n", b);
        }
        else if(0==strcmp(a1,ee))
        {
            if((0==strcmp(a2,aa)) || (0==strcmp(a2,cc)))
                printf("Caso #%d: Bazinga!\n", b);
            else if((0==strcmp(a2,bb)) || (0==strcmp(a2,dd)))
                printf("Caso #%d: Raj trapaceou!\n", b);
        }
    }
    return 0;
}