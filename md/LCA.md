# LCA
https://github.com/Kyo-s-s/Kyo_s_s_Library/blob/main/lib/data-structure/LCA.cpp

最近共通祖先　RMQをセグ木で求めてるけど, 更新されないのでもっと高速に行えそう. 

## コンストラクタ

```C++
LCA<T> lca(n)
```

頂点`n`の木を作る. `T`は辺の型. 重みなし木ならintでよい.

## add_edge

```C++
(1) lca.add_edge(int s, int t)
(2) lca.add_edge(int s, int t, T c)
```

- (1) : `s`から`t`を結ぶ長さ1の辺を追加
- (2) : `s`から`t`を結ぶ長さ`c`の辺を追加

###### 制約

- $0 \leq s, t < n$

###### 計算量

- $O(1)$

## build

```C++
lca.bulid(int root = 0)
```

根 = `root`として構築を行う. この際木じゃないとバグる. (閉路があったら無限ループにハマる.) かならず木の状態で行うこと. 

###### 計算量

- $O(n)$

## query

  ```C++
  lca.query(int u, int v)
  ```

`u`,`v`のLCAを求める.

###### 制約

- $0 \leq u, v < n$

###### 計算量

-  $O(\log n)$

## get_path

```C++
lca.get_path(int u, int v)
```

`u`,`v`の距離を求める.

###### 制約

- $0 \leq u, v < n$

###### 計算量

-  $O(\log n)$
