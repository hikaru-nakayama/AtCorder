#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<long long> A(N + Q + 100);

  int start = Q + 1;
  int end = Q + N;

  for (int i = start; i <= end; i++) {
    int a;
    cin >> a;
    A[i] = a;
  }

  for (int i = 0; i < Q; i++) {
    int T, x, y;
    cin >> T >> x >> y;

    if (T == 1) {
      int tmp = A[y + start - 1];
      A[y + start - 1] = A[x + start - 1];
      A[x + start - 1] = tmp;
    } else if (T == 2) {
      A[start - 1] = A[end];
      start = start - 1;
      end = end - 1;
    } else {
      cout << A[start + x - 1] << endl;
    }
  }
}
