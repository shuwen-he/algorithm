#include<bits/stdc++.h>

using namespace std;

int main(){
	ifstream fin("pow.in");
	ofstream fout("pow.out");

	int a,b;
	fin>>a>>b;
	int x = 1;
	for(int i = 0;i < b;i++){
		x*=a;
		if(x > 1e9){
			fout<<-1<<endl;
			return 0;
		}
	}
	cout<<a<<"的"<<b<<"次方是"<<x<<endl;
	return 0;

}
