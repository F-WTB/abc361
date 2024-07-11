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

int N, w, b, tw, tb;
string S, T;

int solve() {
    cin >> N >> S >> T;
    for (int i = 0; i < N; ++i) {
        (S[i] == 'W' ? w : b) |= 1 << i;
        (T[i] == 'W' ? tw : tb) |= 1 << i;
    }

    map<pr, bool> mp;
    queue<pair<pr, int>> q;

    pr p(w, b);
    q.emplace(p, 0);
    mp[p] = 1;

    while (q.size()) {
        auto [p, d] = q.front();
        q.pop();
        auto [w, b] = p;
        if (w == tw && b == tb) return d;
        int x = ~(w | b);
        int k = 0;
        while (!(x & 1 << k)) ++k;
        for (int i = 0; i < N + 2; ++i) {
            if (x & 3 << i) continue;
            int nw = w & ~(3 << i);
            int nb = b & ~(3 << i);
            nw |= (w >> i & 3) << k;
            nb |= (b >> i & 3) << k;
            pr np(nw, nb);
            if (mp[np]) continue;
            q.emplace(np, d + 1);
            mp[np] = 1;
        }
    }
    return -1;
}

int main() {
    cout << solve() << '\n';
}
