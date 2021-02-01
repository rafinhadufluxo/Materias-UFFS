#include <stdio.h>

int main(void)
{
    int n, s, i;
    scanf("%d", &n);
    s = 0;
    i = 0;
    while (i < n)
    {
        i = i + 1;
        s = s + i;
    }
    printf("%d\n", s);
    return 0;
}