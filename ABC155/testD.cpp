#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int N;
    int K;
    cin >> N >> K;

    ll A[201010];
    vector<ll> sum_pair;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j ++)
        {
            sum_pair.push_back(A[i] * A[j]);
        }
    }

    sort(sum_pair.begin(), sum_pair.end());
    cout << sum_pair[K - 1] << endl;
    
}
