//program to sort using diffrent 
#include <stdio.h>
#include<stdlib.h>

void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);

int main() 
{
    int n, choice,ele;
    int arr[n];
    while (1) {

        printf("Enter number of elements: ");
        scanf("%d",&n);
        for (int i = 0; i < n; i++) {
            printf("enter element %d",i+1);
            scanf("%d", &ele);
            arr[i]=ele;
        }
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                bubble_sort(arr, n);
                break;
            case 2:
                selection_sort(arr, n);
                break;
            case 3:
                insertion_sort(arr, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

//function for bubble sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//function for selection sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
//function for insertion sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
