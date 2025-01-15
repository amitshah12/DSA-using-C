#include<stdio.h>

//function for BubbleSort algorithm
void bubbleSort(int arr[], int n){
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
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

    bubbleSort(arr, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}