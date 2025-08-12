#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> A(N, vector<int>(6));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> A[i][j];
    }
  }

  // 各ダイスの総和
  vector<long long> sum_a(N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 6; j++) {
      sum_a[i] += A[i][j];
    }
  }

  long long ans = 1;
  for (int i = 0; i < N; i++) {
    ans = ans * sum_a[i] % 1000000007;
  }

  cout << ans << endl;
}
