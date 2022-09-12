#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
#define PR(x) cerr << #x << " = " << x << endl

int n;
vector<vector<int>> dist;

vector<vector<int>> dp;

void solve() {
    dp = vector(1 << n, vector<int>(n, INF));
    dp[(1 << n) - 1][0] = 0;
    for (int S = (1 << n) - 1; S >= 0; S--) {
        rep(v,n) {
            rep(u,n) {
                if (!(S >> u & 1)) {
                    dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + dist[v][u]);
                }
            }
        }
    }
    cout << dp[0][0] << endl;
}

int main(){
    cin >> n;
    dist = vector(n, vector<int>(n));
    rep(i,n) rep(j,n) {
        cin >> dist[i][j];
        if (dist[i][j] == -1) {
            dist[i][j] = INF;
        }
    }
    solve();
}