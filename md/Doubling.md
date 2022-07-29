# Doubling

ダブリング

半群$(S, \cdot : S \times S \to S)$に対して使用できる. $S^n$を前処理$O(|S|\log n)$, クエリ$O(\log n)$で求める. 半群なので結合則を満たす必要がある. 

**！！バグっています！！**

## コンストラクタ

```C++
Doubling<S> D(op, idx, v);
```

- 型 `S`
- 二項演算 `S op(S a, S b)`
- `S`の元に対して, インデックスを返す関数`int idx(S a)`
  を定義する必要がある. 例えば [Teleporter](https://atcoder.jp/contests/abc167/tasks/abc167_d) では、
```C++
using S = int;
auto op = [](S a, S b) -> S { return b; };
auto idx = [](S a) -> int { return a; };
```

とすればよい. ここで, `op`の左は`table[i][j]`が, 右は`table[i][_idx(table[i][j])]` が入る.

`v`は最初の遷移である. $s\in S$に対し, $s \cdot s$をあらかじめ計算したうえで渡せばよい.

`op`,`idx`はラムダ式で記述し渡す必要がある.

###### 計算量

- $O(|S|\log n)$



## query

```C++
S D.query(S s, ll n)
```

$s^n$を返す.

###### 制約

- $0 \leq n \leq 10^{18}$

###### 計算量

- $O(\log n)$



## 例

ABC167 D [Teleporter](https://atcoder.jp/contests/abc167/submissions/29492290)

ABC179 E [Sequence Sum](https://atcoder.jp/contests/abc179/submissions/29492311)

- valとsumの2つを持ちながらダブリング. 