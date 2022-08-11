#include <iostream>
using namespace std;


void merge(int arr[], int left, int middle, int right){
    int newArr[right + 1];
    int i = left, j = middle + 1, k = left;
    while(i <= middle && j <= right){
        if(arr[i] < arr[j]){
            newArr[k++] = arr[i++];
        }
        else{
            newArr[k++] = arr[j++];
        }
    }
    while(i <= middle){
        newArr[k++] = arr[i++];
    }
    while(j <= right){
        newArr[k++] = arr[j++];
    }
    for(int j = left; j <= right; j ++){
        arr[j] = newArr[j];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main(){

    return 0;
}
