#include <stdio.h>

#define SIZE 50


// Question 1
/***
 * This function uses a loop to shift the elements one position to the right, and then it saves the
 * value at the original position of the array in a temporary variable, and places it at the end of
 * the shifted elements.
 * @param arr pointer to the array.
 * @param i moves the i elements one cell to the right.
 */
void shift_element(int* arr, int i) {
    // Save the value at the current position
    int val = *arr;

    // Shift the elements one position to the right
    for (int j = 0; j < i; j++) {
        *(arr + j) = *(arr + j + 1);
    }

    // Place the saved value at the end of the shifted elements
    *(arr + i) = val;
}

// Question 2

/***
 * This function uses a loop to iterate over the elements of the array, and for each element it
 * shifts it one position to the right until it is in the correct position.
 * @param arr pointer to the array.
 * @param len size of the array.
 */
void insertion_sort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int j = i;
        while (j > 0 && *(arr + j - 1) > *(arr + j)) {
            // Shift the element one position to the right until it is in the correct position
            shift_element(arr + j - 1, 1);
            j--;
        }
    }
}

/***
 * This main() function reads numbers from the user until it reaches the end of the input or it has read
 * 50 (the value of the variable SIZE) numbers, and then it sorts the array using the insertion_sort function
 * and prints the sorted array to the screen. The elements of the array are separated by a comma with
 * no extra spaces.
 * @return
 */
int main() {
    int arr[SIZE];
    int j = 0;

    // Read numbers from the user
    while (j < SIZE && scanf("%d", &arr[j]) == 1) {
        j++;
    }

    // Sort the array
    insertion_sort(arr, j);

    // Print the sorted array
    for (int i = 0; i < j; i++) {
        printf("%d", arr[i]);
        if (i < j - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}