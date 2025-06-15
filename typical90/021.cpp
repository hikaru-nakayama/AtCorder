#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> finish_order; // {finish_time, node}
vector<int> seen;

void dfs1(int s, vector<vector<int>> &g, int &time) {
  seen[s] = 1;
  for (auto t : g[s]) {
    if (!seen[t]) {
      dfs1(t, g, time);
    }
  }
  finish_order.push_back({time++, s}); // 帰りがけ時刻を記録
}

void dfs2(int s, vector<vector<int>> &g, vector<int> &scc) {
  seen[s] = 1;
  scc.push_back(s);
  for (auto t : g[s]) {
    if (!seen[t]) {
      dfs2(t, g, scc);
    }
  }
}

int main() {
  cin >> N >> M;

  vector<vector<int>> G(N + 1), inverse_G(N + 1);
  seen.assign(N + 1, 0);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    inverse_G[b].push_back(a);
  }

  int time = 0;
  for (int i = 1; i <= N; i++) {
    if (!seen[i]) {
      dfs1(i, G, time);
    }
  }

  sort(finish_order.rbegin(), finish_order.rend());

  seen.assign(N + 1, 0);
  long long ans = 0;

  for (auto [_, v] : finish_order) {
    if (seen[v])
      continue;
    vector<int> scc;
    dfs2(v, inverse_G, scc);
    long long k = scc.size();
    ans += k * (k - 1) / 2;
  }

  cout << ans << endl;
}
