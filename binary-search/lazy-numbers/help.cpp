#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n, k;
    cin >> n >> k;
    int len = 0;
    {
      auto tmp = n;
      while (tmp > 0) {
        len += 1;
        tmp /= k;
      }
    }
    auto lim = (n + 1) / k;
    vector<long long> d;
    auto Get = [&](long long x) {
      d.clear();
      while (x > 0) {
        d.push_back(x % k);
        x /= k;
      }
      long long L = 1;
      long long R = d.back();
      long long ret = 0;
      for (int i = 0; i < len; i++) {
        ret += max(0LL, min(R - (i < (int) d.size() - 1 ? 0 : 1), n) - L + 1);
        if (i < len - 1) {
          L = L * k;
          if (R > lim) {
            R = n + 1;
          } else {
            R = R * k + (i + 1 < (int) d.size() ? d[(int) d.size() - i - 2] : 0);
          }
        }
      }
      return ret + 1;
    };
    long long L = 1;
    long long R = min(k, n + 1);
    long long ans = 0;
    for (int p = 1; p <= len; p++) {
      long long from;
      {
        long long low = L;
        long long high = R;
        while (low < high) {
          auto mid = (low + high) >> 1;
          if (Get(mid) < mid) {
            low = mid + 1;
          } else {
            high = mid;
          }
        }
        from = low;
      }
      long long to;
      {
        long long low = L - 1;
        long long high = R - 1;
        while (low < high) {
          auto mid = (low + high + 1) >> 1;
          if (Get(mid) > mid) {
            high = mid - 1;
          } else {
            low = mid;
          }
        }
        to = low;
      }
      if (from <= to) {
        ans += to - from + 1;
      }
      if (p < len) {
        L = L * k;
        if (R > lim) {
          R = n + 1;
        } else {
          R = R * k;
        }
      }
    }
    cout << ans << '\n';
  }
}
