#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int T; // テストケース数
int N;
int n[1000000];


int main () {
	cin >> T;

	for ( int i = 0; i < T; i ++ ) {
		cin >> N;

		vector<vector<int> > position(N+1);
		int row[1000000];

		for ( int j = 0; j < 2*N; j ++ ) {
			cin >> row[j];
		}

                for ( int j = 0; j < 2*N; j ++ ) {
			position[row[j]].push_back(j);
		}

		set<pair<int, int> > ans;
		for ( int j = 0; j+1 < 2*N; j ++) {
			int a = row[j];
			int b = row[j+1];
			if (position[a][0] + 1 == position[a][1]) continue;
			if (position[b][0] + 1 == position[b][1]) continue;

			vector<int> v{position[a][0], position[a][1], position[b][0], position[b][1]};
			sort(begin(v), end(v));

			if (v[0] + 1 == v[1] && v[2] + 1 == v[3]) {
				ans.emplace(minmax(a, b));
			}

		}
		cout << ans.size() << endl;

	}
}
