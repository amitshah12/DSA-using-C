#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        //finding min element in unsorted array
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        //placing min element at beginning
        if(min_idx != i){
            swap(arr[i], arr[min_idx]);
        }
    }
}

int main(){
    cout<<"Enter size of array:";
    int n;
    cin>>n;

    cout<<"Enter " << n << " elements in array:";
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    selectionSort(arr);
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";

    return 0;
}