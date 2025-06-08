#include <iostream>
#include <vector>

using namespace std;
const int N_MAX = 100000;
vector<long long> fact(N_MAX + 1);
vector<long long> ifact(N_MAX + 1);
long long mod = 1000000007;
int N;

// a^b mod m を計算する
long long modpow(long long a, long long b, long long m) {
  // q は、a^(2^i) の結果を保持
  long long p = 1, q = a;
  for (int i = 0; i < 30; i++) {
    if ((b & (1LL << i)) != 0) {
      p = p * q;
      p %= m;
    }
    q *= q;
    q %= m;
  }

  return p;
}

// a / b mod m を計算する
long long div(long long a, long long b, long long m) {

  // フェルマーの小定理より b^(-1) mod m = b^(m-2) mod m である
  return (a * modpow(b, m - 2, m)) % m;
}

// 階乗の計算をメモ化
void preprocessing() {
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = div(1, fact[i], mod);
  }
}

long long ncr(long long n, long long r) {
  if (n < r) {
    return 0;
  }
  return (fact[n] * ifact[r] % mod) * ifact[n - r] % mod;
}

int main() {
  cin >> N;
  preprocessing();

  for (int k = 1; k <= N; k++) {
    long long ans = 0;
    for (int r = 1; r <= (N + k - 1) / k; r++) {
      ans += ncr(N - (k - 1) * (r - 1), r);
      ans %= mod;
    }

    cout << ans << endl;
  }
}
