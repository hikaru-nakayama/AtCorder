#include <iostream>

using namespace std;

int N, K;

void input()
{
    cin >> N >> K;
}

int main()
{
    input();

    int cnt = 0;
    while (N)
    {
        N /= K;
        cnt ++;
    }

    cout << cnt  << endl;
}