#include <iostream>
#include <vector>

using namespace std;

int main() {
  int K;
  cin >> K;
  long long LARGE = 1000000000 + 7;

  // 桁の合計が i になる場合の数
  vector<long long> dp(K + 1, 0);

  dp[0] = 1; // 左の桁が存在しない 1 通り
  dp[1] = 1; // 桁の合計が 1 になるのは 1 のみなので、1 通り

  if (K % 9 != 0) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 2; i <= K; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i - j >= 0) {
        dp[i] += dp[i - j];
      }
    }
    dp[i] = dp[i] % LARGE;
  }

  cout << dp[K] << endl;
}
