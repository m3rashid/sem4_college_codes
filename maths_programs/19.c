/*
 * PROGRAM TO INSERT AND DELETE ELEMENTS IN AN ARRAY
 *
 * Program Submitted By ---
 *  MD Rashid Hussain
 * Roll No: 20BCS033
 * Semester - IV
 * FET-JMI (CSE) 2020-24
 */

#include <stdio.h>

void insert(int element, int arr[], int *size) {
    arr[*size] = element;
    *size = *size + 1;
}

int delete (int arr[], int *size) {
    int element = arr[*size - 1];
    *size = *size - 1;
    return element;
}

int main() {
    printf("20BCS033 MD Rashid Hussain\n");

    int arr[10] = {5, 6, 7, 5, 3};
    int size = 5;

    printf("Array before insertion:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("\nInserted: 8,7,1,3\n");
    insert(8, arr, &size);
    insert(7, arr, &size);
    insert(1, arr, &size);
    insert(3, arr, &size);
    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    printf("\n\n");
    printf("Deleted element: %d \n", delete (arr, &size));
    printf("Deleted element: %d \n", delete (arr, &size));
    printf("Deleted element: %d \n", delete (arr, &size));

    printf("\nArray after deletion:\n");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
