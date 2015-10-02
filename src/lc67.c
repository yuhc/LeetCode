/* LC ID :  #67
 * Type  :  String
 * Author:  Hangchen Yu
 * Date  :  09/11/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

//copy the Solution class here
#define max(x, y) x>y?x:y

char* addBinary(char* a, char* b) {
    int   lena = strlen(a);
    int   lenb = strlen(b);
    if (!lena) return b;
    if (!lenb) return a;

    short aa[lena], bb[lenb];
    int   i = 0;
    for (; i < lena; i++)
        aa[lena-i-1] = a[i]-'0';
    for (i = 0; i < lenb; i++)
        bb[lenb-i-1] = b[i]-'0';

    int   len = max(lena, lenb);
    short t = 0, nxt = 0;
    char  *ans = (char*) calloc(len+2, sizeof(char));
    for (i = 0; i < len; i++) {
        if (i >= lena) t = nxt + bb[i];
        else if (i >= lenb) t = nxt+aa[i];
        else t = nxt + aa[i] + bb[i];
        nxt = t >> 1;
        ans[i] = (t&1)+'0';
    }
    if (nxt) ans[len++] = '1';
    ans[len] = '\0';

    for (i = 0; i <= (len-1)/2; i++) {
        char t = ans[i];
        ans[i] = ans[len-i-1];
        ans[len-i-1] = t;
    }

    return ans;
}

int main() {
    char a[10], b[10];
    scanf("%s", a);
    scanf("%s", b);
    char *c = addBinary(a, b);
    printf("%s\n", c);

    return 0;
}
