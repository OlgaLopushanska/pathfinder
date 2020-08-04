#include "pathfinder.h"
#include "libmx.h"

int **mx_displace_left(int **ways, int n, int n_way) {
    int cur = 0;

    for (int a = 0; a <= n_way; a++) {
        cur = 0;
        if (ways[a][0] == -1) {
            for (int b = 0; b < n; b++) {
                if (ways[a][b] != -1) {
                    ways[a][cur] = ways[a][b];
                    ways[a][b] = -1;
                    cur++;
                }
            }
        }
    }
    return ways;
}
