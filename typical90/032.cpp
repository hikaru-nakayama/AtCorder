#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define INF (1ll << 60)

int main() {
  int N;
  cin >> N;

  vector<vector<int>> A(N + 1, vector<int>(N + 1));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
    }
  }

  int M;
  cin >> M;

  vector<vector<int>> Rumor(N + 1);

  vector<int> v(N);

  for (int i = 0; i < N; i++) {
    v[i] = i + 1;
  }

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    Rumor[x].push_back(y);
    Rumor[y].push_back(x);
  }

  long long ans = INF;
  do {
    long long result = 0;
    for (int i = 0; i < N; i++) {
      vector<int> bad = Rumor[v[i]];
      for (auto b : bad) {
        if (i + 1 < N && b == v[i + 1]) {
          result = -1;
        }
      }
      if (result != -1) {
        result += A[v[i]][i + 1];
      }
    }
    if (result != -1) {
      ans = min(ans, result);
    }
  } while (next_permutation(v.begin(), v.end()));

  if (ans != INF) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}
