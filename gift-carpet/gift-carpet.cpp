#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n,m; // table 表格 n * m
	cin>>n>>m; // the size of the carpet 地摊
	char s[n][m];

	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < m; i++)
			cin>>s[i][j];

	string name = "vika";
	long long ind = 0,count = 0;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			char curr = s[j][i];
			if(curr == name[ind]){
				ind++;
				count++;
				break;
			}
		}
		if(count == 4)
			break;
	}
	if(count == 4)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long t = 1;
	cin>>t;
	while(t--)
		solve();
}
