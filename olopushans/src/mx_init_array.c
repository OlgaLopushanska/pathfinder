#include "pathfinder.h"
#include "libmx.h"

int **mx_init_array(int row, int col, int value) {
    int **matrix = NULL;

    matrix = (int**)malloc(row * sizeof(int**)); 
    for (int a = 0; a < row; a++) {
        matrix[a] = (int*)malloc(col * sizeof(int*));
        for (int b =0; b < col; b++) 
            matrix[a][b] = value;
    }
    return matrix;
}
