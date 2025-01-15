#include<stdio.h>

void insertionSort(int arr[], int n){
    
    for(int i=1; i<n; i++){// intial value is taken from 1 because 1st element is taken as sorted
        int cur = arr[i];
        //finding the correct position for our current element
        int j = i-1;
        while(j>=0 && arr[j] > cur){
            arr[j+1] = arr[j];
            j--;
        }
        //insert current element
        arr[j+1] = cur;
    }
}
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d element for array: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    

    return 0;
}