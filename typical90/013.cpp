#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF (1ll << 60)
using ll = long long;

struct edge {
  int to;
  int cost;
};

int n, m;

// from から全頂点への最短距離を返す
vector<ll> get_time_cost(int from, const vector<vector<edge>> &g) {
  // ★ priority_queue の型を (cost, vertex) にする ★
  // costが小さい順で取り出される
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que; // { cost, index }

  vector<ll> time(n + 1, INF); // time[i] は from→i の最短時間
  time[from] = 0;
  que.push({0ll, from});

  while (!que.empty()) {
    auto [cost_u, u] = que.top();
    que.pop();

    if (cost_u > time[u])
      continue;

    for (auto &e : g[u]) {
      int v = e.to;
      ll new_cost = cost_u + (ll)e.cost;
      if (new_cost < time[v]) {
        time[v] = new_cost;
        que.push({new_cost, v});
      }
    }
  }

  return time;
}

int main() {
  cin >> n >> m;
  vector<vector<edge>> g(n + 1);

  vector<int> a(m), b(m), c(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    g[a[i]].push_back({b[i], c[i]});
    g[b[i]].push_back({a[i], c[i]});
  }

  vector<ll> t_1 = get_time_cost(1, g);
  vector<ll> t_2 = get_time_cost(n, g);

  for (int i = 1; i <= n; i++) {
    cout << t_1[i] + t_2[i] << endl;
  }
}
