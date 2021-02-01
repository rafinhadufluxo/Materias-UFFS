#include <stdio.h>
int fat(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fat(n - 1);
}
int main()
{
    int num;
    printf("\nDigite um valor para n: ");
    scanf("%d", &num);
    printf("\nO fatorial de %d é %d", num, fat(num));
    return 0;
}