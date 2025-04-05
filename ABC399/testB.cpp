#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n;
vector<int> p(n);
int ans[100];

void input() {
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		p.push_back(x);
	}
}

int main() {
	input();
	vector<int> rank(n);
	int r = 1;

	while (true) {

		int x = 0;
		for ( int i = 0; i < n; i++) {
			if (rank[i]) continue;
			x = max(x, p[i]);
		}

		if (!x) break;

		int k = 0;
		for ( int i = 0; i < n; i++) {
			if (x == p[i]) {
				k++;
				rank[i] = r;
			}
		}

		r += k;
		
	}

	for ( int i = 0; i < n; i ++) {
		cout << rank[i] << endl;
	}


}
	
