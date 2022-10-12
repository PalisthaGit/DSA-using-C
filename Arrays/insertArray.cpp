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
int main() {
    
    // initialize array
    struct Array arr = {{2,3,4,5,6}, 10, 5};
    append(&arr, 10);
    display(arr);
    return 0;
}