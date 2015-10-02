/* LC ID :  #39
 * Type  :  DFS
 * Author:  Hangchen Yu
 * Date  :  09/02/2015
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
*/
void dfs(int k, int* oneAns, int colSize, int*** ans, int** columnSizes, int* returnSize, const int* candidates, const int candidatesSize, const int target) {
    if (!target) {
        //columnSize
        *columnSizes = (int*) realloc(*columnSizes, (*returnSize+1)*sizeof(int));
        (*columnSizes)[*returnSize] = colSize;
        //combinationSum
        *ans = (int**) realloc(*ans, (*returnSize+1)*sizeof(int*));
        (*ans)[*returnSize] = (int*) malloc(colSize*sizeof(int));
        memcpy((*ans)[*returnSize], oneAns, colSize*sizeof(int));
        //returnSize
        (*returnSize)++;
        return;
    }

    int i;
    for (i = k; i < candidatesSize; i++) {
        if (candidates[i] > target) break;
        oneAns[colSize] = candidates[i];
        dfs(i, oneAns, colSize+1, ans, columnSizes, returnSize, candidates, candidatesSize, target-candidates[i]);
    }
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int** ans    = (int**) malloc(0*sizeof(int*));
    int*  oneAns = (int*) malloc(candidatesSize*sizeof(int));
    *columnSizes = (int*) malloc(0*sizeof(int));
    *returnSize  = 0;

    qsort(candidates, candidatesSize, sizeof(int), cmp);
    dfs(0, oneAns, 0, &ans, columnSizes, returnSize, candidates, candidatesSize, target);
    free(oneAns);
    return ans;
}


int main() {
    int* returnSize; int** columnSizes = (int**) malloc(sizeof(int*)); int* candidates;
    int candidatesSize, target;
    scanf("%d%d", &candidatesSize, &target);
    candidates = (int*) malloc(candidatesSize*sizeof(int));
    int i; for (i = 0; i < candidatesSize; i++)
        scanf("%d", &candidates[i]);

    int** ans = combinationSum(candidates, candidatesSize, target, columnSizes, returnSize);
    int j; for (i = 0; i < *returnSize; i++) {
        for (j = 0; j < (*columnSizes)[i]; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
        free(ans[i]);
    }
    free(*columnSizes);

    return 0;
}
