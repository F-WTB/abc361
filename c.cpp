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
int N, K, A[200000];
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A + N);
    int ans = 1e9;
    for (int i = 0; i + N - K - 1 < N; ++i) chmin(ans, A[i + N - K - 1] - A[i]);
    cout << ans << '\n';
}
