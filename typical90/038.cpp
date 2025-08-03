#include <iostream>

using namespace std;
#define TEN18 1000000000000000000LL

unsigned long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

int main() {
  unsigned long long A, B;
  cin >> A >> B;

  unsigned long long gcd_a_b = gcd(max(A, B), min(A, B));

  unsigned long long a, b;
  a = A / gcd_a_b;
  b = B / gcd_a_b;

  unsigned long long ans = a * b * gcd_a_b;

  if (ans % A == 0 && ans % B == 0 && ans <= TEN18) {
    cout << ans << endl;
  } else {
    cout << "Large" << endl;
  }
}
