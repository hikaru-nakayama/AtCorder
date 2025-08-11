#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  long long P;
  cin >> N >> K >> P;

  vector<long long> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  // A_1[i]: i個の要素を使った時の合計金額の配列
  vector<vector<long long>> A_1(N + 1);
  // A_2[i]: i個の要素を使った時の合計金額の配列
  vector<vector<long long>> A_2(N + 1);

  int a_1 = N / 2;
  int a_2 = N - a_1;

  for (int i = 0; i < (1LL << a_1); i++) {
    int m = __builtin_popcount(i); // 1が立っている数

    if (m > K)
      continue;

    long long sum = 0;
    for (int j = 0; j < a_1; j++) {
      if (i & (1LL << j)) {
        sum += A[j];
      }
    }

    A_1[m].push_back(sum);
  }

  for (int i = 0; i <= N; i++) {
    sort(A_1[i].begin(), A_1[i].end());
  }

  for (int i = 0; i < (1LL << a_2); i++) {
    int m = __builtin_popcount(i); // 1が立っている数

    if (m > K)
      continue;

    long long sum = 0;
    for (int j = 0; j < a_2; j++) {
      if (i & (1LL << j)) {
        sum += A[a_1 + j];
      }
    }

    A_2[m].push_back(sum);
  }
  for (int i = 0; i <= N; i++) {
    sort(A_2[i].begin(), A_2[i].end());
  }

  long long ans = 0;

  for (int i = 0; i <= K; i++) {
    auto u = A_1[i];
    auto v = A_2[K - i];

    for (long long s : u) {
      if (s > P)
        continue; // これだけで超えるなら除外
      ans += upper_bound(v.begin(), v.end(), P - s) - v.begin();
    }
  }

  cout << ans << endl;
}
