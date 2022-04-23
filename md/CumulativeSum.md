# Cumulative Sum

https://github.com/Kyo-s-s/Kyo_s_s_Library/blob/main/lib/dp/CumulativeSum.cpp

1次元累積和

## コンストラクタ

```C++
(1) CumuativeSum<T> cs(int n)
(2) CumuativeSum cs(vector<T> v)
```

- (1): 長さ`n+1`, 型`T`の数列を作る. 値はすべて初期値.
- (2): 長さ`n = v.size() + 1`, 型`T`の数列を作る. vの内容が初期値となる.

###### 計算量

- $O(n)$

## update

```C++
void cs.update(int p, T x)
```

`a[p]`の値を`x`に更新する.

###### 制約

- $0 \leq p < n$

###### 計算量

- $O(1)$

## add

```C++
void cs.add(int p, T x)
```

`a[p]`に`x`を加算する. 

###### 制約

- $0 \leq p < n$

###### 計算量

- $O(1)$

## build

```C++
void cs.build()
```

累積和をとる. 以後, `sum`が使えるようになる. 

###### 計算量

- $O(n)$

## sum

```C++
(1) T cs.sum(int r)
(2) T cs.sum(int l, int r)
```

- (1): 区間$[0, r)$の和を返す.
- (2): 区間$[l, r)$の和を返す.

###### 制約

- (1): $0 \leq r \leq n$
- (2): $0 \leq l < r \leq n$
###### 計算量

- $O(1)$

