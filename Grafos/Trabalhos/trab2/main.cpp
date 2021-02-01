#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 500000

int hour;
int tree[N];

struct Grafo
{
    int x;
    int y;
    int v;
};
Grafo grafo[N];

int vintage(const void *a, const void *b)
{
    return (*(struct Grafo *)a).v - (*(struct Grafo *)b).v;
}

void update(int n)
{
    int i;
    for (i = 0; i <= n; ++i)
    {
        tree[i] = i;
    }
}

int searching(int x)
{
    if (tree[x] != x)
    
        tree[x] = searching(tree[x]);
    
    return tree[x];
}

int branch(int x, int y, int p){

    int i, j;
    i = searching(x);
    j = searching(y);
    if (i != j)
    {
        hour -= grafo[p].v;
        if (i > j)
        
            tree[i] = j;
        
        else
        
            tree[j] = i;
        
        return 1;
    }
    return 0;
}

int main()
{
    int m, n;
    int i;

    while (1)
    {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0)
            break;
        memset(&grafo, 0, sizeof(grafo));
        i = 0;
        hour = 0;
        while (i < n)
        {
            scanf("%d %d %d", &grafo[i].x, &grafo[i].y, &grafo[i].v);
            hour += grafo[i].v;
            i++;
        }
        update(m);

        qsort(grafo, n, sizeof(grafo[0]), vintage);
        for (i = 0; i < n; ++i) branch(grafo[i].x, grafo[i].y, i);
        
        printf("%d\n", hour);
    }
    return 0;
}