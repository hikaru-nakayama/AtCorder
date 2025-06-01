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
