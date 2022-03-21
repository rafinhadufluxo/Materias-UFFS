#include <stdio.h>

int main() {

    char frase[50] = { 'F', 'A', 'C', 'E' };
    int n, s = 0, t = 4;
    char f1[2], f2[2], f3[2], f4[2];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%s%s%s%s", f1, f2, f3, f4);
        if (f1[0] == frase[t-1] && f2[0] == frase[t-2] && f3[0] == frase[t-3] && f4[0] == frase[t-4]) {
            t -= 4;
            if (t == 0)
                frase[0] = 'F', frase[1] = 'A', frase[2] = 'C', frase[3] = 'E', t = 4;
            s++;
        } else {
            frase[t] = f1[0], t++, frase[t] = f2[0], t++, frase[t] = f3[0], t++, frase[t] = f4[0], t++;
        }
    }

    printf("%d\n", s);
    return 0;
}