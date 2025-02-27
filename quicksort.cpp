#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int medianOfThree(vector<ld> &arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    if (arr[high] < arr[mid]) swap(arr[high], arr[mid]);
    swap(arr[mid], arr[high]);
    return arr[high];
}

int partition(vector<ld> &arr, int low, int high) {
    ld pivot = medianOfThree(arr, low, high);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<ld> &arr, int low, int high) {
    while (low < high) {
        int pi = partition(arr, low, high);
        if (pi - low < high - pi) {
            quickSort(arr, low, pi - 1);
            low = pi + 1;
        } else {
            quickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}

void process(vector<ld> &data, ofstream &outfile, int testIndex) {
    auto start = chrono::high_resolution_clock::now();
    quickSort(data, 0, data.size() - 1);
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
