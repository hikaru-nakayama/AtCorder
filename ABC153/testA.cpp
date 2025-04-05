#include <iostream>

using namespace std;

int main()
{
    int HP, At;
    cin >> HP >> At;

    int cnt = 0;
    while (HP > 0)
    {
        HP -= At;
        cnt ++;
    }

    cout << cnt << endl;
}