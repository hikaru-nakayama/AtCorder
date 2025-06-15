#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  long long A, B, C;
  cin >> A >> B >> C;

  long long edge_length = gcd(gcd(A, B), C);

  cout << (A / edge_length) + (B / edge_length) + (C / edge_length) - 3 << endl;
}
