#include <iostream>
#include <vector>
using namespace std;
static const int MOD = 1000000007;
int gcd(int n, int m)
{
    if (m == 0)
        return n;
    return gcd(m, n % m);
}

long long lcm2(int n, int m)
{
    long long d = gcd(n, m);
    return (n * m)/ d;
}

long long lcm(vector<long long>& a)
{
    long long l = a[0];
    for (int i = 1; i < a.size(); i++)
        l = lcm2(l, a[i]);
    return l;
}

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    long long  l = lcm(A);
    long long ans = 0;
    for (int i = 0; i < N; i ++)
    {
        ans += l / A[i];
    }

    ans %= MOD;

    cout << ans << endl;
}
