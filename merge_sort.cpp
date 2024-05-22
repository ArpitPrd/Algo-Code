#include <iostream>

void PRINT_ARRAY(int* A, int len) {
	for (int i = 0; i < len; i++) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}

void MERGE(int* A, int p, int q, int r) {
	int L[q-p+2], R[r-q+1];
	for (int i = 0; i < q-p+1; i++) {
		L[i] = A[i + p];
	}
	for (int i = 0; i < r-q; i++) {
		R[i] = A[i + q + 1];
	}
	L[q-p+1] = 100000; // large number
	R[r-q] = 100000;  // large number
	int i = 0, j = 0;
	for (int k = p; k < r; i++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i += 1;
		}
		else {
			A[k] = R[j];
			j += 1;
		}
	}
}

void MERGE_SORT(int* A, int start, int end) {
	if (start < end) {
		MERGE_SORT(A, start, (start+end)/2);
		MERGE_SORT(A, (start + end)/2 + 1, end);
		MERGE(A, start, (start+end)/2, end);
	}
}

int main() {
	int* A = (int *) malloc(sizeof(int) * 5);
	A[0] = 3; A[1] = 5; A[2] = 1; A[3] = 2; A[4] = 7;
	MERGE_SORT(A, 0, 4);
	PRINT_ARRAY(A, 5);
}
