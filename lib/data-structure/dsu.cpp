#include <bits/stdc++.h>
using namespace std;

// https://atcoder.github.io/ac-library/document_ja/dsu.html 

struct dsu{
  public:
    dsu() : _n(0) {}
    dsu(int n):  _n(n), parent(n, -1) {}

    int marge(int a, int b){
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if(x == y) return x;
        if(-parent[x] < -parent[y]) std::swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return x;
    }

    bool same(int a, int b){
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a){
        assert(0 <= a && a < _n);
        if(parent[a] < 0) return a;
        return parent[a] = leader(parent[a]);
    }

    int size(int a){
        assert(0 <= a && a < _n);
        return -parent[leader(a)];
    }

    std::vector<std::vector<int>> groups(){
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
    
  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent;
};


