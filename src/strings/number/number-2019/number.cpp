#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");

	char s[8];
	fin>>s;
	int l = strlen(s);
	int count = 0;
	for(int i = 0; i < l; i++){
		if(s[i] == '1'){
			count++;
		}
	}
	fout<<count<<'\n';
}
