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
    int n = 50;

    for (int i = 1; i <= n; i++) {
        char c = 'a' + rng() % 2;
        cout << c ;
    }
}
