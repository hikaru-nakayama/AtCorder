#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    bool flag = false;

    for (int i = 0; i < N; i ++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            flag = true;
            break;
        }
    }

    
    cout << (flag ? "NO" : "YES") << endl;
}