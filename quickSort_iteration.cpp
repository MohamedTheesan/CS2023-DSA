#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int start, int End) {
    int pivot = arr[(start + End) / 2];
    while (start <= End) {
        while (arr[start] < pivot) {
            start++;
        }
        while (arr[End] > pivot) {
            End--;
        }
        if (start <= End) {
            swap(&arr[start], &arr[End]);
            start++;
            End--;
        }
    }
    return start;
}

void quickSort_i(int arr[], int low, int high) {
    int A[high - low + 1];
    int top = -1;

    A[++top] = low;
    A[++top] = high;

    while (top >= 0) {
        high = A[top--];
        low = A[top--];

        int newStart = partition(arr, low, high);

        if (newStart - 1 > low) {
            A[++top] = low;
            A[++top] = newStart - 1;
        }
        if (newStart + 1 < high) {
            A[++top] = newStart + 1;
            A[++top] = high;
        }
    }
}


int main() {
    int n;
    for(int i=1;i<6;i++){
        int totalTime=0;
        for(int j=0;j<5;j++){

            n = 5000*i;
            int arr[n];
            for(int i=0;i<n;i++){
                arr[i]=rand()%(n+30000);
            }
            srand(time(NULL));
            auto start_time = high_resolution_clock::now();
            int size = sizeof(arr) / sizeof(arr[0]);
            quickSort_i(arr,0,size-1);
            auto end_time = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end_time - start_time);

            totalTime += duration.count();
        }
        cout<<"n is "<<n<<endl;
        cout << "Execution time is " << totalTime/5 <<" microseconds"<<endl<<"\n";
    }
    return 0;
}
