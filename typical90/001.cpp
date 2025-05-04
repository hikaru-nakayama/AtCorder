// 二分探索
#include <iostream>
#include <vector>

using namespace std;
int N, K, L;
vector<int> A;

void input() {
	cin >> N >> L;
	cin >> K;
	A.resize(N+1);

	for (int i = 0; i < N; i ++ ) {
		cin >> A[i];
	}
}

bool check(int x) {
	int l = 0;
	int count = 0;

	for ( int i = 0; i < N; i ++ ) {
		if ( i == 0 ) {
			l = A[i];
		} else {
			l += A[i] - A[i-1];
		}

		if ( l >= x && count < K ) {
			count ++;
			l = 0;
		}

		if ( count == K ) {
			if ( L - A[i] >= x ) {
				return true;
			} else {
				return false;
			}
		}
	}

	return false;
}

int main () {
	input();

	int left = -1;
	int right = 1000000001;


	while ( right - left != 1 ) {

	        int md = ( left + right ) / 2;
		bool t = check(md);

		if (t) {
			left = md;
		} else {
			right = md;
		}
	}

	cout << left << endl;


}
