#include <stdio.h>

int main()
{
    int N, H[10000];

    while (1) {
        int i, peaks = 0;

        scanf("%d", &N);
        if (!N)
            break;

        for (i = 0; i < N; ++i)
            scanf("%d", &H[i]);

        for (i = 0; i < N; ++i) {
            int prev = ((i - 1) % N + N) % N;
            int next = (i + 1) % N;

            if (H[i] > H[prev] && H[i] > H[next] ||
                H[i] < H[prev] && H[i] < H[next])
                ++peaks;
        }

        printf("%d\n", peaks);
    }

    return 0;
}