#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define INF (1ll << 60)

int main() {
  int N;
  cin >> N;

  vector<int> A(2 * N);

  for (int i = 0; i < 2 * N; i++) {
    cin >> A[i];
  }

  // dp[i][j] は、A_i から A_j を取り除く時のコストの最小値
  vector<vector<long long>> dp(2 * N, vector<long long>(2 * N, INF));

  for (int i = 2 * N - 1; i >= 0; i--) {
    for (int j = i + 1; j < 2 * N; j++) {
      if ((j - i) % 2 == 0) {
        continue;
      }

      if (j - i == 1) {
        dp[i][j] = abs(A[i] - A[j]);
        continue;
      }

      dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + abs(A[i] - A[j]));

      for (int k = i + 1; k < j - 1; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }
    }
  }

  cout << dp[0][2 * N - 1] << endl;
}
