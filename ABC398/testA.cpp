#include <iostream>

using namespace std;

int n;
string ans;

int main() {
	cin >> n;

	int m;

	if ( n % 2 == 0 ) {
		m = n / 2 - 1;
	} else {
		m = n / 2;
	}

	for ( int i = 0; i < m; i++ ) {
		ans += '-';
	}

	if ( n % 2 == 0 ) {
		ans += "==";
	} else {
		ans += '=';
	}

        for ( int i = 0; i < m; i++ ) {
		ans += '-';
	}

	cout << ans << endl;

}
