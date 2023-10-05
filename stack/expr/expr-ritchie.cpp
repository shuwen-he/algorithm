#include <bits/stdc++.h>

using namespace std;

struct node {
	int v;
	int y;
	int h;
};    

int main() {
	ifstream fin("expr.in");
   	ofstream fout("expr.out");

    char s[1000002];
	stack<char> q;
	stack<node> n;
	
	fin >> s;
	int l = strlen(s);
	s[l] = ')';
	q.push('(');
	
	for (int i = 0; i <= l; i++) {
		if(s[i]=='(') {
		   q.push(s[i]);    
	    }else if (s[i] == '0' || s[i] == '1') {
		    node temp;
		    temp.v = s[i] -'0';
		    temp.y = 0;
		    temp.h = 0;
		    n.push(temp);
		}else{
			bool fff =false;          
		if(s[i] == ')'){
			fff = true;
   			if (q.top() == '(') {
            			   	
			}
		}       
  	}	 
}
}
