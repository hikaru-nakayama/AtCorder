#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  priority_queue<long long> que;
  for (int i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    que.push(b);
    // b は a の 1/2 より大きいので、必ず b から取り出されるので問題ない
    que.push(a - b);
  }

  long long ans = 0;
  while (K--) {
    long long score = que.top();
    que.pop();
    ans += score;
  }

  cout << ans << endl;
}
