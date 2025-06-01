#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// 仕事情報を表す構造体
struct Job {
  ll S;  // 報酬
  int D; // 締切
  int C; // 仕事を完了させるための日数
  bool operator<(const Job &other) const { return D < other.D; }
};

int main() {

  int N;
  cin >> N;

  vector<Job> T(N);

  vector<vector<ll>> dp(
      N + 1, vector<ll>(5001, 0)); // i までの job を行い、j 日の締切までの報酬
  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    int D, C;
    ll S;
    cin >> D >> C >> S;
    T[i] = {S, D, C};
  }

  sort(T.begin(), T.end());

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= 5000; j++) {
      // Job i をやらない場合、i - 1 の job までの報酬がある
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);

      int j0 = j + T[i - 1].C;
      if (j0 <= T[i - 1].D) {
        dp[i][j0] = max(dp[i][j0], dp[i - 1][j] + T[i - 1].S);
      }
    }
  }

  ll ans = 0;
  int D_max = T.back().D;
  for (int j = 0; j <= D_max; j++) {
    ans = max(ans, dp[N][j]);
  }
  cout << ans << endl;
}
