#include "pathfinder.h"
#include "libmx.h"

int main(int args, char *argv[]) {
    char *s = NULL;
    char **islands = NULL;
    int n = 0;
    int **matrix = NULL;
    int ***res = NULL;

    s = mx_path_error_first(args, argv);
    islands = mx_path_error(s, &n);
    matrix = mx_path_array(islands, s, n);
    res = mx_find_path(matrix, n);
    mx_path_print(res, matrix, islands, n);
    return 0;
}
