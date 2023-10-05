#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream fin("pow.in");
	ofstream fout("pow.out");

	int a,b;
	fin>>a>>b;
	
	int result = 1;
	for(int i = 0; i < b; i++){
		result *= a;
		if(result > 1e9){
			fout<<-1<<'\n';
		}
	}
	fout<<result<<'\n';
}
