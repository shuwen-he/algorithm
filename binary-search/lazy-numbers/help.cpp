#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t; // 测试用例数量
  cin >> t;

  while (t--) {
    long long n, k;
    cin >> n >> k;
    int len = 0; // 以k为底的n的最大位数

    long long tmp = n;
    while (tmp > 0) {
	    len += 1;
	    tmp /= k;
    }

    long long lim = (n + 1) / k;
    vector<long long> d;

    auto Get = [&](long long x) { // 计算表示数字x的位
      d.clear();
      while (x > 0) {
        d.push_back(x % k);
        x /= k;
      }
      long long l = 1;
      long long r = d.back();
      long long ret = 0;
      for (int i = 0; i < len; i++) {
        ret += max(0LL, min(r - (i < (int) d.size() - 1 ? 0 : 1), n) - l + 1);
        if (i < len - 1) {
          l = l * k;
          if (r > lim) {
            r = n + 1;
          } else {
            r = r * k + (i + 1 < (int) d.size() ? d[(int) d.size() - i - 2] : 0);
          }
        }
      }
      return ret + 1;
    };

    long long l = 1; // 当前搜索范围的左边界
    long long r = min(k, n + 1); // 当前搜索范围的左边界
    long long ans = 0;
    for (int p = 1; p <= len; p++) { // 循环处理每个位数p从1到len
	    long long from;
	    
	    long long low = l;
	    long long high = r;
	    while (low < high) {
		    auto mid = (low + high) >> 1;
		    if (Get(mid) < mid) {
			    low = mid + 1;
		    } else {
			    high = mid;
		    }
	    }
	    from = low;

	    long long to;
	    long long low2 = l - 1;
	    long long high2 = r - 1;
	    while (low2 < high2) {
		    auto mid = (low2 + high2 + 1) >> 1;
		    if (Get(mid) > mid) {
			    high2 = mid - 1;
		    } else {
			    low2 = mid;
		    }
	    }
	    to = low2;
	    
	    if (from <= to) {
		    ans += to - from + 1;
	    }
	    if (p < len) {
		    l = l * k;
		    if (r > lim) {
			    r = n + 1;
		    } else {
			    r = r * k;
		    }
	    }
    }
    cout << ans << '\n';
  }
}
