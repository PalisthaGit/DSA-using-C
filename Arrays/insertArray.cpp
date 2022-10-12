#include <stdio.h>
#include <stdlib.h>
struct Array {

    // array
    int A[10];
    int size;
    int length;

};

void display(struct Array arr) {
    int i;
    printf("\nElements are\n");
    for(i = 0;i<arr.length;i++){
        printf("%d ", arr.A[i]);
    }
}

// insert array at end of the array - append
// as going to modify array it should be call by address type
void append(struct Array *arr, int x) {
    // check if there is free space in the array
    // use pointer whenever call by address
    if(arr->length<arr->size) {
        arr->A[arr->length++] = x;
    }

}

// insert element in an array
void insert(struct Array *arr, int index, int x) {
    int i;
    // check if the given index is valid
    // from 0 to length of array is valid
    if(index>=0 && index <=arr->length) {
        for(i = arr->length; i> index; i--) {
            // copy elements from index one step forward
            arr->A[i] = arr->A[i-1];
        }
        // insert element at index
        arr->A[index] = x;
        arr->length++;
   
    }

}

int main() {
    
    // initialize array
    struct Array arr = {{2,3,4,5,6}, 10, 5};
    insert(&arr, 0, 10);
    append(&arr, 10);
    display(arr);
    return 0;
}