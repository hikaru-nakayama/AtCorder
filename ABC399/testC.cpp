#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int N; // 頂点の数
int M; // 辺の数
int u[10000000];
int v[10000000];
vector<vector<int> > G; // グラフを表現するための隣接リスト
vector<int> colors(10000000);
queue<int> que;
int k = 0; // 隣接成分


void bfs(int vertex) {
	que.push(vertex);
	colors[vertex] = 1;
	while (!que.empty()) {
		int a = que.front();
                que.pop();

		for ( size_t i = 0; i < G[a].size(); i ++) {
			int neighbor = G[a][i];
			if (colors[neighbor] != 1) {
			  que.push(neighbor);
			  colors[neighbor] = 1;
			}
		}
	}
}

void dfs(int vertex) {
	colors[vertex] = 1;

	for ( size_t i = 0; i < G[vertex].size(); i ++) {
		int neighbor = G[vertex][i];
		if ( colors[neighbor] != 1 ) {
			dfs(neighbor);
		}
	}

}


void input() {
	cin >> N >> M;

	G.resize(N+1);
        colors.resize(N+1, 0);

	for ( int i = 0 ; i < M; i++ ) {
		cin >> u[i] >> v[i];
	}

	for ( int i = 0; i < M; i ++ ) {
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
}

int main() {
	input();

	for ( int i = 1; i <= N; i++ ) {
		int a = colors[i];
		if ( a != 1 ) {
			k++;
			dfs(i);
		}
	}

	cout << M - ( N - k ) << endl;

	return 0;
}

