#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> cnt;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        cnt[s] ++;

    }
    int max = -1;
    for (map<string, int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++)
    {
        pair<string, int> p = *itr;
        if (max < p.second)
            max = p.second;
    }

    for (map<string, int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++)
    {
        pair<string, int> p = *itr;
        if (max == p.second)
            cout << p.first << endl;
    }
}