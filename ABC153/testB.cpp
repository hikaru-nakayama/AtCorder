#include <iostream>

using namespace std;

int main()
{
    int HP, N;
    cin >> HP >> N;
    int A[101010];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += A[i];
    }
    if (total >= HP)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
}