# Segtree
https://github.com/Kyo-s-s/Kyo_s_s_Library/blob/main/lib/data-structure/Segtree.cpp

[ACL](https://atcoder.github.io/ac-library/document_ja/segtree.html)のパクり　
`internal::ceil_pow2`とかがなくても動くようになってる(これをこのまま貼るだけでOK！)。

`RMQ`(Range Maximize Query)、`RmQ`(Range minimize Query)、`RSQ`(Range Sum Query)が書いてあるので、
```cpp
(1) RMQ seg(int n)
(2) RMQ seg(vector<long long> v)
```
などと書けばよい。モノイドを乗せるときはACLと同じようにする。

また、
```cpp
(1) SegtreeMmS seg(int n)
(2) SegtreeMmS seg(vector<long long> v)
```
とすると`min`,`max`,`sum`が取得できる　でもこれ別々のセグ木を持てばよいので使わないかも