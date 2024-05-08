#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

int a[100];
using namespace std;

int main() {
    std::mt19937 rng(time(0));
    int k = 1;
    cout << k << endl;
    while (k--) {
        int n = 2000000;

        for (int i = 1; i <= n; i++) {
            char c = 'a' + rng() % 20;
            cout << c;
        }
        cout << endl;
    }
}
