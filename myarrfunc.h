#ifndef MYARRFUNC_H
#define MYARRFUNC_H
#include <stddef.h>
#define MAX_SIZE 100
int set_size(size_t *n);
int fill_array(int *arr, size_t n);
void show_array(const int *arr, size_t n);
int min_in_range(const int *arr, size_t n, size_t k, size_t m, int *result);
int difference_in_range(const int *arr, size_t n, size_t k, size_t m, long long *result);
size_t print_indices_below(const int *arr, size_t n, int k);
void clear_input(void);
#endif
