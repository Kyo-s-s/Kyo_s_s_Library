#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Cumulative Sum (一次元累積和)
 * @docs md/CumulativeSum.md
 */

template<class T> struct CumulativeSum{
  public:
    CumulativeSum(int n) : CumulativeSum(std::vector<T> (n)) {}
    CumulativeSum(const std::vector<T> &v) : _n(v.size()){
        data = std::vector<T> (_n + 1);
        for(int i = 0; i < _n; i++){
            data[i + 1] = v[i];
        }
    }

    void update(int p, const T &x) {
        assert(0 <= p && p < _n);
        data[p + 1] = x;
    }

    void add(int p, const T &x){
        assert(0 <= p && p < _n);
        data[p + 1] += x;
    }

    void build() {
        for(int i = 1; i < data.size(); i++){
            data[i] += data[i - 1];
        }
    }

    T sum(int r) {
        assert(0 <= r && r <= _n);
        return data[r];
    }

    T sum(int l, int r) {
        assert(0 <= l && l < r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<T> data;
};