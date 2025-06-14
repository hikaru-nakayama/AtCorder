#include <iostream>

using namespace std;

long long pow(int n, int m) {
  long long p = 1;
  long long q = n;

  for (int i = 0; i < 60; i++) {
    if ((m & (1LL << i)) != 0) {
      p = p * q;
    }
    q *= q;
  }
  return p;
}

int main() {
  long long a, b, c;
  cin >> a >> b >> c;

  long long ans;
  ans = pow(c, b);

  if (a < ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
