// ダイクストラ法
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
typedef long long ll;

int N;
int M;
struct edge{
	int to,cost,idx;
};
vector<vector<edge>> G(N+1);
vector<int> u, v, C;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q; // (cost, vertex)

#define INF (1LL << 60)



void input() {
    cin >> N >> M;
    u.resize(M);
    v.resize(M);
    C.resize(M);
    G.assign(N + 1, {});

    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i] >> C[i];
    }

    for (int i = 0; i < M; i++) {
        G[u[i]].push_back({v[i], C[i], i});
        G[v[i]].push_back({u[i], C[i], i});
    }
}

int main() {
    input();
    vector<ll> dist(N + 1, INF);
    dist[1] = 0;
    q.push({0, 1}); // {cost, vertex}
    vector<int>ans(G.size());

    while (!q.empty()) {
        auto [cost, x] = q.top();
        q.pop();

	// 重複を取り除く
        if (dist[x] != cost) continue;

        for (auto [to, c, idx] : G[x]) {
            ll new_cost = dist[x] + c;
            if (dist[to] > new_cost) {
                dist[to] = new_cost;
                q.push({new_cost, to});
		ans[to] = idx;
            }
        }
    }


    for (int i = 2; i< N+1; i++) {
       cout << ans[i] + 1 << ' ';
    }

    cout << endl;
}

