#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> stum(N);
    

    for (int i = 0; i < N; i ++)
        cin >> stum[i];
    
    if (K >= N)
    {
        cout << 0 << endl;
        return 0;
    }
    
    sort(stum.rbegin(), stum.rend());
    
    long long ans = 0;
    for (int i = K; i < N; i++)
    {
        ans += stum[i];
    }

    cout << ans << endl;
}