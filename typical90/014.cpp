#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  long long ans = 0;
  // 学校と家の数が同じなので、これでOK
  for (int i = 0; i < N; i++) {
    ans += abs((long long)A[i] - B[i]);
  }

  cout << ans << endl;
}
