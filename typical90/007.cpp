#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, Q;

int main() {
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());
  cin >> Q;

  vector<int> B(Q);
  for (int i = 0; i < Q; i++) {
    cin >> B[i];
    auto p = upper_bound(A.begin(), A.end(), B[i]);
    if (p == A.end()) {
      cout << B[i] - *prev(p) << endl;
    } else if (p == A.begin()) {
      cout << *p - B[i] << endl;
    } else {
      cout << min(*p - B[i], B[i] - *prev(p)) << endl;
    }
  }
}
