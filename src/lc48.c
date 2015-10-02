/* LC ID :  #48
 * Type  :  Mathematics
 * Author:  Hangchen Yu
 * Date  :  09/08/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

//copy the Solution class here
//x = y0, y = -x0
//let the bottom right corner as (-1,1)
//in place: swap (i,j), (j,n-i-1), (n-i-1, n-j-1), (n-j-1, i)
//successively
void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int n = matrixRowSize;
    int i, j;
    for (i = 0; i < n/2; i++)
        for (j = 0; j < (n+1)/2; j++) {
            int t = matrix[i][j];
            matrix[i][j] = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            matrix[j][n-i-1] = t;
        }
}

int main() {
    int n;
    int* matrix[n];
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(n*sizeof(int));
        for (j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }
    rotate(matrix, n, n);
     for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
     }
    return 0;
}
