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
ll N;

int second() {
    int ok = 0, ng = 1e9 + 1;
    while (abs(ok - ng) > 1) {
        int m = (ok + ng) / 2;
        ((ll)m * m <= N ? ok : ng) = m;
    }
    return ok;
}
int third() {
    int ok = 0, ng = 1e6 + 1;
    while (abs(ok - ng) > 1) {
        int m = (ok + ng) / 2;
        ((ll)m * m * m <= N ? ok : ng) = m;
    }
    return ok;
}

ll pow(ll a, int n) {
    ll v = 1;
    for (ll b = 1; b <= n; b <<= 1, a *= a)
        if (n & b) v *= a;
    return v;
}
ll pow(int a, int n) { return pow(ll(a), n); }

int main() {
    cin >> N;
    int c = third() + 1, d = second() + 1;
    vector<bool> v(c);
    ll ans = 1 + d - c;
    cerr << c << ',' << d << '\n';
    for (ll a = 2; a < c; ++a) {
        if (v[a]) continue;
        for (bint x = a * a; x <= N; x *= a) {
            if (x < c) v[int(x)] = 1;
            if (c <= x && x < d)
                continue;
            ++ans;
        }
    }
    cout << ans << '\n';
}
