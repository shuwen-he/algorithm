#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }

    if (k > 10) {
      k -= (k - 10) / 2 * 2;
    }

    for (int it = 0; it < k; it++) {
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      if (it % 2 == 0) {
        if (a[0] < b.back()) {
          swap(a[0], b.back());
        }
      } else {
        if (b[0] < a.back()) {
          swap(b[0], a.back());
        }
      }
    }
    cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
  }
  return 0;
}
