#include <iostream>
#include <vector>

using namespace std;

int N;

void dfs(int s, vector<vector<long long>> &tree, long long &ans,
         vector<long long> &seen, vector<long long> &ct) {
  seen[s] = 1;
  ct[s] = 1;
  for (auto t : tree[s]) {
    if (seen[t] == -1) {
      dfs(t, tree, ans, seen, ct);
      ct[s] += ct[t];
    }
  }
  ans += ct[s] * (N - ct[s]);
}

int main() {

  cin >> N;
  vector<vector<long long>> T(N + 1);
  vector<long long> seen(N + 1, -1);
  vector<long long> ct(N + 1, 0);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }

  long long ans = 0;

  dfs(1, T, ans, seen, ct);

  cout << ans << endl;
}
