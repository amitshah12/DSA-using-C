#include<iostream>
#include<vector>
using namespace std;

/*Give an array of names of the fruits you are supposed to sort it in lexicographical order
 using the selection sort 
 input: ["papaya", "lime", "watermelon", "apple", "mango", "Kiwi"]
 Output: ["apple", "kiwi", "lime", "mango", "papaya", "watermelon"]   */


void selectionSort(vector<string> &arr){
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

// void selectionSort(char arr[][60], int n){

//     for(int i=0; i<n-1; i++){
//         //finding min element
//         int min_idx = i;
//         for(int j=i+1; j<n; j++){
//             if(strcmp(arr[min_idx], arr[j]) > 0){
//                 min_idx = j;
//             }
//         }

//         //place the min element at the beginning
//         if(i != min_idx){
//             swap(arr[i], arr[min_idx]);
//         }
//     }
//     return;
// }

int main(){
    cout<<"Enter size of array:";
    int n;
    cin>>n;

    cout<<"Enter " << n << " elements in array:";
    vector <string> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    selectionSort(arr);
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";

    return 0;
}