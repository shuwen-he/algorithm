#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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
//    int k = 1;
    int last_opt = 1;
    for (int j = i; j <= m; j++) {
/*      while (j - k - 1 >= i - 1 && Eval(i, j, k + 1) <= Eval(i, j, k)) {
        k += 1;
      }
      dp[i][j] = Eval(i, j, k);*/
      ld cur = 1e9;
      int opt = -1;
      for (int kk = max(1, last_opt - 60); j - kk >= i - 1; kk++) {
        auto now = Eval(i, j, kk);
        if (now < cur) cur = now, opt = kk;
        if (now > 1.01 * cur) break;
      }
      dp[i][j] = cur;
      last_opt = opt;
/*      ld res = 1e9;
      for (int kk = 1; j - kk >= i - 1; kk++) res = min(res, Eval(i, j, kk));
      if (abs(res - dp[i][j]) > 1e-9) debug("hi", i, j, dp[i][j], res);
      dp[i][j] = res;*/
    }
  }
  cout << fixed << setprecision(17) << 2 * dp[n][m] + n << '\n';
  debug(clock());
  return 0;
}
