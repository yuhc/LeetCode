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
void getReturnSize(int k, int colSize, int* returnSize, int* longest, const int* candidates, const int candidatesSize, const int target) {
    if (!target) {
        (*returnSize)++;
        if (colSize > *longest) *longest = colSize;
        return;
    }

    int i;
    for (i = k; i < candidatesSize; i++) {
        if (candidates[i] > target) break;
        getReturnSize(i, colSize+1, returnSize, longest, candidates, candidatesSize, target-candidates[i]);
    }
}

void dfs(int k, int* oneAns, int colSize, int*** ans, int** columnSizes, int* size, const int* candidates, const int candidatesSize, const int target) {
    if (!target) {
        (*columnSizes)[*size] = colSize;
        (*ans)[*size] = (int*) malloc(colSize*sizeof(int));
        memcpy((*ans)[(*size)++], oneAns, colSize*sizeof(int));
        return;
    }

    int i;
    for (i = k; i < candidatesSize; i++) {
        if (candidates[i] > target) break;
        oneAns[colSize] = candidates[i];
        dfs(i, oneAns, colSize+1, ans, columnSizes, size, candidates, candidatesSize, target-candidates[i]);
    }
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    if (candidatesSize > 1) qsort(candidates, candidatesSize, sizeof(int), cmp);

    *returnSize = 0;
    int longest  = 0;
    getReturnSize(0, 0, returnSize, &longest, candidates, candidatesSize, target);

    int** ans    = (int**) malloc((*returnSize)*sizeof(int*));
    int*  oneAns = (int*)  malloc(longest*sizeof(int));
    *columnSizes = (int*)  malloc((*returnSize)*sizeof(int));
    int   size   = 0;
    dfs(0, oneAns, 0, &ans, columnSizes, &size, candidates, candidatesSize, target);

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
    }

    return 0;
}
