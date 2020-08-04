#include "pathfinder.h"
#include "libmx.h"
 
static void path_error2_dop2(char *s);
 
static void path_error2_dop(char *s);
 
void mx_path_error2(char *s) {
    int comma = 0;
    int dash = 0;
    int a = 1;
    int n = 1;
 
    for (; s[a] != '\0'; a++) {
        if (s[a] == '\n') {
            n++;
            comma = 0;
            dash = 0;
        }
        if (s[a] == '-')
            dash++;
        if (s[a] == ',')
            comma++;
        if (comma > 1 && dash > 1)
            mx_path_error_output(n, s);
    }
    path_error2_dop2(s);
    path_error2_dop(s);
}
 
static void path_error2_dop(char *s) {
    int a = 1;
    int n = 1;

    while (s[a] != '\0') {
        if (s[a] == '\n')
            n++;
        if (mx_isalpha(s[a]) && (!mx_isalpha(s[a + 1])
            && s[a + 1] != '-' && s[a + 1] != ','))
            mx_path_error_output(n, s);
        if (s[a] == '\n' && s[a + 1] == '\n') 
            mx_path_error_output(n, s);
        if (s[a] == ',' && mx_isdigit(s[a + 1]) == 0)
            mx_path_error_output(n, s);
        if (s[a] == '\n' && (!mx_isalpha(s[a + 1]) && s[a + 1] != '\0'))
            mx_path_error_output(n, s);
        if (s[a] == '-' && !mx_isalpha(s[a + 1]))
            mx_path_error_output(n, s);
        a++;
    }
    return;
}

static void path_error2_dop2(char *s) {
    int a = 1;
    int n = 1;

    while (s[a] != '\0') {
        if (s[a] == '\n')
            n++;
        if (!mx_isdigit(s[a]) && !mx_isalpha(s[a]))
            if(s[a] != '-' && s[a] != ',')
                if(s[a] != '\n')
                    mx_path_error_output(n, s);
        if (mx_isdigit(s[a]) == 1
            &&(mx_isdigit(s[a + 1]) == 0 && s[a + 1] != '\n'))
            mx_path_error_output(n, s);
        a++;
    }
}

