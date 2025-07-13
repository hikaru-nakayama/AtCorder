#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int &x : a)
    cin >> x;

  int right = 0, ans = 0;
  unordered_map<int, int> freq; // 値 → 出現回数

  for (int left = 0; left < N; ++left) {
    while (
        right < N &&
        (freq.size() < K ||
         (freq.size() == K &&
          freq.count(
              a[right])))) { // すでに K種類になっていても、
                             // 「すでに含まれている種類」を追加するだけなら種類数は増えないのでOK
      freq[a[right]]++;
      ++right;
    }

    ans = max(ans, right - left);

    // 重複した値の時は削除しない
    if (--freq[a[left]] == 0)
      freq.erase(a[left]);
  }

  cout << ans << endl;
}
