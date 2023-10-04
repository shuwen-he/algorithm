#include <iostream>

using namespace std;

int max(int a,int b){
	int c;
	if(a > b){
		c = a;
	}else{
		c = b;
	}
	return c;
}

int main(){
	int a,b;
	cout<<"please enter two int number:"<<'\n';
	cin>>a>>b;
	int c = max(a,b);
	cout<<"max num is :"<<c<<'\n';
}
