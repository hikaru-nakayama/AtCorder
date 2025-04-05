#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[101];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    bool flag = true;

    for (int i = 0; i < N; i++)
    {
        if (A[i] % 2 == 0)
        {
            if (A[i] % 3 != 0 && A[i] % 5 != 0)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << "APPROVED" << endl;
    else 
        cout << "DENIED" << endl;
        
}