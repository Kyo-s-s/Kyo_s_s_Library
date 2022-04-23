#include <bits/stdc++.h>
using namespace std;

struct Eratos{
  public:
    
    Eratos(int _Eramax = 1e6){
        Eramax = _Eramax;
        E.resize(Eramax + 1);
        for(int i = 0; i < Eramax + 1; i++) E[i] = i;
        for(int i = 2; i < Eramax + 1; i++) if(E[i] == i){
            for(int j = 2 * i; j < Eramax + 1; j += i) E[j] = i;
        }
        E[1] = -1;
    }

    vector<int> factorize(int n){
        assert(n <= Eramax);
        vector<int> ret;
        while(n != 1){
            ret.push_back(E[n]);
            n /= E[n];
        }
        return ret;
    }

    vector<int> divisor(int n){
        assert(n <= Eramax);
        vector<int> fact = factorize(n);
        map<int, int> cnt;
        vector<int> list;
        for(auto x: fact) cnt[x]++;
        for(auto [k, v]: cnt) list.push_back(k);
        vector<int> ret;

        auto dfs = [&](auto&& self, int n, int x) -> void {
            if(n == list.size()){
                ret.pb(x); return;
            }
            for(int u = 0; u <= cnt[list[n]]; u++){
                self(self, n + 1, x * pow(list[n], u));
            }
        };
        dfs(dfs, 0, 1);
        return ret;
    }

    bool is_prime(int x){
        assert(x <= Eramax);
        return x == E[x];
    }

  private:
    vector<int> E;
    int Eramax;
    int pow(int a, int n){
        int ret = 1;
        while(n > 0){
            if(n & 1) ret = ret * a;
            a *= a;
            n >>= 1;
        }
        return ret;
    }

};

