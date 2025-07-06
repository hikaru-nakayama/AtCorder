
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
        INF = numeric_limits<T>::min(); 

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
            dat[i] = max(dat[2 * i + 1], dat[2 * i + 2]);
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
	  dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
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
            return max(vl, vr);
        }
    }
};


int main() {
    int W, N;
    cin >> W >> N;
    RMQ<int> rmq(W+1);
    for ( int i = 0; i < N; i ++ ) {
	    int L, R;
	    cin >> L >> R;
	    int max_v = rmq.query(L, R+1);
	    if ( max_v != numeric_limits<int>::min() ) {
	      cout << max_v + 1 << endl;
	      rmq.bulk_update(L, R+1, max_v + 1);
	    } else {
	      cout << 1 << endl;
	      rmq.bulk_update(L, R+1, 1);
	    }
    }
}
