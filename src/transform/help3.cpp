/* 
 * Problem: NOI2009 transform
 * Author: Shuwen He
 * Time: 2009.9.17 15:29
 * State: Solved
 * Memo: 二分图匹配
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN=20001,MAXM=MAXN*4;

struct edge{
	edge *next;
	int t;
}*V[MAXN],ES[MAXM];

int N,EC;
int S[MAXN][2],mat[MAXN];
bool vis[MAXN];

inline void addedge(int a,int b){
	ES[++EC].next = V[a]; V[a] = ES + EC;
	V[a]->t = b;
}

void init(){
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	scanf("%d",&N);
	int i,d,t1,t2;
	for (i=1;i<=N;i++){
		scanf("%d",&d);
		t1 = i + d;
		if (t1>N) t1-=N;
		t2 = i - d;
		if (t2<1) t2+=N;
		if (t1 < t2)
			S[i][0] = t1,S[i][1] = t2;
		else
			S[i][0] = t2,S[i][1] = t1;
		addedge(i,S[i][1]+=N);
		addedge(i,S[i][0]+=N);
	}
}

bool augment(int i){
	for (edge *e=V[i];e;e=e->next){
		int j = e->t;
		if (!vis[j]){
			vis[j] = true;
			if (!mat[j] || augment(mat[j])){
				mat[j] = i;
				mat[i] = j;
				return true;
			}
		}
	}
	return false;
}

void solve(){
	int cnt = 0;
	for (int i=N;i>=1;i--){
		memset(vis,0,sizeof(vis));
		if (augment(i))
			cnt++;
	}
	if (cnt < N){
		printf("No Answer\n");
		exit(0);
	}
}

void print(){
	int i;
	for (i=1;i<N;i++)
		printf("%d ",mat[i] - N - 1);
	printf("%d\n",mat[i] - N - 1);
}

int main(){
	init();
	solve();
	print();
	return 0;
}
