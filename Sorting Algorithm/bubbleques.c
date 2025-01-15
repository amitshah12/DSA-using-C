#include<stdio.h>


// Given an integer array arr, move all 0's to the end of it while maintaining the relatives order of the non-zero elements.
// Note that you must do this in-place without making a copy of array
// eg. Input: 0 5 0 3 4 2  Output: 5 3 4 2 0 0
//
void moveZerosToEnd(int arr[], int n){
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]==0){
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
            }
        }
    }
    return;
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d element in array: ",n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    moveZerosToEnd(arr, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}