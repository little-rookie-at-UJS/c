#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

int a[100];
using namespace std;

int main() {
    std::mt19937 rng(time(0));
    int n = 1000000, m = 1, k = 10;
    // cout << n << " " << m << " " << k << endl;
    cout <<1<<" " << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << rng() % 10000000000 + 1 << " ";
    }
}
