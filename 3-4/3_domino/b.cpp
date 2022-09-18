#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define mod 1000000007

int n, m;
vector<vector<int>> color;

void solve() {
    vector<int> crt(1 << m, 0);
    vector<int> nxt(1 << m, 0);
    crt[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            rep(used, 1 << m) {
                if ((used >> j & 1) || color[i][j]) {
                    // (i,j) にブロックを置く必要がない
                    nxt[used] = crt[used & ~(1 << j)];
                } else {
                    // 2通りの向きを試す
                    int res = 0;
                    if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]) {
                        res += crt[used | 1 << (j + 1)];
                    }
                    if (i + 1 < n && !color[i + 1][j]) {
                        res += crt[used | 1 << j];
                    }
                    nxt[used] = res % mod;
                }
            }
            swap(crt, nxt);
        }
    }
    cout << crt[0] << endl;
}

int main(){
    cin >> n >> m;
    color.resize(n, vector<int>(m, 0));
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,m) {
            if (s[j] == '#') {
                color[i][j] = 1;
            }
        }
    }
    solve();
} 