#include <iostream>
#include <chrono>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

void plotData(const std::vector<int>& x, const std::vector<int>& y) {
    std::ofstream dataFile("data.txt");
    for (size_t i = 0; i < x.size(); ++i) {
        dataFile << x[i] << " " << y[i] << "\n";
    }
    dataFile.close();

    std::ofstream plotFile("plot.gnuplot");
    plotFile << "set terminal png\n";
    plotFile << "set output 'plot.png'\n";
    plotFile << "plot 'data.txt' with lines\n";
    plotFile.close();

    system("gnuplot plot.gnuplot");
}

void PRINT_ARRAY(int* A, int len) {
	for (int i = 0; i < len; i++) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}

void MERGE(int* A, int p, int q, int r) {
	int L[q - p + 1], R[r - q + 1];
	for (int i = 0; i < q - p; i++) {
		L[i] = A[i + p];
	}
	for (int i = 0; i < r-q; i++) {
		R[i] = A[i + q];
	}
	L[q-p] = INT_MAX;
	R[r-q] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k < r; k++) {
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
	if (end - start > 1) {
        // cout << start <<  " " << end << endl;
		MERGE_SORT(A, start, (start+end)/2);
		MERGE_SORT(A, (start + end)/2, end);
		MERGE(A, start, (start+end)/2, end);
	}
}

int main() {
    vector<int> v = {10, 100, 1000, 10000, 100000};
    vector<int> time;
    for (int l : v){
        int len = l;
    	cout << "length of array: " << len;
    	int* A = (int *) malloc(sizeof(int) * len);
    	cout << "unsorted array" << endl;
        for (int i = 0; i < len; i++) {
    		A[i] = rand() % 100;
            cout << A[i] << " ";
    	}
        cout << endl;
        auto start = std::chrono::high_resolution_clock::now();
        MERGE_SORT(A, 0, len);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        time.push_back(duration.count());
    }
    plotData(v, time);
}