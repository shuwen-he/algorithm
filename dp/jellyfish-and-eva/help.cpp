#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int main() {
  const int N = 5010;
  vector<vector<ld>> p(N);
  p[2] = {0.5, 0};

  for (int n = 4; n < N; n += 2) {
    p[n].resize(n);
    ld q = 1 / ld(n);
    for (int i = 1; i < n - 1; i++) {
      p[n][i] = ((i - 1 < n - 2 ? p[n - 2][i - 1] : 0) * (n - 1 - i) + (i >= 2 ? p[n - 2][i - 2] : 0) * (i - 1)) * q;
    }
    p[n][0] = q;
  }

  int tt;
  cin >> tt;

  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
    }
    vector<ld> dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      vector<ld> a;
      for (int j : g[i]) {
        a.push_back(dp[j]);
      }
      int sz = (int) a.size();
      if (sz % 2 == 1) {
        for (int j = 0; j < sz; j++) {
          dp[i] += a[j];
        }
        dp[i] /= sz;
      } else {
        sort(a.rbegin(), a.rend());
        for (int j = 0; j < sz; j++) {
          dp[i] += a[j] * p[sz][j];
        }
      }
    }
    cout << fixed << setprecision(17) << dp[0] << '\n';
  }
}
