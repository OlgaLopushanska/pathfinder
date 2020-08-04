#include "pathfinder.h"
#include "libmx.h"

int mx_new_line(int line, int *p, int *r) {
    *p = -1;
    *r = -1;
    line++;
    return line;
}
