#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    long long cnt[10][10] = {};

    for (int i = 1; i <= N; i++)
    {
        int top, btm;
        btm = i % 10;
        int x = i;
        while (x > 0)
        {
            top = x;
            x /= 10;
        }

        cnt[top][btm] ++;

    }
    long long ans = 0;
    for (int i = 0; i <= 9; i ++)
    {
        for (int j = 0; j <= 9; j ++)
        {
            ans += cnt[i][j] * cnt[j][i];
        }
    }

    cout << ans << endl;
}