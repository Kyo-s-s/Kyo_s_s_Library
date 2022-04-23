# Eratos

https://github.com/Kyo-s-s/Kyo_s_s_Library/blob/main/lib/math/Eratos.cpp

エラトステネスの篩に関連したやつ

## コンストラクタ

```cpp
Eratos Era(int Eramax = 1e6)
```

特に指定しないと$N = 10^6$として前処理をする. 指定するとその値をNとして前処理をする.

##### 計算量

- $O(N \log \log N)$

## factorize

```cpp
vector<int> Era.factorize(int n)
```

$n$を素因数分解する. $n \leq N$じゃないとダメ

##### 計算量

- $O(\log n)$

## divisor

```cpp
vector<int> Era.factorize(int n)
```

$n$​の約数を列挙する.  $n \leq N$じゃないとダメ

##### 計算量

- $O(\log n)$

## is_prime

```cpp
bool is_prime(int x)
```

$x$が素数か判定する. $x \leq N$じゃないとダメ

##### 計算量

- $O(1)$