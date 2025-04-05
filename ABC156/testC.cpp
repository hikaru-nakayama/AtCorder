#include <iostream>
#include <algorithm>

using namespace std;

int N;
static const int MAX_N = 101;
int X[MAX_N];
#define INF (1<<27)

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X[i];
}

int main()
{
    input();
    int ans = INF;
    
    for (int p = 0; p <= 100; p++)
    {
        int sum = 0;
         for (int i = 0; i < N; i++)
        {
            sum += (X[i] - p) * (X[i] - p);
        }
        ans = min(ans, sum);
    }
   
    cout << ans << endl;
}