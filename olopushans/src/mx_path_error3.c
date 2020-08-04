#include "pathfinder.h"
#include "libmx.h"

static int count_islands(char *islands, char ***res);

static char **count_islands_dop(char **temp, int *temp2, int *u);

char **mx_path_error3(char *s, int n) {
    char *islands = mx_strnew(mx_strlen(s));
    char **res = NULL;
    int a = 1;  
    int b = 0;
    char *errno6 = "error: invalid number of islands\n";
    
    for (; s[a] != '\0'; a++) { 
        if (mx_isalpha(s[a]) == 1)
            islands[b++] = s[a];
        if (mx_isalpha(s[a]) != 1  && mx_isalpha(s[a - 1]) == 1)
            islands[b++] = ' ';
    }
    islands[b - 1]=' ';
    islands[b]='\0';
    if ((a = count_islands(islands, &res)) != n) {
        free(s);
        mx_free_array2((void**)res, a);
        write(2, errno6, mx_strlen(errno6));
        exit(0);
    }
    return res;
}
 
static int count_islands(char *islands, char ***res) {  
    int u = 0;
    char **temp = NULL;
    int *temp2 = NULL;
    int a = 0;
    int b = 0;
   
    temp = mx_strsplit(islands, ' ');
    for (u = 0; temp[u] != NULL; u++)
        ;
    temp2 = (int*) malloc(sizeof(int*) * u);
    for (a = 0; a < u; a++)
        temp2[a] = 0;
    temp2[1] = 1;
    for (a = 0; temp[a] != NULL; a++){
        temp2[a] = 1;
        for ( b = 0; b < a; b++)
            temp2[a] = mx_strcmp(temp[b], temp[a]) == 0 ? 0 : temp2[a];
    }
    (*res) = count_islands_dop(temp, temp2, &u);
    free(islands);
    return u;
}

static char **count_islands_dop(char **temp, int *temp2, int *u) {
    char **res = NULL;
    int pr = 0;
    int a = 0;
    int t = 0;

    for(a = 0; a < *u; a++)
        t = temp2[a] ? t + 1 : t;
    res = (char**) malloc(sizeof(char**) * (t + 1));
    for(a = 0; a < *u; a++){
        if(temp2[a]){
            res[pr] = mx_strnew(mx_strlen(temp[a]));
            for(int b = 0; b < mx_strlen(temp[a]); b++)
                res[pr][b] = temp[a][b];
            pr++;
        }
    }
    res[pr] = NULL;
    mx_free_array2((void**)temp, *u + 1); 
    free(temp2);
    *u = t;
    return res;
}

