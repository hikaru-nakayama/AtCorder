#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

template <typename T> struct RMQ {
  T INF;

  int n;
  vector<T> dat;
  vector<T> lazy;

  RMQ(int n_) : n(), dat(n_ * 4), lazy(n_ * 4) {
    INF = numeric_limits<T>::min();
    int x = 1;
    while (n_ > x)
      x *= 2;
    n = x;
    dat.assign(n_ * 4, INF);
    lazy.assign(n_ * 4, INF);
  }

  void eval(int k) {
    if (lazy[k] == INF)
      return;
    if (k < n - 1) {
      lazy[k * 2 + 1] = lazy[k];
      lazy[k * 2 + 2] = lazy[k];
    }
    dat[k] = lazy[k];
    lazy[k] = INF;
  }

  void update(int i, T x) {
    i += n - 1;
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = max(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }

  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

  T query_sub(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l)
      return INF;
    if (a <= l && r <= b)
      return dat[k];
    T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};

int main() {
  long long W, N;
  cin >> W >> N;

  vector<long long> L(N), R(N), V(N);
  for (long long i = 0; i < N; i++) {
    cin >> L[i] >> R[i] >> V[i];
  }

  vector<vector<long long>> dp(N, vector<long long>(W + 1, -1));
  RMQ<long long> rmq(W + 1);

  dp[0][0] = 0;
  rmq.update(0, 0);
  for (long long j = L[0]; j <= R[0]; j++) {
    if (j <= W) {
      dp[0][j] = V[0];
      rmq.update(j, V[0]);
    }
  }

  for (long long i = 1; i < N; i++) {
    RMQ<long long> next_rmq(W + 1);
    for (long long j = 0; j <= W; j++) {
      // 作らない場合
      if (dp[i - 1][j] != -1) {
        dp[i][j] = dp[i - 1][j];
        next_rmq.update(j, dp[i][j]);
      }

      // 作る場合
      long long left = max(0LL, j - R[i]);
      long long right = j - L[i];
      if (right >= 0) {
        long long max_prev = rmq.query(left, right + 1);
        if (max_prev != rmq.INF) {
          dp[i][j] = max(dp[i][j], max_prev + V[i]);
          next_rmq.update(j, dp[i][j]);
        }
      }
    }
    rmq = move(next_rmq);
  }

  cout << dp[N - 1][W] << endl;
}
