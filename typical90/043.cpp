#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct edge {
  int to;
  int direction; // 0: 横, 1: 縦
  int cost;      // 方向転換コスト(0 or 1)
};

struct node {
  int index;
  int direction;
  int cost; // 累積コスト
};

struct Compare {
  bool operator()(const node &a, const node &b) const {
    return a.cost > b.cost;
  }
};

int dijkstra(vector<vector<vector<edge>>> &graph, int start, int goal, int graphSize) {
  const int INF = 1e9;

  priority_queue<node, vector<node>, Compare> que;
  vector<vector<int>> record(graphSize, vector<int>(2, INF));

  // 開始は横向き(0)から。start での向き切替が0コストで入っている想定なので十分
  record[start][0] = 0;
  que.push({start, 0, 0});

  while (!que.empty()) {
    auto current_node = que.top();
    que.pop();

    if (current_node.cost > record[current_node.index][current_node.direction]) continue;

    const auto &paths = graph[current_node.index][current_node.direction];
    for (auto e : paths) {
      int nc = current_node.cost + e.cost;
      if (nc < record[e.to][e.direction]) {
        record[e.to][e.direction] = nc;
        que.push({e.to, e.direction, nc});
      }
    }
  }

  return min(record[goal][0], record[goal][1]);
}

int main() {
  int H, W;
  cin >> H >> W;

  int r_s, c_s, r_t, c_t; // (r_s, c_s) -> (r_t, c_t)
  cin >> r_s >> c_s >> r_t >> c_t;
  --r_s; --c_s; --r_t; --c_t;

  vector<vector<char>> S(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> S[i][j];
  }

  auto id = [&](int i, int j) { return i * W + j; };

  vector<vector<vector<edge>>> g(H * W, vector<vector<edge>>(2));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') continue;

      // 横(0)のまま移動
      if (j + 1 < W && S[i][j + 1] != '#') g[id(i, j)][0].push_back({id(i, j + 1), 0, 0});
      if (j - 1 >= 0 && S[i][j - 1] != '#') g[id(i, j)][0].push_back({id(i, j - 1), 0, 0});

      // 縦(1)のまま移動
      if (i + 1 < H && S[i + 1][j] != '#') g[id(i, j)][1].push_back({id(i + 1, j), 1, 0});
      if (i - 1 >= 0 && S[i - 1][j] != '#') g[id(i, j)][1].push_back({id(i - 1, j), 1, 0});

      // 向き変更（同一マスで 0 <-> 1）
      if (id(i, j) != id(r_s, c_s)) {
        g[id(i, j)][0].push_back({id(i, j), 1, 1});
        g[id(i, j)][1].push_back({id(i, j), 0, 1});
      } else {
        // start の向き変更コストは 0
        g[id(i, j)][0].push_back({id(i, j), 1, 0});
        g[id(i, j)][1].push_back({id(i, j), 0, 0});
      }
    }
  }

  int ans = dijkstra(g, id(r_s, c_s), id(r_t, c_t), H * W);
  cout << ans << endl;
}

