// 全頂点対最短経路問題
// ワーシャルフロイド法


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
#define inf (1ll << 60)

int n, m;
vector<int> u, v, c;

void input() {
	cin >> n >> m;
	u.resize(m);
	v.resize(m);
	c.resize(m);

	for ( int i = 0; i < m; i ++ ) {
		cin >> u[i] >> v[i] >> c[i];
	}
}

int main() {
	input();
        vector<vector<ll>> d(n, vector<ll>(n, inf));

	for ( int i = 0; i < n; i ++ ) {
		d[i][i] = 0;
	}

	for ( int i = 0; i < m; i ++ ) {
		d[u[i] - 1][v[i] - 1] = c[i];
	}

	ll ans = 0;
	for ( int k = 0; k < n; k ++ ) {
		for ( int i = 0; i < n; i ++ ) {
			for ( int j = 0; j < n; j ++ ) {
				if ( d[i][k] < inf && d[k][j] < inf ) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		for ( int i = 0; i < n; i ++ ) {
			for ( int j = 0; j < n; j ++ ) {
				if ( d[i][j] < (1ll << 59) ) {
					ans += d[i][j];
				}
			}
		}
	}

	cout << ans << endl;
}
