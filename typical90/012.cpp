#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class UnionFind {
public:
  UnionFind() = default;

  explicit UnionFind(size_t n) : m_parents(n) {
    // m_parents = [0, 1, 2, 3, ..., n-1] と初期化される
    iota(m_parents.begin(), m_parents.end(), 0);
  }

  // 頂点iのrootのインデックスを返す
  int find(int i) {
    if (m_parents[i] == i) {
      return i;
    }

    // パス圧縮
    // 全ての頂点の親としてrootに繋ぎ直すことで次回の探索を減らす
    return m_parents[i] = find(m_parents[i]);
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
      m_parents[b] = a;
    }
  }

  bool connected(int a, int b) { return (find(a) == find(b)); }

private:
  vector<int> m_parents;
};

int f(int r, int c, int w) { return (r - 1) * w + c; }

int main() {
  int H, W, Q;
  cin >> H >> W >> Q;

  vector<vector<int>> m(H + 1, vector<int>(W + 1, 0));

  UnionFind uf(H * W);

  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    int r, c;
    int ra, ca, rb, cb;
    if (t == 1) {
      cin >> r >> c;
      m[r][c] = 1;
      int target = f(r, c, W);

      if (r > 1 && m[r - 1][c]) {
        int u = f(r - 1, c, W);
        uf.merge(u, target);
      }

      if (c > 1 && m[r][c - 1]) {
        int u = f(r, c - 1, W);
        uf.merge(u, target);
      }

      if (r < H && m[r + 1][c]) {
        int u = f(r + 1, c, W);
        uf.merge(u, target);
      }

      if (c < W && m[r][c + 1]) {
        int u = f(r, c + 1, W);
        uf.merge(u, target);
      }
    } else if (t == 2) {
      cin >> ra >> ca >> rb >> cb;
      int a = f(ra, ca, W);
      int b = f(rb, cb, W);

      bool is_connected = uf.connected(a, b);

      if (is_connected && m[ra][ca] && m[rb][cb]) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}
