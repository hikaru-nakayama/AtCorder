#include <iostream>
#include <vector>
using namespace std;
#define INFTY 1000000
int main()
{
    int n;
    cin >> n;
    vector<int> A(n + 1);
    A[0] = INFTY;

    for (int i = 1; i <= n; i ++)
    {
        cin >> A[i];
    }
    
    int sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        int cnt = 0;
        for (int j = 0; j <= i - 1; j ++)
        {
            if (A[i] <= A[j])
            {
                cnt++;
                continue;
            } else
                break;
        }
        if (cnt == i)
            sum ++;
    }

    cout << sum << endl;
}