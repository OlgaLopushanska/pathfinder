#include "pathfinder.h"
#include "libmx.h"

int mx_atoi(char *str) {
    int n = mx_strlen(str);
    long t = 0;
    char *rst = NULL;
 
    if (str[0] != '-')
        rst = str;
    else {
        rst = str + 1;
        n--;
    }
    for (int a = 0; a < n; a++) {
        t = t + (rst[a] - '0') * mx_pow(10.0, (n - 1 - a));
        if (t > 2147483647)
            t = 0;
    }
    return str[0] != '-' ? t : -t;
}
