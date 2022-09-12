#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
#define PR(x) cerr << #x << " = " << x << endl

int n, m; // 乗車券の枚数、都市の数
int a, b; // 開始・終了の都市
vector<int> t; // 各乗車券に記載された馬の頭数
vector<vector<int>> dist; // グラフの距離行列 (辺がなければ -1)

// dp[S][v] := 残っている乗車券がS、現在位置v の状態に至るまでの最小コスト
vector<vector<double>> dp;

void solve() {
    a--; b--;
    dp.resize(1 << n, vector<double>(m, INF));
    dp[(1 << n) - 1][a] = 0;

    double res = INF;
    for (int S = (1 << n) - 1; S >= 0; S--) {
        chmin(res, dp[S][b]);
        rep(v,m) rep(i,n) {
            if (S >> i & 1) rep(u,m) {
                if (dist[v][u] < INF) {
                    chmin(dp[S & ~(1 << i)][u], dp[S][v] + (double)dist[v][u] / t[i]);
                }
            }
        }
    }

    if (res < INF) cout << fixed << setprecision(6) << res << endl;
    else cout << "Impossible" << endl;
}

int main(){
    cin >> n >> m >> a >> b;
    t.resize(n);
    dist.resize(m, vector<int>(m));
    rep(i,n) cin >> t[i];
    rep(i,m) rep(j,m) {
        cin >> dist[i][j];
        if (dist[i][j] == -1) {
            dist[i][j] = INF;
        }
    }
    solve();
} 