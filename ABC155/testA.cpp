#include <iostream>
#include <set>

using namespace std;


int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    set<int> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);

    if (st.size() == 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
}