#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> u, v;
vector<vector<int>> G;
int N;

vector<int> dfs(int x) {
	vector<int> dist(N+1, -1);
	stack<int> s;
	s.push(x);
	dist[x] = 0;
	while(!s.empty()) {
		int y = s.top();
		s.pop();
		for ( auto nv: G[y] ) {
			if ( dist[nv] == -1 ) {
					s.push(nv);
					dist[nv] = dist[y] + 1;
			}
		}
	}
	return dist;
}

int main () {
	cin >> N;
	u.resize(N+1);
	v.resize(N+1);
	G.resize(N+1);

	for ( int i = 0; i < N-1; i ++ ) {
		cin >> u[i] >> v[i];
	}

	for ( int i = 0; i < N-1; i ++ ) {
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}

	vector<int> dist0 = dfs(1);

	int mx = -1, mv = -1;
	for ( int i = 1; i <= N; i ++ ) {
		if ( mx < dist0[i] ) {
			mx = dist0[i];
			mv = i;
		}
	}

	vector<int> dist1 = dfs(mv);
	
	mx = -1;
	for ( int i = 1; i <= N; i ++ ) {
		mx = max(mx, dist1[i]);
	}

	cout << mx + 1 << endl;

}
