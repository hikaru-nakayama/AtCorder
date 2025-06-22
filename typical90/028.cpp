#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> field(1001, vector<int>(1001, 0));

  for (int i = 0; i < N; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;

    field[lx][ry] -= 1;
    field[rx][ry] += 1;
    field[rx][ly] -= 1;
    field[lx][ly] += 1;
  }

  // y 軸方向に累積和を求める
  for (int i = 0; i < 1001; i++) {
    for (int j = 1; j < 1001; j++) {
      field[i][j] += field[i][j - 1];
    }
  }

  // x 軸方向に累積和を求める
  for (int i = 1; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      field[i][j] += field[i - 1][j];
    }
  }

  vector<int> ans(N + 1, 0);

  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      if (field[i][j] > 0) {
        ans[field[i][j]]++;
      }
    }
  }

  for (int k = 1; k <= N; k++) {
    cout << ans[k] << endl;
  }
}
