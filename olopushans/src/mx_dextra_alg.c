#include "pathfinder.h"
#include "libmx.h"

static int **initialize(int *min, int *vis, int st, int n);

static int *minval(int **in, int *min, int st, int n);

static int next_index(int **in, int *vis, int st, int n);

static int **create_way(int **res, int *min, int *vis, int n);

int **mx_dextra_alg(int **in, int **cn, int n, int st) {
    int *min = (int *)malloc (sizeof(int*)*n);
    int *vis = (int *)malloc (sizeof(int*)*n);
    int *id_hist = (int *)malloc (sizeof(int*)*n);
    int **res = initialize(min, vis, st, n);
    int *a = (int *)malloc (sizeof(int*)*2);

    for (a[0] = 0; a[0] < n; a[0]++) {
        for (a[1] = 1; a[1] <= cn[st][0]; a[1]++) {
            res[cn[st][a[1]]][st] = min[st] + in[st][cn[st][a[1]]];
            min = minval(res, min, cn[st][a[1]], n);
        }
        id_hist[a[0]] = st;
        vis[st] = 0;
        st = -1;
        for(a[1] = a[0]; st == -1 && a[1] >= 0; a[1]--)
            st = next_index(res, vis, id_hist[a[1]], n);
    }
    free(a);
    free(id_hist);
    return create_way(res, min, vis, n); 
}

static int **initialize(int *min, int *vis, int st, int n){
    int big = 2000000;
    int **res = (int **)malloc (sizeof(int**)*(n));

    for (int a = 0; a < n; a++) {
        res[a] = (int *)malloc (sizeof(int*)*(n));
        for (int b = 0; b < n; b++)
            res[a][b] = big;
    }
    for (int a = 0; a < n; a++) {
        min[a] = big;
        vis[a] = 1;
    }
    vis[st] = 0;
    min[st] = 0;
    return res;
}

static int *minval(int **in, int *min, int st, int n) {
    for(int a = 0; a < n; a++)
        min[st] = min[st] < in[st][a] ? min[st] : in[st][a];
    return min;
}

static int next_index(int **in, int *vis, int st, int n){
    int minval = 2000000;
    int id = -1;

    for (int a = 0; a < n; a++) {
        for(st = 0; st < n; st++){
            if (in[a][st] < minval && in[a][st] != 0 && vis[a]) {
                minval = in[a][st];
                id = a;
            }
        }
    }
    return id;
}

static int **create_way(int **res, int *min, int *vis, int n) {
    int **way = NULL;

    way = (int**)malloc(sizeof(int**) * n);
    for (int a = 0; a < n; a++){
        way[a] = (int*)malloc(sizeof(int*)*(n + 1));
        way[a][0] = 0;
        for (int b= 0; b < n; b++) {
            if (res[a][b] == min[a]) {
                way[a][0]++;
                way[a][way[a][0]] = b;
            }
        }
    }
    mx_free_array2((void**)res, n);
    free(min);
    free(vis);
    return way;
}

