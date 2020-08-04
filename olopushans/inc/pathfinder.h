#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>


int mx_atoi(char *str);

char **mx_path_error(char *s, int *n);

void mx_path_error2(char *s);

char **mx_path_error3(char *s, int n);

char *mx_path_error_first(int args, char *argv[]);

int main(int args, char *argv[]);

int **mx_path_array(char **islands, char *s, int n);

int mx_new_line(int line, int *p, int *r);

void mx_free_array2(void **arr, int row);

void mx_free_array3(void ***arr, int row, int col);

int mx_path_error_output(int n, char *s);

int **mx_init_array(int row, int col, int value);

int ***mx_find_path(int **matrix, int n);

int **mx_dextra_alg(int **in, int **cn, int n, int st);

void path_print2(int **ways, int **matrix, char **islands, int n);

int **mx_sort_way(int **ways, int n, int n_way);

void mx_path_print(int ***in, int **matrix, char **islands, int n);

void mx_write_zero(char *st);

int **mx_displace_left(int **ways, int n, int n_way);


#endif
