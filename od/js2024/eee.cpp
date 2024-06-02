#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a;
    std::vector<int> pos{0};
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        while (x) {
            a.push_back(x);
            x /= 2;
        }
        pos.push_back(a.size());
    }

    std::vector<int> ans(q);
    std::vector<int> L(q), R(q), k(q);
    std::vector<std::pair<int, int>> qry(2 * q);
    for (int i = 0; i < q; i++) {
        std::cin >> L[i] >> R[i] >> k[i];
        L[i]--;
        L[i] = pos[L[i]];
        R[i] = pos[R[i]];
        qry[2 * i] = {L[i], i};
        qry[2 * i + 1] = {R[i], i};
    }
    std::sort(qry.begin(), qry.end());

    int m = *std::max_element(a.begin(), a.end());

    std::vector<int> val(q);

    n = a.size();
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);

    auto solve =
            [&](auto &&self, int l, int r, int al, int ar, int ql, int qr) -> void {

                if (r - l == 1) {
                    for (int i = ql; i < qr; i++) {
                        ans[qry[i].second] = l;
                    }
                    return;
                }
                int m = (l + r) / 2;
                int am = std::stable_partition(p.begin() + al, p.begin() + ar,
                                               [&](int i) {
                                                   return a[i] < m;
                                               }) - p.begin();

                for (int i = ql, j = am; i < qr; i++) {
                    auto [x, k] = qry[i];
                    while (j < ar && p[j] < x) {
                        j++;
                    }
                    if (x == L[k]) {
                        val[k] = -j;
                    } else {
                        val[k] += j;
                    }
                }

                int qm = std::stable_partition(qry.begin() + ql, qry.begin() + qr,
                                               [&](auto &t) {
                                                   return k[t.second] >= val[t.second];
                                               }) - qry.begin();

                for (int i = ql; i < qm; i++) {
                    auto [x, j] = qry[i];
                    k[j] -= val[j];
                    val[j] = 0;
                }

                self(self, l, m, al, am, ql, qm);
                self(self, m, r, am, ar, qm, qr);
            };
    solve(solve, 0, m + 1, 0, n, 0, 2 * q);

    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}