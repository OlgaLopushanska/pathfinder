#include "pathfinder.h"
#include "libmx.h"

static int find_ways(int **connect, int **ways, int *input, int start);

static void ways_reset(int *fringe, int *change, int *stop, int n);

static void ways_cheking(int *fringe, int *change, int *stop, int n);

static void create_one_way(int **fringe, int **ways, int **connect, int *input);

void mx_path_print(int ***in, int **matrix, char **islands, int n) {
    int **ways = mx_init_array(n * n * 100, n, -1);
    int n_way = -1;
    int start = 0;
    int **connect = NULL;
    int *input = (int*)malloc(4 * sizeof(int*));

    input[0] = n;
    for (start = 0; start < n - 1; start++) {
        connect = in[start];
        input[1] = start;
        n_way = find_ways(in[start], ways, input, n_way);
    }
    ways = mx_displace_left(ways, n, n_way);
    ways = mx_sort_way(ways, n, n_way);
    path_print2(ways, matrix, islands, n);
    mx_free_array2((void**)ways, n * n * 100);
    mx_free_array2((void**)islands, n + 1);
    mx_free_array3((void***)in, n, n);
    free(input);
    return;
}

static int find_ways(int **connect, int **ways, int *input, int n_way) {
    int stop =0;
    int end = 0;
    int **fringe = (int**)malloc(2 * sizeof(int**));

    fringe[0] = (int*)malloc(input[0]*sizeof(int*));
    fringe[1] = (int*)malloc(input[0]*sizeof(int*));
    for (end = input[1] + 1; end < input[0]; end++) {
        ways_reset(fringe[0], fringe[1], &stop, input[0]);
        while (stop == 0) {
            n_way++;
            input[2] = end;
            input[3] = n_way;
            create_one_way(fringe, ways, connect, input);
            ways_cheking(fringe[0], fringe[1], &stop, input[0]);
        }
    }
    mx_free_array2((void**)fringe, 2);
    return n_way;
}

static void ways_reset(int *fringe, int *change, int *stop, int n){
    int a = 0;

    for (a = 0; a < n; a++)
        fringe[a] = -1;
    for (a = 0; a < n; a++)
        change[a] = 1;
    *stop = 0;
    return;
}

static void ways_cheking(int *fringe, int *change, int *stop, int n){
    int a = 0;

    for (a = 0; a < n; a++)
        change[a] = 0;
    for (a = 0; a < n; a++) {
        change[a] = 1;
        *stop = a == n - 1 && fringe[a] == 1 ? 1 : 0;
        a = fringe[a] > 1 ? n : a;
    }
    return;
}

static void create_one_way(int **fringe, int **ways, int **connect, int *input){
    int a = 0;
    int current = input[0] - 1;
    int end = input[2];
    int n_way = input[3];

    for (a = end; a != input[1];) {
        if (fringe[1][current]) {
            fringe[0][current] = fringe[0][current] > 1
            ? fringe[0][current]-1 : connect[a][0];
        }    
        ways[n_way][current] = a;
        a = connect[a][fringe[0][current]];
        current--;
    }
    ways[n_way][current] = a;
    return;
}


