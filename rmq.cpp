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

    RMQ(int n_) : n(), dat(n_ * 4) {
        INF = numeric_limits<T>::max(); 

        // 必要な葉の数を計算
        // 2^x > n_ を満たす最小のの2^xを葉の数にすることで完全２分木になる
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
        dat.assign(4 * n, INF); // 全体をINFで初期化
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

    // [a, b) の区間に対するクエリ
    T query(int a, int b) {
        // dat[0]は [0, n) を表す
        return query_sub(a, b, 0, 0, n);
    }

    // dat[k]が表す区間を[l, r) とする
    T query_sub(int a, int b, int k, int l, int r) {
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

    // クエリの実行
    cout << "Query [0, 6): " << rmq.query(0, 6) << endl; // 1
    cout << "Query [1, 4): " << rmq.query(1, 4) << endl; // 1
    cout << "Query [4, 6): " << rmq.query(4, 6) << endl; // 4
    cout << "Query [7, 9): " << rmq.query(7, 9) << endl; // INF (INT_MAX)

    RMQ<long long> rmq_ll(N);
    rmq_ll.update(0, 10000000000LL);
    rmq_ll.update(1, 100LL);
    cout << "Query [0, 2) (long long): " << rmq_ll.query(0, 2) << endl; // 100

    return 0;
}
