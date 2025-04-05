#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    bool solved[101010];
    int wa[101010];
    int N, M;
    cin >> N >> M;

    
    for (int i = 0; i < M; i ++)
    {
        int p;
        string s;

        cin >> p >> s;
        p --;
        if (s == "WA" && !solved[p])
            wa[p] ++;
        if (s == "AC") 
            solved[p] = true;
    }

    int correct = 0, penalty = 0;
    
    for (int i = 0; i < N; i ++)
    {
        if (solved[i])
        {
            correct ++;
            penalty += wa[i];
        }
            
    }

    cout << correct << " " << penalty << endl;
}