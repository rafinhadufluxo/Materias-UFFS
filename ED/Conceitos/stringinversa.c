#include <stdio.h>
#include <string.h>
/*
    invertendo string, apenas isso!

*/
int main() {
    char str1[50], str2[50];
    int i, j = 0;
    

    fgets(str1,sizeof(str1),stdin);
    str1[strcspn(str1, "\n")] = '\0';
    for(i = (strlen(str1) - 1); i >= 0; i--) {
        str2[j] = str1[i];
        j++;
    }
    str2[j] = 0;
    printf("String invertida: %s\n", str2);
    return 0;
}