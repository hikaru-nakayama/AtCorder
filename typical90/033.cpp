#include <iostream>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  if (H != 1 && W != 1) {
    int h = 0;
    int w = 0;
    if (H % 2 == 0) {
      h = H / 2;
    } else {
      h = H / 2 + 1;
    }

    if (W % 2 == 0) {
      w = W / 2;
    } else {
      w = W / 2 + 1;
    }

    cout << h * w << endl;
  } else if (H == 1) {
    cout << W << endl;
  } else if (W == 1) {
    cout << H << endl;
  }
}
