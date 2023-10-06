#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    bool canWin = true;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].first >= arr[0].first and arr[i].second >= arr[0].second)
        {
            canWin = false;
        }
    }

    if (!canWin)
    {
        cout << -1 << nline;
    }
    else
        cout << arr[0].first << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T = 1;
    cin >> T;
    while (T--) 
    {
        solve();
    }
}
