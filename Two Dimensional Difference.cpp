#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e3 + 10;

int a[maxn][maxn];
int d[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            d[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
        }
    }
    while (q--) {
        int x, y, xx, yy, c;
        cin >> x >> y >> xx >> yy >> c;  // (x, y) ~ (xx, yy) add c
        d[x][y] += c;
        d[x][yy + 1] -= c;
        d[xx + 1][y] -= c;
        d[xx + 1][yy + 1] += c;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            cout << d[i][j] << " \n"[j == m];
        }
    }
    return 0;
}
