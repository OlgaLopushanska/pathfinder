#include "pathfinder.h"
#include "libmx.h"

int mx_path_error_output(int n, char *s) {
    char *out = mx_strnew(200);
    char *num = NULL;

    if(!s)
        free(s);
    out = mx_strcat(out, "error : line ");
    num = mx_itoa(n);
    out = mx_strcat(out, num);
    free(num);
    out = mx_strcat(out, " is not valid\n");
    write(2, out, mx_strlen(out));
    free(out);
    exit(0);
    return 0;
}
