#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream fin("power.in");
	ofstream fout("power.out");

	int n;
	fin>>n;
	for(int i = 30; i > 0; i--){
		int power = 1<<i;// 
		if(n >= power){
			fout<<power<<'\n';
			n -= power;
		}
	}
}
