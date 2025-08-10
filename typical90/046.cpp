#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> count_a(46, 0), count_b(46, 0), count_c(46, 0);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    count_a[a % 46] += 1;
  }
  for (int i = 0; i < N; i++) {
    long long b;
    cin >> b;
    count_b[b % 46] += 1;
  }
  for (int i = 0; i < N; i++) {
    long long c;
    cin >> c;
    count_c[c % 46] += 1;
  }

  long long ans = 0;

  for (int i = 0; i < 46; i++) {
    for (int j = 0; j < 46; j++) {
      for (int k = 0; k < 46; k++) {
        long long sum = i + j + k;
        if (sum % 46 == 0) {
          ans += count_a[i] * count_b[j] * count_c[k];
        }
      }
    }
  }

  cout << ans << endl;
}
