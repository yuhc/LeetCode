/* LC ID :  #72
 * Type  :  Dynamic Programming
 * Author:  Hangchen Yu
 * Date  :  09/15/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//copy the Solution class here
#define min(a,b) a>b?b:a

int minDistance(char* word1, char* word2) {
    int n = strlen(word1), m = strlen(word2);
    int f[n+1][m+1], i = 0, j;
    for (; i <= n; i++) f[i][0] = i;
    for (i = 0; i <= m; i++) f[0][i] = i;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            f[i][j] = INT_MAX;
            if (word1[i-1] == word2[j-1])
                f[i][j] = min(min(f[i-1][j-1], f[i-1][j]+1), f[i][j-1]+1);
            else {
                f[i][j] = min(f[i][j], f[i-1][j-1]+1);
                f[i][j] = min(f[i][j], f[i-1][j]+1);
                f[i][j] = min(f[i][j], f[i][j-1]+1);
            }
        }

    return f[n][m];
}

int main() {
    char *word1=(char*)malloc(1000), *word2=(char*) malloc(1000);
    scanf("%s", word1);
    scanf("%s", word2);
    int ans = minDistance(word1, word2);
    printf("%d\n", ans);

    return 0;
}
