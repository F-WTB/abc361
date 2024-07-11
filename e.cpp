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

int N, A, B, C;
vector<pr> g[200000];

void dfs(vector<ll> &d, int v, int p) {
    for (auto [nv, c] : g[v]) {
        if (nv == p) continue;
        d[nv] = d[v] + c;
        dfs(d, nv, v);
    }
}

pair<int, ll> mfv(int v) {
    vector<ll> d(N);
    dfs(d, v, v);
    auto it = max_element(d.begin(), d.end());
    return make_pair(it - d.begin(), *it);
}

ll d() {
    return mfv(mfv(0).first).second;
}

int main() {
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N - 1; ++i) {
        cin >> A >> B >> C;
        --A, --B;
        g[A].emplace_back(B, C);
        g[B].emplace_back(A, C);
        sum += C;
    }
    cout << sum * 2 - d() << '\n';
}
