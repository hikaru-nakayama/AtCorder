#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1000000007;
const string T = "atcoder";

void add(int &a, int &b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int main() {
  int N;
  string S;

  cin >> N >> S;

  vector<vector<int>> dp(
      N + 1,
      vector<int>(
          T.size() + 1,
          0)); // Sの初めからi文字目までで選んでTのj番目の文字列までと一致する場合の数

  dp[0][0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= T.size(); j++) {
      add(dp[i + 1][j], dp[i][j]);

      if (j < T.size() && S[i] == T[j]) {
        add(dp[i + 1][j + 1], dp[i][j]);
      }
    }
  }

  cout << dp[N][T.size()] << endl;
}
