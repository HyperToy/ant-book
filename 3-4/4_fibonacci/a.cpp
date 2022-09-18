#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define mod 1000000007

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &a, mat &b) {
    mat c(a.size(), vec(b[0].size(), 0));
    rep(i,a.size()) {
        rep(k,b.size()) {
            rep(j,b[k].size()) {
                (c[i][j] += a[i][k] * b[k][j]) %= mod;
            }
        }
    }
    return c;
}

mat pow(mat a, ll n) {
    mat b(a.size(), vec(a[0].size(), 0));
    rep(i,a.size()) {
        b[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) b = mul(b, a);
        a = mul(a, a);
        n >>= 1;
    }
    return b;
}

ll n;

void solve() {
    mat a(2, vec(2));
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 0;
    a = pow(a, n);
    cout << a[1][0] << endl;
}

int main(){
    cin >> n;
    solve();
} 