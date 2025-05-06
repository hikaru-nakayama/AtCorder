#include <iostream>
#include <vector>

using namespace std;

int N, K;
string S;

vector<vector<int>> create_next() {
  vector<vector<int>> nex(N + 1, vector<int>(26, -1));

  for (int i = N - 1; i >= 0; i--) {
    nex[i] = nex[i + 1];
    nex[i][S[i] - 'a'] = i;
  }

  return nex;
}

int main() {
  cin >> N >> K;
  cin >> S;
  string ans = "";
  int prev = -1;
  vector<vector<int>> nex = create_next();

  for (int i = 0; i < K; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      int idx = nex[prev + 1][c - 'a'];
      if (idx != -1 && N - (idx + 1) >= K - i - 1) {
        ans += c;
        prev = idx;
        break;
      }
    }
  }

  cout << ans << endl;
}
