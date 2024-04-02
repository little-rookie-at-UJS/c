template <class T, size_t B> struct LinearBase {
    array<T, B> base;
    LinearBase() { base.fill(0); }
    void Insert(T x) {
        for (int i = B - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (!base[i]) {
                    base[i] = x;
                    return;
                } else {
                    x ^= base[i];
                }
            }
        }
    }
    auto QueryMax() -> T {
        T res = 0;
        for (int i = B - 1; i >= 0; i--) {
            res = max(res, res ^ base[i]);
        }
        return res;
    }
    auto Contains(T x) -> bool {
        for (int i = B - 1; i >= 0; i--) {
            if (x >> i & 1) {
                x ^= base[i];
            }
        }
        return x == 0;
    }
    auto operator+(const auto &o) -> LinearBase<T, B> {
        auto res = *this;
        for (int i = B - 1; i >= 0; i--) {
            res.Insert(o.base[i]);
        }
        return res;
    }
};

template <class T, size_t B> struct PrefixLinearBase {
    array<T, B> base;
    array<int, B> pos;
    PrefixLinearBase() {
        base.fill(0);
        pos.fill(-1);
    }
    void InsertWithPos(T x, int p) {
        for (int i = B - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (!base[i]) {
                    base[i] = x, pos[i] = p;
                    return;
                } else if (pos[i] < p) {
                    swap(base[i], x);
                    swap(pos[i], p);
                }
                x ^= base[i];
            }
        }
    }
    auto QueryRange(int l) -> LinearBase<T, B> {
        LinearBase<T, B> res;
        for (int i = 0; i < static_cast<int>(B); i++) {
            if (pos[i] >= l) {
                res.base[i] = base[i];
            }
        }
        return res;
    }
};