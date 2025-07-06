#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> primes(N+1, 0);

	// エラトステネスの篩
	// N * 調和級数なので計算量は NlogN
	for ( int i = 2; i <= N; i ++ ) {
		if ( primes[i] > 0 ) continue;
		int m = N / i;
		for ( int j = 1; j <= m; j ++ ) {
			primes[j * i] ++;
		}
	}

	int ans = 0;
	for ( int i = 2; i <= N; i ++) {
		if ( primes[i] >= K ) {
			ans ++;
		}
	}

	cout << ans << endl;
}
