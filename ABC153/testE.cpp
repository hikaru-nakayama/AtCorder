#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000

 void chmin(int& min, int p)
 {
     if (min > p)
         min = p;
 }

int main()
{
    
    int HP, N;
    int A[1010], B[1010];
    cin >> HP >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    vector< vector<int> > dp(1010, vector<int>(10101)); //i番目までの魔法を使って残りHPをhにする最小の魔力
    

    for (int i = 0; i <= N; i ++)
    {
         for (int j = 0; j <= HP; j++)
         {
             dp[i][j] = INF; //最小値を求めるので十分大きな値で初期化
         }   
    }
    dp[0][HP] = 0; //0番目を使って残りをHPにするのは当然魔力量０

     for (int i = 0; i <= N; i++)
     {
          for (int h = HP; h >= 0; h--)
          {
              chmin(dp[i + 1][h], dp[i][h]);
              chmin(dp[i][max(0, h - A[i])], dp[i][h] + B[i]);
          }
     }

     cout << dp[N][0] << endl;


}