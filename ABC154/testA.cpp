#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    int n, m;
    cin >> n >> m;
    string u;
    cin >> u;
    if (u == s)
        cout << --n << " " << m << endl;
    else if (u == t)
        cout << n << " " << --m << endl;
}