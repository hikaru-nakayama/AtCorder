#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
  long double T;
  long double l, X, Y;
  int Q;

  cin >> T;
  cin >> l >> X >> Y;
  cin >> Q;

  vector<long double> E(Q);

  for (int i = 0; i < Q; i++) {
    cin >> E[i];
  }

  for (int i = 0; i < Q; i++) {
    // E869120 君の radian 角
    long double alpha = (2.0L * M_PI * E[i]) / T;
    // E869120 君 の y 座標
    long double y_e = -(l / 2.0L) * sinl(alpha);
    // E869120 君 の z 座標
    long double z_e = (l / 2.0L) - (l / 2.0L) * cosl(alpha);

    long double tan_v = z_e / (sqrtl(X * X + abs(Y - y_e) * abs(Y - y_e)));

    long double ans = atanl(tan_v);

    long double ans_deg = ans * 180.0L / acosl(-1.0L);
    cout << fixed << setprecision(8) << ans_deg << endl;
  }
}
