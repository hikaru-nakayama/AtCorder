#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_set<string> s;
  for (int i = 1; i <= N; i++) {
    string t;
    cin >> t;
    if (s.insert(t).second) {
      cout << i << endl;
    }
  }
}
