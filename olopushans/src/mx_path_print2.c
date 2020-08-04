#include "pathfinder.h"
#include "libmx.h"

static char *path_print_dop(int **matrix, char *out, int a, int b) ;

static void print_first_line(int **ways, char **islands, int n, int a);

static void print_second_line(int **ways, char **islands, int n, int a);

static void print_third_line(int **ways, int **matrix, int n, int a);

void path_print2(int **ways, int **matrix, char **islands, int n) {
    int n_way = 1;

    for (n_way = 0; ways[n_way][0] != -1; n_way++);
    n_way--;
    for (int a = 0; a <= n_way; a++) {
        print_first_line(ways, islands, n, a);
        print_second_line(ways, islands, n, a);
        print_third_line(ways, matrix, n, a);
        write(1,"========================================\n", 41); 
    }
    mx_free_array2((void**)matrix, n);
}

static char *path_print_dop(int **matrix, char *out, int a, int b) {
    char *num = NULL;

    if(matrix !=NULL)
        num = mx_itoa(matrix[a][b]);
    else
        num = mx_itoa(a);
    out = mx_strcat(out, num);
    free(num);
    return out;
 }

static void print_first_line(int **ways, char **islands, int n, int a) {
    char *out = mx_strnew(200);
    int b = 0;

    write(1,"========================================\n", 41);
    out = mx_strcat(out, "Path: ");
    out = mx_strcat(out, islands[ways[a][0]]);
    out = mx_strcat(out, " -> ");
    for (b = 0; ways[a][b+1] != -1 && b+1 < n; b++)
        ;
    out = mx_strcat(out, islands[ways[a][b]]);
    out = mx_strcat(out, "\n");
    write(1, out, mx_strlen(out));
    mx_write_zero(out);
    free(out);
 }

static void print_second_line(int **ways, char **islands, int n, int a) {
    char *out = mx_strnew(200);
    int b = 0;

    out = mx_strcat(out, "Route: ");
    out = mx_strcat(out, islands[ways[a][0]]);
    for (b = 1; ways[a][b] != -1  && b < n; b++) {
        out = mx_strcat(out, " -> ");
        out = mx_strcat(out, islands[ways[a][b]]);
    } 
    out = mx_strcat(out, "\n");
    write(1, out, mx_strlen(out));
    mx_write_zero(out);
    free(out);
 }

static void print_third_line(int **ways, int **matrix, int n, int a) {
    char *out = mx_strnew(200);
    int sum = 0;
    int b = 0;

    out = mx_strcat(out, "Distance: ");
    out = path_print_dop(matrix, out, ways[a][0], ways[a][1]);
    if (ways[a][2] != -1) {
        sum = matrix[ways[a][0]][ways[a][1]];
        for (b = 2; ways[a][b] != -1 && b < n; b++) {
            out = mx_strcat(out, " + ");
            out = path_print_dop(matrix, out, ways[a][b - 1], ways[a][b]);
            sum = sum + matrix[ways[a][b - 1]][ways[a][b]];
        }
        out = mx_strcat(out, " = ");
        out = path_print_dop(NULL, out, sum, -1);
    }
    out = mx_strcat(out, "\n");
    write(1, out, mx_strlen(out));
    mx_write_zero(out); 
    free(out);
}
