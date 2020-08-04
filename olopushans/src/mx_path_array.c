#include "pathfinder.h"
#include "libmx.h"

static int max_len(char **in);

static int read_islands(char **islands, char *s, int *p, int *r);

static int read_length(int **matrix, char *s, int *p, int *r, int line);

int **mx_path_array(char **islands, char *s, int n) {
    int **matrix = mx_init_array(n, n, 0);
    int p = -1;
    int r = -1; 
    int line = 1;

    for (int a = 0; s[a] != '\0'; a++) {
        if (mx_isalpha(s[a]) == true)
            a = a + read_islands(islands, &s[a], &p, &r);
        if (mx_isdigit(s[a]) == true && p != -1 && r != -1) 
            a = a + read_length(matrix, &s[a], &p, &r, line);
        line = s[a] == '\n' ?  mx_new_line(line, &p, &r) : line;
    }
    free(s);
    return matrix;
}

static int max_len(char **in) {
    int max_l = 0;
    int max_temp = 0;

    for (int a = 0; in[a] != NULL; a++) {
        max_temp = mx_strlen(in[a]);
        max_l = (max_temp > max_l) ? max_temp : max_l;
    }
    return max_l;
}

static int read_islands(char **islands, char *s, int *p, int *r) {
    int res = 0;
    int b = 0;
    int c = 0;
    char *u = mx_strnew(max_len(islands));

    for (int a = 0; s[a] != '\0' && a >= 0; a++) {
        if (mx_isalpha(s[a]) == true)
            u[c++] = s[a];
        if (mx_isalpha(s[a]) == false && u[0] != '\0') {
            for (b = 0; islands[b] != NULL; b++)
                c = mx_strcmp(u, islands[b]) == 0 ? b : c;
            *r = *p != -1 ? c : *r;
            *p = *p == -1 ? c : *p;
            c = 0;
            res = a;
            mx_write_zero(u);
            a = *r != -1 ? -5 : a;
        }
    }
    free(u);
    return res;
}

static int read_length(int **matrix, char *s, int *p, int *r, int line) {
    int a = 0;
    int b = 0;
    char *t = mx_strnew(20);

    for (int c = 0; s[c] != '\0' && c >= 0; c++) {
        if (mx_isdigit(s[c]) == true && *p != -1 && *r != -1)
            t[b++] = s[c];
        if (mx_isdigit(s[c]) == false && b > 0 && *p != -1 && *r != -1) {
            if (mx_atoi(t) == 0) {
                free(t);
                mx_path_error_output(line, s);
            }
            matrix[*p][*r] = mx_atoi(t);
            matrix[*r][*p] = matrix[*p][*r];
            a = c;
            c = -5;
        }
    }
    free(t);
    return a;
}
