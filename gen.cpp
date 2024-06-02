#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

int a[100];
using namespace std;

int main() {
    std::mt19937 rng(time(0));
//    int n;
//    cin >> n
    cout << 1 << endl;
    int n = rng() %10000+1;
    int m = rng()%100000+1;
    int k = rng()%100000+1;

    cout << n << " " << m << " " << k << endl;

    for(int i = 1; i <= m; i++) {
        cout << rng() % 5 + 1 << " " << rng() % n + 1
        << " " << rng() % k + 1 << " " << rng() % 10 + 1 << endl;
    }


    for(int i = 1; i <= k; i++) {
        cout << rng() % k + 1 << " " << rng() % 10 + 1 << endl;
    }


}
