#include <stdio.h>
#include <string.h>
#define MAX 256
int shift_table[MAX];
void shift_table_comp(char p[]) {
    int m = strlen(p);
    for (int i = 0; i < MAX; i++) shift_table[i] = m;
    for (int j = 0; j < m - 1; j++) shift_table[(unsigned char)p[j]] = m - 1 - j;
}
int horspool(char t[], char p[]) {
    int n = strlen(t);
    int m = strlen(p);
    shift_table_comp(p);
    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && p[m - 1 - k] == t[i - k]) k++;
        if (k == m) return i - m + 1;
        else i += shift_table[(unsigned char)t[i]];
    }
    return -1;
}
int main() {
    char text[1000], pattern[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';
    int pos = horspool(text, pattern);
    if (pos != -1) printf("Pattern found starting at index %d\n", pos);
    else printf("Pattern not found\n");
    return 0;
}
