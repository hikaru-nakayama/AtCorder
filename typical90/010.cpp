#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> C(N), P(N); // C is class. P is score.

  for (int i = 0; i < N; i++) {
    cin >> C[i] >> P[i];
  }

  int Q;
  cin >> Q;
  vector<int> L(Q), R(Q);

  for (int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i];
  }

  vector<int> S_1(N + 1, 0); // 1組の累積和 S[i]は1番目からi番目までの和を表す。
  vector<int> S_2(N + 1, 0); // 2組の累積和 S[i]は1番目からi番目までの和を表す。

  for (int i = 1; i <= N; i++) {
    S_1[i] = S_1[i - 1];
    S_2[i] = S_2[i - 1];
    if (C[i - 1] == 1)
      S_1[i] += P[i - 1];
    else
      S_2[i] += P[i - 1];
  }

  for (int i = 0; i < Q; i++) {
    int l = L[i], r = R[i];
    int sum1 = S_1[r] - S_1[l - 1];
    int sum2 = S_2[r] - S_2[l - 1];
    cout << sum1 << " " << sum2 << endl;
  }
}
