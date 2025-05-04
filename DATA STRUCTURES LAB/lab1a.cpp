//Search the target
#include<stdio.h>
#include<stdlib.h>
#include"lab1b.h"

int linsearch(int n,int arr[],int target);
int binsearch(int n,int arr[],int target);

int main(){
    int n,choice,target;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    } 

    printf("Enter the target:\n");
    scanf("%d",&target);
    
    int result;

    do{
        printf("\n---MENU---");
        printf("\n1.Linear Search");
        printf("\n2.Binary Search");
        printf("\n3.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
               result = linsearch(n,arr,target);
               if(result!=-1){
                printf("The element %d is found at the index:%d\n",target,result);
               } 
               else{
                printf("Element %d not found.",target);
               }
               break;

            case 2:
               bubble_sort(arr,n);
               displayArray(n,arr);
               result = binsearch(n,arr,target);
               if(result!=-1){
                printf("The element %d is found at the index:%d\n",target,result);
               } 
               else{
                printf("Element %d not found.",target);
               }
               break;

            case 3:
               exit(0);

            default:
               printf("Invalid choice.Please try again.\n");   
        }

    }while(choice!=3);
    return 0;
    }

int linsearch(int n,int arr[],int target){
    for (int i=0;i<n;i++){
        if(arr[i]==target){
           return i;
        }
    }
    return -1;
}

int binsearch(int n,int arr[],int target){
    bubble_sort(arr,n);
    displayArray(n,arr);
    int left=0,right=n-1;

    while(left<=right){
        int mid= left + (right - left)/2;

        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}

