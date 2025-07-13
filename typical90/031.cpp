#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> W(n), B(n);

  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }

  const int W_MAX = 50;
  const int BLUE_MAX = (W_MAX * (W_MAX + 1) / 2) + W_MAX + 1;

  vector<vector<int>> grundy(W_MAX + 1, vector<int>(BLUE_MAX + 1, 0));

  for (int w = 0; w <= W_MAX; w++) {
    for (int b = 0; b <= BLUE_MAX; b++) {
      int k = b / 2;
      set<int> s;
      for (int l = b - k; l < b; l++) {
        s.insert(grundy[w][l]);
      }
      if (w >= 1 && w + b <= BLUE_MAX) {
        s.insert(grundy[w - 1][w + b]);
      }
      // mex を求める
      int g = 0;
      while (s.count(g)) {
        g++;
      }
      grundy[w][b] = g;
    }
  }

  int xor_sum = 0;
  for (int i = 0; i < n; i++) {
    xor_sum ^= grundy[W[i]][B[i]];
  }

  cout << (xor_sum == 0 ? "Second" : "First") << endl;
}
