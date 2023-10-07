#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> p5(9);
  p5[0] = 1;

  for (int i = 0; i < 8; i++) {
    p5[i + 1] = p5[i] * 5;
  }

  int n = p5[8];
  vector<array<int, 4>> g(n);
  vector<int> dist(n, -1);

  for (int from = 0; from < n; from++) {
    array<int, 8> goal;
    int tmp = from;
    for (int i = 0; i < 8; i++) {
      goal[i] = tmp % 5;
      tmp /= 5;
    }
    bool win = true;
    for (int i = 0; i < 8; i++) {
      if (goal[i] == 4) continue;
      if (i % 4 != goal[i]) {
        win = false;
        break;
      }
    }
    if (win) {
      dist[from] = 0;
      continue;
    }
    array<int, 8> new_goal;
    for (int op = 0; op < 4; op++) {
      fill(new_goal.begin(), new_goal.end(), 4);
      bool fail = false;
      for (int i = 0; i < 8; i++) {
        if (goal[i] == 4) continue;
        int new_i = i;
        if (op == 0 && new_i % 4 == 1) new_i -= 1;
        if (op == 1 && new_i % 4 == 2) new_i += 1;
        if (op == 2 && new_i % 2 == 1) new_i ^= 2;
        if (op == 3 && new_i >= 4) new_i ^= 2;
        if (new_goal[new_i] == 4) {
          new_goal[new_i] = goal[i];
        } else {
          if (new_goal[new_i] != goal[i]) {
            fail = true;
            break;
          }
        }
      }
      if (fail) {
        g[from][op] = -1;
      } else {
        int to = 0;
        for (int i = 7; i >= 0; i--) {
          to = to * 5 + new_goal[i];
        }
        g[from][op] = to;
      }
    }
  }
  vector<vector<int>> gr(n);
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) {
      if (j != -1) {
        gr[j].push_back(i);
      }
    }
  }
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (dist[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    for (int to : gr[que[b]]) {
      if (dist[to] == -1) {
        dist[to] = dist[que[b]] + 1;
        que.push_back(to);
      }
    }
  }

  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    array<int, 8> goal;
    fill(goal.begin(), goal.end(), 4);
    bool fail = false;
    for (int bit = 0; bit < 30; bit++) {
      int x = (a >> bit) & 1;
      int y = (b >> bit) & 1;
      int z = (m >> bit) & 1;
      int gx = (c >> bit) & 1;
      int gy = (d >> bit) & 1;
      int i = x + 2 * y + 4 * z;
      int j = gx + 2 * gy;
      if (goal[i] == 4) {
        goal[i] = j;
      } else {
        if (goal[i] != j) {
          fail = true;
          break;
        }
      }
    }
    if (fail) {
      cout << -1 << '\n';
      continue;
    }
    int to = 0;
    for (int i = 7; i >= 0; i--) {
      to = to * 5 + goal[i];
    }
    cout << dist[to] << '\n';
  }
  return 0;
}
