#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ld> inv(m + 1);

  for (int i = 1; i <= m; i++) {
    inv[i] = 1 / ld(i);
  }

  vector<vector<ld>> dp(n + 1, vector<ld>(m + 1, 1e9));
  dp[0][0] = 0;

  auto Eval = [&](int i, int j, int k) {
    return dp[i - 1][j - k] + (j - k) * inv[k];
  };

  for (int i = 1; i <= n; i++) {
    int last_opt = 1;
    for (int j = i; j <= m; j++) {
      ld cur = 1e9;
      int opt = -1;
      for (int kk = max(1, last_opt - 60); j - kk >= i - 1; kk++) {
        auto now = Eval(i, j, kk);
        if (now < cur) cur = now, opt = kk;
        if (now > 1.01 * cur) break;
      }
      dp[i][j] = cur;
      last_opt = opt;
    }
  }

  cout << fixed << setprecision(17) << 2 * dp[n][m] + n << '\n';

  return 0;
}
