#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll N = 200200;

void Fix(string &s) {
    reverse(s.begin(), s.end());

    s.resize(N, '0');

    for (ll i = N - 1; i > 0; i--)
        while (i < N - 1 && s[i] == '1' && s[i - 1] == '1')
            s[i] = s[i - 1] = '0', s[i + 1] = '1', i++, i++;

    reverse(s.begin(), s.end());
}

int main() {
    string s1;
    cin >> s1;
    Fix(s1);
    string s2;
    cin >> s2;
    Fix(s2);
    cerr << s1 << " " << s2 << endl;
    if (s1 == s2) cout << "=";
    if (s1 > s2) cout << ">";
    if (s1 < s2) cout << "<";
}