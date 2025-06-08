#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// a と b の最大公約数を求める
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    // ユークリッドの互除法は d = gcd(a, b) とすると ( a, b ) => ( b, r ) => ...
    // => ( d, 0 ) となるので, d = x * d + y * 0 の方程式に帰着される。これは x
    // = 1 y = 0 を解にもつ。
    x = 1;
    y = 0;
    return a;
  }
  // ax + by = d は、a, b に対して互除法を使うことで、b(qx + y) + rx = d
  // と書ける。(a, b) と (b, r) の最大公約数は同じなので、qx + y = s, x = t
  // とおくと、 bs + rt = dとなり、より係数が小さい問題に帰着される。
  // 最大公約数が変わらないので、右辺の値に対して解があることが保証されている。
  // つまり、この操作を繰り返せば、d = x * d + y * 0
  // の自明な式に辿り着けることになる。x, y が決定されたので、逆順に辿れば元の
  // x, y が求まる。
  // x, y は s, t 以下は、bs + rt = d の問題になったことを表現している。
  long long d = extGCD(b, a % b, y, x);
  // y = s - qx = s - a / b * x の計算をしている
  y -= a / b * x;
  return d;
}

int main() {
  int N;
  cin >> N;

  long long a, b, c;
  vector<int> coin(3);

  cin >> coin[0] >> coin[1] >> coin[2];
  sort(coin.begin(), coin.end());

  a = coin[0];
  b = coin[1];
  c = coin[2];
  const int P = 10000;
  int ans = P;

  for (int x = 0; x < P; x++) {
    for (int y = 0; y < P; y++) {
      int tmp = a * x + b * y;
      if (tmp > N || (N - tmp) % c != 0) {
        continue;
      }

      int z = (N - tmp) / c;
      if (ans > x + y + z) {
        ans = x + y + z;
      }
    }
  }

  cout << ans << endl;
}
