#include <iostream>

using namespace std;
typedef long long ll;
int idx = 0;
int chmax(ll& max, int p, int id)
{
    if (max < p)
    {
        max = p;
        return id;
    }
    return idx;
}


int main()
{
    int N, K;
    cin >> N >> K;
    int p[201010];
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    int sum = 0;
    for (int j = 0; j < K; j++)
    {
        sum += p[j];
    }

    ll max = sum;

    for (int i = 0; i < N - K; i++)
    {
        sum = sum - p[i] + p[i + K];
        idx = chmax(max, sum, i + 1);
    }

    double ans = 0;

    for (int i = idx; i < idx + K; i++)
    {
        ans += (p[i] + 1)  / 2.0;
    }

    cout << ans << endl;
}