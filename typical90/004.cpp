#include <iostream>
#include <vector>

using namespace std;

int H, W;
vector<vector<int>> A;

void input() {
  cin >> H >> W;
  A.assign(H, vector<int>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
}

int main() {

  input();
  vector<int> R(H + 1);
  vector<int> C(W + 1);

  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      C[j] += A[i][j];
    }
  }

  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++) {
      R[j] += A[j][i];
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << C[j] + R[i] - A[i][j] << " ";
    }
    cout << endl;
  }
}
