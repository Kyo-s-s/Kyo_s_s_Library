#include <bits/stdc++.h>
using namespace std;

template<class T> struct LCA {
  public:
    LCA(int n) : _n(n) {
        G.resize(_n);
    }

    void add_edge(int s, int t){ add_edge(s, t, T(1)); }
    void add_edge(int s, int t, T c){
        G[s].push_back({t, c});
        G[t].push_back({s, c});
    }

    void build(int root = 0){
        in.resize(_n, -1);
        out.resize(_n, -1);
        dist.resize(_n);
        dist[root] = T(0);

        auto dfs = [&](auto&& self, int now, int bef, int depth) -> void {

            in[now] = euler_tour.size();
            euler_tour.push_back({depth, now});

            for(auto e: G[now]) if(e.to != bef){
                dist[e.to] = dist[now] + e.cost;
                self(self, e.to, now, depth + 1);
                euler_tour.push_back({depth, now});
            }
            
        };

        dfs(dfs, root, -1, 0);

        log = 0;
        while((1 << log) < euler_tour.size()) log++;
        size = 1 << log;
        d.resize(2 * size, e());

        for(int i = 0; i < euler_tour.size(); i++) d[size + i] = euler_tour[i];
        for(int i = size - 1; i >= 1; i--) update(i);

    }

    int query(int u, int v){
        return prod(min(in[u], in[v]), max(in[u], in[v]) + 1).index;
    }

    T get_path(int u, int v){
        return dist[u] + dist[v] - 2 * dist[query(u, v)];
    }

  private:
    struct edge{ int to; T cost; };
    struct S { int depth, index; };
    S op(S a, S b){ return (a.depth < b.depth ? a : b); }
    S e(){ return {1 << 28, 1 << 28}; }

    int _n, log, size;
    vector<vector<edge>> G;
    vector<T> dist;
    vector<int> in;
    vector<S> euler_tour;
    vector<S> d;

    void update(int k){ d[k] = op(d[2 * k], d[2 * k + 1]); }
    S prod(int l, int r){
        S smr = e(), sml = e();
        l += size; r += size;
        while(l < r){
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1; r >>= 1;
        }
        return op(sml, smr);
    }
    
};

