#include "pathfinder.h"
#include "libmx.h"
 
static char *path_read_file(char *argv);
 
char *mx_path_error_first(int args, char *argv[]) {
    char *errno1 = "usage: ./pathfinder [filename]\n";
    int fd = open(argv[1], O_RDONLY);
    char *res = NULL;
 
    if (args == 1) {
        write(2, errno1, 31);
        exit(0);
    }
    if (fd < 0) {
        write(2, "error: file ", 12);
        write(2, argv[1], mx_strlen(argv[1]));
        write(2, " does not exist\n", 16);
        exit(0);
    }
    close(fd);
    res = path_read_file(argv[1]);
    return res;
}
 
static char *path_read_file(char *argv){
    char *res = NULL;
 
    res = mx_file_to_str(argv);
    if (res == NULL) {
        write(2, "error: file ", 12);
        write(2, argv, mx_strlen(argv));
        write(2, " is empty\n", 10);
        exit(0);
    }
    return res;
}
