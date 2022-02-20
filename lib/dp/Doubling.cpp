#include <bits/stdc++.h>
using namespace std;


template <class S>
struct Doubling{
  public:
    Doubling(function<S(S, S)> op, function<int(S)> idx, vector<S> v) : _op(op), _idx(idx) {
        table.resize(62, vector<S>(v.size()));
        for(int i = 0; i < v.size(); i++) table[0][i] = v[i];
        for(int i = 0; i < 61; i++){
            for(int j = 0; j < v.size(); j++){
                table[i+1][j] = _op(table[i][j], table[i][_idx(table[i][j])]);
            }
        }
    }        
    
    S query(S s, long long n){
        for(int i = 0; i < 62; i++) if((n >> i) & 1){
            s = _op(s, table[i][_idx(s)]);
        }
        return s;
    }
    
  private:
    function<S(S, S)> _op;
    function<int(S)> _idx;
    vector<vector<S>> table;
};