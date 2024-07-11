#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

int a[3], b[3], c[3], d[3];

int main() {
    for (int i = 0; i < 3; ++i) cin >> a[i];
    for (int i = 0; i < 3; ++i) cin >> b[i];
    for (int i = 0; i < 3; ++i) cin >> c[i];
    for (int i = 0; i < 3; ++i) cin >> d[i];

    for (int i = 0; i < 3; ++i) chmax(a[i], c[i]);
    for (int i = 0; i < 3; ++i) chmin(b[i], d[i]);

    for (int i = 0; i < 3; ++i)
        if (b[i] <= a[i]) {
            cout << "No" << '\n';
            return 0;
        }
    cout << "Yes\n";
}
