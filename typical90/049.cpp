#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class UnionFind {
public:
  UnionFind() = default;

  explicit UnionFind(int n) : m_parents(n), m_size(n, 1) {
    iota(m_parents.begin(), m_parents.end(), 0);
  }

  // 頂点 i の root
  int find(int i) {
    if (m_parents[i] == i)
      return i;
    return m_parents[i] = find(m_parents[i]); // パス圧縮
  }

  // 併合（サイズの小さい方を大きい方にぶら下げる）
  bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (m_size[a] < m_size[b])
      swap(a, b);
    m_parents[b] = a;
    m_size[a] += m_size[b];
    return true;
  }

  bool connected(int a, int b) { return find(a) == find(b); }

  // 頂点 x が属する木（連結成分）のサイズ
  int size(int x) { return m_size[find(x)]; }

private:
  vector<int> m_parents;
  vector<int> m_size; // 根にのみ正しいサイズが入る
};

// 辺の定義
struct Edge {
  long long u;
  long long v;
  long long cost;
};

bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }

struct Kruskal {
  UnionFind uft;
  long long sum;
  vector<Edge> edges;
  int V; // 頂点数

  Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
  void init() {
    sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
    uft = UnionFind(V);
    sum = 0;
    for (auto e : edges) {
      if (!uft.connected(e.u, e.v)) { // 閉路にならなければ加える
        uft.merge(e.u, e.v);
        sum += e.cost;
      }
    }

    if (uft.size(edges[0].u) != V) {
      sum = -1;
    }
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  vector<long long> C(M), R(M), L(M);

  for (int i = 0; i < M; i++) {
    cin >> C[i] >> L[i] >> R[i];
  }

  vector<Edge> edges;

  for (int i = 0; i < M; i++) {
    // 頂点を区間の端点とする [2, 4)
    // 全てのbitは、区間のXORで求めることができるので、任意の区間を作れるように全てを頂点で繋げる
    edges.push_back({L[i] - 1, R[i], C[i]});
  }
  Kruskal krs(edges, N + 1);
  cout << krs.sum << endl;
}
