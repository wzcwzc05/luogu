#include <stdio.h>
#include <string.h>
int main() {
    char str[10001];
    gets(str);
    int n = strlen(str);
    for (int i = 0; i < n;) {
        if ((unsigned char)str[i] >= 0x80) {
            if (str[i] * 256 + str[i + 1] !=
                str[n - 1 - i] + str[n - i - 2] * 256) {
                printf("NO\n");
                return 0;
            }
            i += 2;
        } else {
            if (str[i] != str[n - 1 - i]) {
                printf("NO\n");
                return 0;
            }
            i += 1;
        }
    }
    printf("YES\n");
    return 0;
}