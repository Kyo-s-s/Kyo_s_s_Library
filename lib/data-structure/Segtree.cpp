#include <bits/stdc++.h>
using namespace std;

template<class S, S (*op)(S, S), S (*e)()> struct Segtree {
  public:
    Segtree() : Segtree(0) {}
    Segtree(int n) : Segtree(vector<S> (n, e())) {}
    Segtree(const vector<S> &v) : n(int(v.size())) {
        while ((1 << log) < n) log++;
        size = 1 << log;
        d = vector<S> (2 * size, e());
        for (int i = 0; i < n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if (l == n) return n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int n, size, log = 0;
    vector<S> d;
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

};

long long RMQop(long long a, long long b) { return max(a, b); }
long long RMQe() { return -(1LL << 60); }
using RMQ = Segtree<long long, RMQop, RMQe>;

long long RmQop(long long a, long long b) { return min(a, b); }
long long RmQe() { return 1LL << 60; }
using RmQ = Segtree<long long, RmQop, RmQe>;

long long RSQop(long long a, long long b) { return a + b; }
long long RSQe() { return 0; }
using RSQ = Segtree<long long, RSQop, RSQe>;


struct MmS { long long min, max, sum; };
MmS MmSop(MmS a, MmS b){ return { min(a.min, b.min), max(a.max, b.max), a.sum + b.sum }; }
MmS MmSe(){ return {1LL << 60, -1ll << 60, 0 }; }

struct SegtreeMmS : Segtree<MmS, MmSop, MmSe> {
    using Segtree::Segtree;
    SegtreeMmS(int n){
        vector<MmS> sv(n, MmSe());
        (*this) = SegtreeMmS(sv);
    }
    SegtreeMmS(vector<long long> v) {
        int n = v.size();
        vector<MmS> sv(n);
        for(int i = 0; i < n; i++) sv[i] = {v[i], v[i], v[i]};
        (*this) = SegtreeMmS(sv);
    }
    void set(int p, long long x){
        Segtree::set(p, {x, x, x});
    }
    long long get(int p){
        return Segtree::get(p).sum;
    }
};


