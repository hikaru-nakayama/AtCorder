#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

template <typename T>
struct RMQ {
    T INF;

    int n;          // 葉の数
    vector<T> dat;  // 完全二分木の配列
    vector<T> lazy;  // 完全二分木の配列（遅延評価用）

    RMQ(int n_) : n(), dat(n_ * 4), lazy(n_ * 4) {
        INF = numeric_limits<T>::max(); 

        // 必要な葉の数を計算
        // 2^x > n_ を満たす最小のの2^xを葉の数にすることで完全２分木になる
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
        dat.assign(n_ * 4, INF); // 全体をINFで初期化
        lazy.assign(n_ * 4, INF); // 全体をINFで初期化
    }

    void eval(int k) {
	    if ( lazy[k] == INF ) return;
	    if ( k < n - 1 ) {
		    lazy[k*2 + 1] = lazy[k];
		    lazy[k*2 + 2] = lazy[k];
	    }
	    dat[k] = lazy[k];
	    lazy[k] = INF;

    }

    // i:更新したい数列の位置 (0-indexed)
    // x:更新する値
    void update(int i, T x) {
        i += n - 1; // 数列i番目はdatのn-1+i番目に格納されている
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = min(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

    // [a, b) をxで更新する
    void bulk_update(int a, int b, T x) {
	    bulk_update_sub(a, b, x, 0, 0, n);
    }

    void bulk_update_sub(int a, int b, T x, int k, int l, int r) {
        if (a <= l && r <= b) { // クエリ範囲がノード区間を完全に含む場合
          lazy[k] = x;
	  eval(k);
        } else if ( a < r && l < b )  { // 一部が重なる場合
	  bulk_update_sub(a, b, x, k * 2 + 1, l, ( l + r ) / 2);
	  bulk_update_sub(a, b, x, k * 2 + 2, ( l + r ) / 2, r);
	  dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    // [a, b) の区間に対するクエリ
    T query(int a, int b) {
        // dat[0]は [0, n) を表す
        return query_sub(a, b, 0, 0, n);
    }

    // dat[k]が表す区間を[l, r) とする
    T query_sub(int a, int b, int k, int l, int r) {
	eval(k);
        if (r <= a || b <= l) { // クエリ範囲とノード区間が全く重ならない場合
            return INF;
        } else if (a <= l && r <= b) { // クエリ範囲がノード区間を完全に含む場合
            return dat[k];
        } else { // 一部が重なる場合
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};


// 動作確認用の main 関数 (例)
int main() {
    int N = 10; // 数列のサイズ
    RMQ<int> rmq(N);

    // 値を更新
    rmq.update(0, 5);
    rmq.update(1, 2);
    rmq.update(2, 8);
    rmq.update(3, 1);
    rmq.update(4, 9);
    rmq.update(5, 4);

    cout << rmq.query(0, 2) << endl;

    rmq.bulk_update(0, 2, 1);

    cout << rmq.query(0, 2) << endl;

    return 0;
}
