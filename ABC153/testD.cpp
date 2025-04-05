#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    long long HP;
    cin >> HP;
    long long cnt = 1;
    long long  ans = 0;
    while (HP > 0)
    {
        ans += cnt;
        HP /= 2;
        cnt *= 2;
    }

    cout << ans << endl;


}