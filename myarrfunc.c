#include <stdio.h>
#include "myarrfunc.h"

int set_size(size_t *n) {
    size_t size;

    printf("Enter array size (1-%d): ", MAX_SIZE);
    if (scanf("%zu", &size) != 1 || size == 0 || size > MAX_SIZE) {
        return 0;
    }

    *n = size;
    return 1;
}

int fill_array(int *arr, size_t n) {
    size_t i;

    for (i = 0; i < n; i++) {
        printf("arr[%zu] = ", i);
        if (scanf("%d", arr + i) != 1) {
            return 0;
        }
    }
    return 1;
}

void show_array(const int *arr, size_t n) {
    size_t i;

    for (i = 0; i < n; i++) {
        printf("arr[%zu] = %d, address = %p\n", i,
               *(arr + i), (void *)(arr + i));
    }
}

int min_in_range(const int *arr, size_t n, size_t k, size_t m, int *result) {
    size_t i;
    int min;

    if (k > m || m >= n) {
        return 0;
    }

    min = *(arr + k);
    for (i = k + 1; i <= m; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }

    *result = min;
    return 1;
}

int difference_in_range(const int *arr, size_t n, size_t k, size_t m, long long *result) {
    size_t i;
    int min, max;

    if (k > m || m >= n) {
        return 0;
    }

    min = *(arr + k);
    max = *(arr + k);
    for (i = k + 1; i <= m; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    *result = (long long)max - min;
    return 1;
}

size_t print_indices_below(const int *arr, size_t n, int k) {
    size_t i;
    size_t count = 0;

    for (i = 0; i < n; i++) {
        if (*(arr + i) < k) {
            printf("%zu ", i);
            count++;
        }
    }

    if (count == 0) {
        printf("No elements found");
    }
    printf("\n");
    return count;
}

void clear_input(void) {
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}
