#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>

using namespace std;
struct node{
	int v;
	int y;
	int h;
};

int main(){
	ifstream fin("expr.in");
	ofstream fout("expr.out");

	char s[20];
	fin>>s;
	int l = strlen(s);
	s[l] = ')';
	stack<char> q;
	q.push('(');
	stack<node> n;

	for(int i = 0; i <= l; i++){ // 0&(1|0)|(1|1|1&0)
		if(s[i] == '0' || s[i] == '1'){
			node temp;
			temp.v = s[i] - '0';
			temp.y = 0;
			temp.h = 0;
			n.push(temp);
		}else if(s[i] == '('){
			q.push(s[i]);
		}else{
			bool fff = false;
			if(s[i] == ')'){
				if(q.top() == '('){
					q.pop();
				}else if(!n.empty() && !q.empty()){
					while(q.top() == '&' || q.top() == '|'){
						char z = q.top();
						q.pop();
						node a = n.top();
						n.pop();
						node b = n.top();
						n.pop();
						node temp;
						temp.y = b.y;
						temp.h = b.h;
						if(z == '&'){
							if(b.v == 0){
								temp.y++;
							}else{
								temp.y += a.y;
								temp.h += b.h;
							}
							temp.v = b.v & a.v;
						}
						if(z == '|'){
							if(b.v == 1){
								temp.h++;
							}else{
								temp.y += a.y;
								temp.h += b.h;
							}
							temp.v = b.v | a.v;
						}
						n.push(temp);
					}
					q.pop();
				}
			}

			if(!n.empty() && !q.empty()){
				while((q.top() == '&' && (s[i] == '&' || s[i] == '|')) || (q.top() == '|' && s[i] == '|')){
					char z = q.top();
					q.pop();
					node a = n.top();
					n.pop();
					node b = n.top();
					n.pop();
					node temp;
					temp.y = b.y;
					temp.h = b.h;
					if(z == '&'){
						if(b.v == 0){
							temp.y++;
						}else{
							temp.y += a.y;
							temp.h += a.h;
						}
						temp.v = b.v & a.v;
					}

					if(z == '|'){
						if(b.v == 1){
							temp.h++;
						}else{
							temp.y += a.y;
							temp.h += a.h;
						}
						temp.v = b.v | a.v;
					}
					n.push(temp);
				}
			}

			if(fff == true){ // & | )
				q.push(s[i]);
			}
		}
	}
	fout<<n.top().v<<'\n';
	fout<<n.top().y<<' '<<n.top().h<<'\n';
}
