#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<pair<long long, long long>> cd(N);

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    cd[i] = {x, y};
  }

  vector<vector<long long>> dist(N, vector<long long>(N, 0));
  // 各点同士の距離を求める
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      long long dx = cd[i].first - cd[j].first;
      long long dy = cd[i].second - cd[j].second;
      long long d2 = dx * dx + dy * dy;
      dist[i][j] = d2;
    }
  }

  vector<long long> cost(1 << N,
                         0); // cost[i]: i で表せる要素の組みの最大の距離
  // すベてのグループ候補の距離の最大値を求める
  // {1, 2, 5} -> 100110
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < j; k++) {
        if ((i & (1 << j)) && (i & (1 << k))) {
          cost[i] = max(cost[i], dist[j][k]);
        }
      }
    }
  }

  const long long INF = (1LL << 62);
  // dp[i][j]: i の group 数で、j ( bit で表現）の要素を選んだ時の cost の最小値
  vector<vector<long long>> dp(K + 1, vector<long long>((1 << N) + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= K; i++) {
    dp[i][0] = 0;
    for (int j0 = 0; j0 < (1 << N); j0++) {
      for (int j1 = j0; j1; j1 = (j1 - 1) & j0) {
        // j0をj1とj2に分割する
        long long j2 = j0 ^ j1;
        long long prev = dp[i - 1][j2];
        if (prev == INF)
          continue;
        // prev が i - 1 個のグループになるので、j1 は 1 つのグループでの cost
        // を使う
        dp[i][j0] = min(dp[i][j0], max(prev, cost[j1]));
      }
    }
  }

  cout << dp[K][(1 << N) - 1] << endl;
}
