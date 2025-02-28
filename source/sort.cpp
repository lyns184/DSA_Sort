#include <bits/stdc++.h>
using namespace std;
using ld = long double;

void process(vector<ld> &data, ofstream &outfile, int testIndex) {
    auto start = chrono::high_resolution_clock::now();
    sort(data.begin(), data.end());
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
