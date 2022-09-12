#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
#define PR(x) cerr << #x << " = " << x << endl

int n;
vector<vector<int>> dist; // [n][n]

vector<vector<int>> dp; // [1<<n][n]

// すでに訪れた頂点集合S, 現在位置v
int rec(int S, int v) {
    if (dp[S][v] != -1) {
        // 探索済みならそのまま返す
        return dp[S][v];
    }
    if (S == (1 << n) - 1 && v == 0) {
        // 終端条件
        // すべての頂点を訪れて戻った
        return dp[S][v] = 0;
    }

    int res = INF;
    rep(u,n) {
        if (!(S >> u & 1)) {
            // 次の頂点u に移動する
            res = min(res, rec(S | 1 << u, u) + dist[v][u]);
        }
    }
    return dp[S][v] = res;
}

void solve() {
    dp = vector(1<<n, vector<int>(n, -1));
    cout << rec(0, 0) << endl;
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