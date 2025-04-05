#include <iostream>
#include <vector>
#include <numeric>
#define rep(i, N) for(int (i); (i) < N; (i) ++)

using namespace std;

int main()
{
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> A(N);

    for (int i = 0; i < N; i ++)
    {
        cin >> A[i];
    }
    
    //配列の要素の総和を求める
    int sum = accumulate(A.begin(), A.end(), 0);

    for (int i = 0; i < K + 1; i ++)
    {
        if (sum + i >= N * M)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}