#include <iostream>
#include <vector>

using namespace std;

int n;
int j = 0;

vector<int> tmp1;
vector<int> to1;
vector<int> from1;

// 現在の状態を出力する（各 vector のサイズに合わせてカンマ区切りで表示）
void output(const vector<int>& from, const vector<int>& tmp, const vector<int>& to) {
    if ( j == 0 ) {
	    cout << "初期配置" << endl;
    } else {
            cout << j << "回目の移動" << endl;
    }
    cout << "from: [";
    for (size_t i = 0; i < from.size(); i++) {
        cout << from[i];
        if (i != from.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "tmp: [";
    for (size_t i = 0; i < tmp.size(); i++) {
        cout << tmp[i];
        if (i != tmp.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "to: [";
    for (size_t i = 0; i < to.size(); i++) {
        cout << to[i];
        if (i != to.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// ハノイの塔の再帰的移動
// m: 移動する盤の枚数
// from: 元の塔
// tmp: 補助の塔
// to: 目的の塔
void hanoi(int m, vector<int>& from, vector<int>& tmp, vector<int>& to) {
    if (m <= 0)
        return;
    
    // m-1 枚を from から tmp に移動 (to を補助として)
    hanoi(m - 1, from, to, tmp);
    
    // 一番上の盤を from から to へ移動
    if (!from.empty()) {
        int disk = from.back();
        from.pop_back();
        to.push_back(disk);
	j ++;
	output(from1, tmp1, to1);  // 移動後の状態を出力

    }
    
    
    // tmp にある m-1 枚を to へ移動 (from を補助として)
    hanoi(m - 1, tmp, from, to);
}

int main() {
    cin >> n;
    
    
    // 初期状態：from に 1～n の盤を積む（最小盤 1 が最上部になるように）
    // ここでは、下から大きい順に入れるので、vector の末尾が「山の頂上」となります。
    for (int i = n; i >= 1; i--) {
        from1.push_back(i);
    }

    output(from1, tmp1, to1);
    
    hanoi(n, from1, tmp1, to1);
    
    return 0;
}

