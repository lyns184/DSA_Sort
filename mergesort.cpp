#include <bits/stdc++.h>
using namespace std;
using ld = long double;

void merge(vector<ld> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<ld> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<ld> &arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void process(vector<ld> &data, ofstream &outfile, int testIndex) {
    auto start = chrono::high_resolution_clock::now();
    mergeSort(data, 0, data.size() - 1);
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
