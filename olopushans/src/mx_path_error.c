#include "pathfinder.h"
#include "libmx.h"

static int read_number(char *s, int c);
 
char **mx_path_error(char *s, int *n) {
    char **res = NULL;
    char *errno6 = "error: invalid number of islands\n";

    if (!mx_isdigit(s[0]) && !(s[0] == '-' && mx_isdigit(s[1]))) 
        mx_path_error_output(1, s);
    *n = read_number(s, '\n');
    if (*n == 0)
        exit(0);
    if (*n == 1)
        exit(0);
    if (*n < 0) {
        write(2, errno6, mx_strlen(errno6));
        exit(0);
    }
    if (mx_isdigit(s[0]) == 1 && mx_isdigit(s[1]) == 0 && s[1] != '\n') 
        mx_path_error_output(1, s);
    mx_path_error2(s);
    res = mx_path_error3(s, *n);
    return res;
}

static int read_number(char *s, int c) {
    char *t = mx_strnew(mx_strlen(s));
    int n = -1;

    for (unsigned long a = 0; s[a] != c; a++)
        if(mx_isdigit(s[a]) || (a == 0 && s[0] == '-'))
            t[a] = s[a];
        else 
            mx_path_error_output(1, s);
    n = mx_atoi(t);
    free(t);
    return n;
}
