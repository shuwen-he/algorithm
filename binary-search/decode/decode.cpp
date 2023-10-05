#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream fin("decode.in");
	ofstream fout("decode.out");

	int k;
	fin>>k;
	int n,d,e;
	for(int i = 0;i < k; i++){
		fin>>n>>d>>e;
		int s = n - e * d + 2;
		int l = 1;
		int r = s - 1;
		int p = -1,q = -1;
		while(l <= r){
			int mid = l + (r - l) / 2;
			if(mid * (s - mid) == n){
				p = mid;
				q = s - mid;
				break;
			}else if(mid * (s - mid) < n){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		if(p != -1 && q != -1 && p <= q){
			fout<<p<<' '<<q<<'\n';
		}else{
			fout<<"NO"<<'\n';
		}
	}
}
