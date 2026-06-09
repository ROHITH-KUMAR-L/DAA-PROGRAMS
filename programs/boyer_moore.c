#include <stdio.h>
#include <string.h>
#define MAX 256
int bad_char[MAX];
void compute_bad_char(char p[], int m) {
    for (int i = 0; i < MAX; i++) bad_char[i] = m;
    for (int i = 0; i < m - 1; i++) bad_char[(unsigned char)p[i]] = m - 1 - i;
}
int search(char t[], char p[]) {
    int n = strlen(t);
    int m = strlen(p);
    compute_bad_char(p, m);
    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && p[j] == t[s + j]) j--;
        if (j < 0) {
            return s; // match found
        } else {
            int shift = bad_char[(unsigned char)t[s + j]] - (m - 1 - j);
            s += (shift > 0) ? shift : 1;
        }
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
    int pos = search(text, pattern);
    if (pos != -1) printf("Pattern found starting at index %d\n", pos);
    else printf("Pattern not found\n");
    return 0;
}
