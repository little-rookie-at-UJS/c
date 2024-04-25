#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

int a[100];
using namespace std;

int main() {
    std::mt19937 rng(time(0));
    int n = 5;
    int k = 2;
    cout << n << " " << k << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int r = rng() % 10;
            if (r)cout << "W";
            else cout << "B";
        }
        cout << endl;
    }
}
