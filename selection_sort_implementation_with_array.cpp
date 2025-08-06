#include <iostream>

void selection_sort(int *arr, int size){
    int count = 0;
    while (count < size-1){
        int smallest = 100;
        int small_index = 0;

        for (int i = count; i < size; i++){
            if (arr[i] < smallest){
                smallest = arr[i]; 
                small_index = i;
            }
        }
        int temp = arr[small_index];
        arr[small_index] = arr[count];
        arr[count] = temp;
        count++;
    }
}

int main() {
    int size = 3;
    int arr[size] = {1,2,3};
    selection_sort(arr, size);
    for (int i = 0; i < size; i++){
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;}

    return 0;
}