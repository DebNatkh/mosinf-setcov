// #include "testlib.h"
#include <iostream>

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include <random>

std::default_random_engine generator;
void gen(int n, int m, int k) {
    std::normal_distribution<double> distribution(k, rand() % 10);
    cout << n << " " << m << endl;
    for (int j = 0; j < m; j++) {
        int num = distribution(generator);
        num = max(num, 1);
        num = min(num, n);
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i + 1;
        random_shuffle(arr.begin(), arr.end());
        cout << num;
        for (int i = 0; i < num; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    }

}

int main(int argc, char *argv[]) {
    generator.seed(57);
    int test_group = stoi(argv[1]);
    if (test_group == 1) {
        cout << 6 << endl;
        gen(5, 5, 3);
        gen(10, 10, 5);
        gen(20, 12, 5);
        gen(20, 12, 10);
        gen(100, 12, 10);
        gen(100, 12, 15);
    } else if (test_group == 2) {
        cout << 0 << endl;
    }
}