#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std; 

const int MAXN=20001,MAXM=MAXN*4;
struct edge { 
	edge *next; 
	int t; 
}*V[MAXN],ES[MAXM];

int N,EC,Stack[MAXN]; 
int S[MAXN][2],deg[MAXN],mat[MAXN]; 
bool nuked[MAXN];

inline void addedge(int a,int b) { 
	ES[++EC].next = V[a]; 
	V[a] = ES + EC; 
	V[a]->t = b; 
	ES[++EC].next = V[b]; 
	V[b] = ES + EC; 
	V[b]->t = a; 
	++deg[b]; 
	mat[b] = a; 
}

void init() { 
	freopen("transform.in","r",stdin); 
	freopen("transform.out","w",stdout); 
	scanf("%d",&N); 
	int i,d,t1,t2; 
	for (i=1;i<=N;++i) { 
		scanf("%d",&d); t1 = i + d; 
		if (t1>N) t1-=N; t2 = i - d; 
		if (t2<1) t2+=N; 
		if (t1 < t2) S[i][0] = t1,S[i][1] = t2; 
		else 
		S[i][0] = t2,S[i][1] = t1; addedge(i,S[i][1]+=N); addedge(i,S[i][0]+=N); deg[i] = 2; 
	} 
}

inline void Match(int i,int j) {
	mat[i] = j; 
	mat[j] = i; 
}

void dfsMatch(int i,bool s) { 
	nuked[i] = true; 
	int j; 
	for (edge *e=V[i];e;e=e->next) { 
		j = e->t; 
		if (!nuked[j]) { 
			dfsMatch(j,!s); 
			if (s) Match(i,j); 
			break; 
		} 
	} 
}

void noAnswer() { 
	printf("No Answer\n"); 
	exit(0); 
}

void cut() { 
	int Stop = 0,i,j; 
	for (i=1;i<=N;++i) { 
		if (deg[i+N] == 0) noAnswer(); 
		else if (deg[i+N] == 1) Stack[++Stop] = i+N; 
	} while (Stop) { 
			i = Stack[Stop--]; 
			nuked[i] = true; 
			for (edge *e=V[i];e;e=e->next) { 
				j = e->t; if (!nuked[j]) break; 
			} 
			Match(i,j); 
			i = j; 
			nuked[i] = true; 
			for (edge *e=V[i];e;e=e->next) { 
				j = e->t; 
				if (!nuked[j]) { 
					deg[j]--; 
					if (deg[j] == 0) noAnswer(); 
					else if (deg[j] == 1) Stack[++Stop] = j; 
			        } 
		        } 
	        } 
}

void solve() { 
	cut(); 
	for (int i=1;i<=N;i++) { 
		if (!nuked[i]) { dfsMatch(i,true); 
		} 
	}
}

void print() { 
	int i; 
	for (i=1;i<N;i++)
		printf("%d ",mat[i] - N - 1); 
	printf("%d\n",mat[i] - N - 1); 
}

int main() { 
	init(); 
	solve(); 
	print(); 
	return 0; 
}
