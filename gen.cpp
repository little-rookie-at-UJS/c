#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

int a[100];
using namespace std;

int main() {
    std::mt19937 rng(time(0));
    int n = rng() % 10  + 1;
    int m = rng() % 10  + 1;
    int c1 = rng() % 3  + 1;
    int c2 = rng() % 2  + 1;
    cout <<n  << " " << m << " " << c1 << " " << c2 << endl;
    for (int i = 0; i < c1; i++) {
        cout << rng() % n + 1 << " " << rng() % m + 1 << endl;
    }
    for (int i = 0; i < c2; i++) {
        cout << rng() % m + 1 << endl;
    }

}
