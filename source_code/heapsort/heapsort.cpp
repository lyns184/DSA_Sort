#include <bits/stdc++.h>
using namespace std;
using ld = long double;

void heapify(vector<ld> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<ld> &arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void process(vector<ld> &data, ofstream &outfile, int testIndex) {
    auto start = chrono::high_resolution_clock::now();
    heapSort(data);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    outfile << "Sorting time " << testIndex << ": " << duration.count() << " ms\n";
}

int main() {
    ifstream infile("test.txt");
    ofstream outfile("time.txt");
    string line;
    int testIndex = 1;
    while (getline(infile, line)) {
        stringstream ss(line);
        vector<ld> data;
        ld num;
        while (ss >> num) {
            data.push_back(num);
        }
        process(data, outfile, testIndex++);
    }
    return 0;
}
