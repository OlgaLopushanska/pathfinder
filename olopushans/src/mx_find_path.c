#include "pathfinder.h"
#include "libmx.h"

int ***mx_find_path(int **matrix, int n)   {
    int ***res = (int ***)malloc (sizeof(int***)*n);
    int **connect = (int **)malloc (sizeof(int**)*n);

    for (int a = 0; a < n; a++) {
        connect[a] = (int *)malloc (sizeof(int*)*(n + 1));
        connect[a][0] = 0;
        for (int b = 0; b < n; b++) {
            connect[a][b + 1] = -1;
            if (matrix[a][b] != 0) {
                connect[a][0]++;
                connect[a][connect[a][0]] = b;
            }
        }
    }
    for (int a = 0; a < n; a++)
        res[a] = mx_dextra_alg(matrix, connect, n, a);
    mx_free_array2((void**)connect, n);
    return res;
}

