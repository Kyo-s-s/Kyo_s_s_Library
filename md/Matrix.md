# Matrix

行列　すげー

## コンストラクタ

```C++
(1) Matrix<T> A(int n, int m)
(2) Matrix<T> A(int n)
```

- (1) : `n`×`m`行列を作る. すべて0.

- (2) : `n`×`n`行列を作る. すべて0.

  各要素には`A[i][j]`でアクセスできる.

## 各種演算

```C++
Matrix + Matrix
Matrix += Matrix
Matrix - Matrix
Matrix -= Matrix

Matrix * Matrix
Matrix *= Matrix
```

が動く. 和/差は`n`, `m`が等しいこと, 積は左の`m`と右の`n`が等しいことが条件.

###### 計算量

- $O(nm)$(和/差)

- $O(nmk)$(積, $n, m$は左の大きさ, $k$は右の$m$)

## pow

```c++
A.pow(long long k)
```

`A`の`k`乗を求める. `n`, `m`が等しいことが条件. 

###### 計算量

- $O(n^3)$
## 単位行列

```C++
Matrix<T>::I(int n)
```

`n`×`n`の単位行列を返す. 

## 出力

```C++
Matrix<int> A(3, 4);
    
for(int i = 0; i < A.n; i++) for(int j = 0; j < A.m; j++){
    A[i][j] = A.m * i + j;
}

cout << A;

/*
    [0, 1, 2, 3]
    [4, 5, 6, 7]
    [8, 9, 10, 11]
*/
```

