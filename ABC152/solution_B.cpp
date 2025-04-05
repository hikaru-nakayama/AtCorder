#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    string ab, ba;

    for (int i = 0; i < b; i++)
        ab += char('0' + a); 
    for (int i = 0; i < a; i++)
        ba += char('0' + b);
    
    if (ab < ba)
        cout << ab << endl;
    else
        cout << ba << endl;
}