#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> seen(N + 1, -1);
  vector<vector<int>> g(N + 1);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  stack<int> s;

  s.push(1);
  seen[1] = 0;
  while (!s.empty()) {
    int node = s.top();
    s.pop();

    for (auto c : g[node]) {
      if (seen[c] == -1) {
        seen[c] = seen[node] + 1;
        s.push(c);
      }
    }
  }

  vector<int> odd;
  vector<int> even;

  for (int i = 1; i <= N; i++) {
    if (seen[i] % 2 == 0) {
      even.push_back(i);
    } else {
      odd.push_back(i);
    }
  }

  if (even.size() > odd.size()) {
    for (int i = 0; i < N / 2; i++) {
      cout << even[i] << " ";
    }
  } else {
    for (int i = 0; i < N / 2; i++) {
      cout << odd[i] << " ";
    }
  }

  cout << endl;
}
