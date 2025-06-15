#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;

  vector<long long> A(N), B(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  long long diff = 0;
  for (int i = 0; i < N; i++) {
    diff += abs(A[i] - B[i]);
  }

  if (K >= diff && abs(K - diff) % 2 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
