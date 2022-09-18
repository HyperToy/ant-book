#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define mod 1000000007

int n, m;
vector<vector<int>> color;

int rec(int i, int j, vector<vector<bool>> used) {
    if (j == m) {
        return rec(i+1, 0, used);
    }

    if (i == n) {
        return 1;
    }

    if (used[i][j] || color[i][j]) {
        return rec(i, j+1, used);
    }

    int res = 0;
    used[i][j] = true;

    if (j+1 < m && !used[i][j+1] && !color[i][j+1]) {
        used[i][j+1] = true;
        res += rec(i, j+1, used);
        used[i][j+1] = false;
    }

    if (i+1 < n && !used[i+1][j] && !color[i+1][j]) {
        used[i+1][j] = true;
        res += rec(i, j+1, used);
        used[i+1][j] = false;
    }
    
    used[i][j] = false;
    return res % mod;
}


void solve() {
    vector used(n, vector<bool>(m, false));
    cout << rec(0, 0, used) << endl;
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