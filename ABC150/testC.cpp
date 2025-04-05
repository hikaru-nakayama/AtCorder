#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
#define rep(i, N) for (int(i) = 0; (i) < N; (i) ++)
int main()
{
    int N;
    int P[8], Q[8];

    //入力を受け付ける
    cin >> N;

    rep(i, N) cin >> P[i];
    
    rep(i, N) cin >> Q[i];

    vector<int> v;
    
    rep(i, N) v.push_back(i + 1);

    
    int idx = 0, a = -1, b = -1;
    do {
        bool ok = true;
        rep(i, N) if (P[i] != v[i]) ok = false;
        if (ok) a = idx;

        ok = true;

        rep(i, N) if (Q[i] != v[i]) ok = false;
        if (ok) b = idx;

        idx ++;

    } while (next_permutation(v.begin(), v.end()));

    
    int ans = abs(a - b);
    cout << ans << endl;

}