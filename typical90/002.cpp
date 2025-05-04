#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;

bool isValid(string s) {
	int count = 0;
	for ( auto c: s ) {
		if ( c == '(' ) {
			count ++;
		} else {
			count --;
		}
		if ( count < 0 ) {
			return false;
		}
	}

	if ( count == 0 ) {
		return true;
	} else {
		return false;
	}
}

int main() {
	cin >> N;
	for ( ll bit = 0; bit <= (1<<N); bit++ ) {
	        string ans = "";
		for (int i = N-1; i >= 0; i -- ) {
			if ( !(bit & (1<<i)) ) {
				ans += '(';
			} else {
				ans += ')';
			}
		}

		if ( isValid(ans) ) {
			cout << ans << endl;
		}
	}
}
