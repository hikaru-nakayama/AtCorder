#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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

  vector<vector<int>> Rumor;

  vector<int> v;

  for (int i = 0; i < N; i++) {
    v[i] = i + 1;
  }

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    Rumor[x].push_back(y);
    Rumor[y].push_back(x);
  }

  do {
  } while (next_permutation(v.begin(), v.end()));
}
