// 以下のアルゴリズムはTLE してしまっている
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
  long double ans = 0.0L;
  int N;
  cin >> N;

  vector<long double> X(N + 1), Y(N + 1);

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j)
        continue;
      for (int k = 0; k < N; k++) {

        if (k == j || k == i)
          continue;
        pair<long double, long double> P_i = {X[i], Y[i]};
        pair<long double, long double> P_j = {X[j], Y[j]};
        pair<long double, long double> P_k = {X[k], Y[k]};

        pair<long double, long double> u = {P_i.first - P_j.first,
                                            P_i.second - P_j.second};
        pair<long double, long double> v = {P_k.first - P_j.first,
                                            P_k.second - P_j.second};

        double u_norm = sqrtl(u.first * u.first + u.second * u.second);
        double v_norm = sqrtl(v.first * v.first + v.second * v.second);
        if (u_norm == 0.0L || v_norm == 0.0L) {
          continue;
        }

        long double inner_product = u.first * v.first + u.second * v.second;

        long double cos_theta = inner_product / (u_norm * v_norm);

        long double angle = acosl(cos_theta);
        ans = max(ans, angle);
      }
    }
  }

  long double ans_deg = ans * 180.0L / acosl(-1.0L);
  cout << fixed << setprecision(8) << ans_deg << endl;
}
