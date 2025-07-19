#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define INF (1ll << 60)
/*
 * 与えられた N 個の点 (x, y) に対し，
 *   (x, y) → (x − y, x + y)
 * という 45° 回転＋√2 倍スケーリングを施すと，
 *   マンハッタン距離 |x₁ − x₂| + |y₁ − y₂|
 * は
 *   max(|tx₁ − tx₂|, |ty₁ − ty₂|)
 * というチェビシェフ距離に変換される．
 *
 * x座標の差の絶対値を最大にする点、y座標の差の絶対値を最大にする点
 * をそれぞれ考えば良い
 */

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<long long> tx(N);
  vector<long long> ty(N);

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    tx[i] = x - y;
    ty[i] = x + y;
  }

  long long max_tx = -INF;
  long long min_tx = INF;
  long long max_ty = -INF;
  long long min_ty = INF;

  for (int i = 0; i < N; i++) {
    max_tx = max(max_tx, tx[i]);
    min_tx = min(min_tx, tx[i]);
    max_ty = max(max_ty, ty[i]);
    min_ty = min(min_ty, ty[i]);
  }

  while (Q--) {
    int q;
    cin >> q;
    long long xq = tx[q - 1];
    long long yq = ty[q - 1];
    long long mx = max(abs(max_tx - xq), abs(min_tx - xq));
    long long my = max(abs(max_ty - yq), abs(min_ty - yq));
    long long ans = max(mx, my);
    cout << ans << endl;
  }
}
