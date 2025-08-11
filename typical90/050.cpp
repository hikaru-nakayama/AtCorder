#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, L;
  cin >> N >> L;

  const long long MOD = 1'000'000'007;

  // i 段目までの登り方の場合の数
  vector<long long> dp(N + 1, 0);

  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    dp[i] = dp[i - 1];
    if (i - L >= 0) {
      dp[i] = (dp[i - L] + dp[i]) % MOD;
    }
  }

  cout << dp[N] << endl;
}
