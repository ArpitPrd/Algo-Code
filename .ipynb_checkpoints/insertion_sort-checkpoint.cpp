#include <iostream>

void PRINT_ARRAY(int* A, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void INSERTION_SORT(int* A, int len) {
    for (int j = 1; j < len; j++) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

int main() {
    int len = 3;
    int* A = (int*) malloc(len*sizeof(int));
    A[0] = 3; A[1] = 2; A[2] = 3;
    printf("unsorted\n");
    PRINT_ARRAY(A, len);
    INSERTION_SORT(A, len);
    printf("sorted\n");
    PRINT_ARRAY(A, len);
}