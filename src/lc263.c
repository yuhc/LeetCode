/* LC ID :  #263
 * Type  :  Math
 * Author:  Hangchen Yu
 * Date  :  09/12/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//copy the Solution class here
bool isUgly(int num) {
    if (num <= 0) return false;

    while (num > 1 && num%2 == 0)
        num /= 2;
    while (num > 1 && num%3 == 0)
        num /= 3;
    while (num > 1 && num%5 == 0)
        num /= 5;
    return (num==1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", isUgly(n)?1:0);
    return 0;
}
