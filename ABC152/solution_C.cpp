#include <iostream>

using namespace std;
#define INFTY 201010

void chmin(int& min, int p)
{
    if (p < min)
        min = p;
}

int main()
{
    int n;
    cin >> n;

    int A[201010];

    for (int i = 0; i < n; i ++)
        cin >> A[i];
    int cnt = 0;
    int min = INFTY;
    for (int i = 0; i < n; i++)
    {
        chmin(min, A[i]);
        if (min == A[i])
            cnt ++;
    }

    cout << cnt << endl;
}