#include "pathfinder.h"
#include "libmx.h"

static int *ways_find_end(int **ways, int *end, int *sum, int a);

static int *ways_sum(int **ways, int *end, int *sum, int a);

static int **ways_change(int **ways, int *flag, int a);

int **mx_sort_way(int **ways, int n, int n_way)  {
    int flag = 1;
    int *end = (int*)malloc(2*sizeof(int*));
    int *sum = (int*)malloc(3*sizeof(int*));

    sum[2] = n;
    while (flag) {
        flag = 0;
        for (int a = 0; a <= n_way - 1; a++) {
            end = ways_find_end(ways, end, sum, a);
            sum = ways_sum(ways, end, sum, a);
            if ((ways[a][0] == ways[a + 1][0] && (end[0] > end[1] || sum[0] > sum[1]))
                || ways[a][0] > ways[a + 1][0])
                ways = ways_change(ways, &flag, a);
        }
    }
    free(end);
    free(sum);
    return ways;
}

static int *ways_sum(int **ways, int *end, int *sum, int a) {
    int b = 0;
    int n = sum[2];
    
     if (ways[a][0] == ways[a + 1][0] && end[0] == end[1]) {
        for (b = 0; b < n - 1 && ways[a][b] != -1
            && ways[a+1][b] != -1 ; b++) {  
            sum[0] = ways[a + 1][b] < ways[a][b] ? sum[0] + 1 : 0;
            b = ways[a + 1][b] != ways[a][b] ? n + 5 : b;
        }
    }
    return sum;
}

static int *ways_find_end(int **ways, int *end, int *sum, int a){
    int b = 0;
    int n = sum[2];

    sum[0] = 0;
    sum[1] = 0;
    for ( b = 0; b < n; b++) { 
        end[0] = ways[a][b] != -1 ? ways[a][b] : end[0];
        end[1] = ways[a+1][b] != -1 ? ways[a + 1][b] : end[1];
    }
    return end;
}

static int **ways_change(int **ways, int *flag, int a){
    int *temp = NULL;
            
    temp = ways[a];
    ways[a] = ways[a+1];
    ways[a + 1] = temp;
    *flag = 1;
    return ways;
}
