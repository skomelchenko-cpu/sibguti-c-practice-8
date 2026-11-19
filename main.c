#include <stdio.h>
#include "myarrfunc.h"

int main(void) {
    int arr[MAX_SIZE];
    size_t n = 0;
    size_t k, m;
    int filled = 0;
    int min, value;
    long long difference;
    char choice;

    while (1) {
        printf("\na - Set array size\n");
        printf("b - Fill array\n");
        printf("c - Show array and addresses\n");
        printf("d - Minimum in range k-m\n");
        printf("e - Difference between max and min in range k-m\n");
        printf("f - Indices of elements below k\n");
        printf("g - Exit\n");
        printf("Choice: ");

        if (scanf(" %c", &choice) != 1) {
            break;
        }

        if (choice == 'g') {
            break;
        }

        switch (choice) {
            case 'a':
                if (set_size(&n)) {
                    filled = 0;
                    printf("Array size: %zu\n", n);
                } else {
                    printf("Invalid size\n");
                    clear_input();
                }
                break;

            case 'b':
                if (n == 0) {
                    printf("Set the array size first\n");
                    break;
                }
                filled = 0;
                if (fill_array(arr, n)) {
                    filled = 1;
                    printf("Array filled\n");
                } else {
                    printf("Invalid input\n");
                    clear_input();
                }
                break;

            case 'c':
                if (!filled) {
                    printf("Fill the array first\n");
                } else {
                    show_array(arr, n);
                }
                break;

            case 'd':
            case 'e':
                if (!filled) {
                    printf("Fill the array first\n");
                    break;
                }
                printf("Enter k and m (0-%zu): ", n - 1);
                if (scanf("%zu %zu", &k, &m) != 2) {
                    printf("Invalid input\n");
                    clear_input();
                    break;
                }
                if (choice == 'd') {
                    if (min_in_range(arr, n, k, m, &min)) {
                        printf("Minimum: %d\n", min);
                    } else {
                        printf("Invalid range\n");
                    }
                } else {
                    if (difference_in_range(arr, n, k, m, &difference)) {
                        printf("Difference: %lld\n", difference);
                    } else {
                        printf("Invalid range\n");
                    }
                }
                break;

            case 'f':
                if (!filled) {
                    printf("Fill the array first\n");
                    break;
                }
                printf("Enter k: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input\n");
                    clear_input();
                    break;
                }
                printf("Indices: ");
                print_indices_below(arr, n, value);
                break;

            default:
                printf("Unknown menu item\n");
                clear_input();
        }
    }

    return 0;
}
