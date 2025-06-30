#include <iostream>
#include <vector>

using namespace std;

template <typename T> struct RMQ {
  const T INF = numeric_limits<T>::max();
  int n;         // 葉の数
  vector<T> dat; // 完全二分木の配列

  RMQ(int n_) : n(), dat(n_ * 4, INF) {
    // 必要な葉の数を計算
    // 2^x > n_ を満たす最小のの2^xを葉の数にすることで完全２分木になる
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x;
  }

  // i:更新したい数列の位置
  // x:更新する値
  void update(int i, int x) {
    i += n - 1; //数列i番目はdatのn-1+i番目に格納されている
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = min(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }

  int query(int a, int b) { return query_sub(a, b, 0, 0, n); }

  // dat[k]が表す区間を[l, r) とする
  int query_sub(int a, int b, int k, int l, int r) {}
};
