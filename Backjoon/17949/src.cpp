#include <iostream>
#include <cstring>
#include <vector>

#define CHAR "char"
#define INT "int"
#define LONG "long_long"

#define CHAR_SIZE 2
#define INT_SIZE 8
#define LONG_SIZE 16

using namespace std;

long long int getNumber(int start, int size, string& str){
	int end = start + size;
	long long int res = 0;
	
	for(int i = start; i < end; i++){
		res *= 16;
		if( '0' <= str[i]&& str[i] <= '9') res += str[i] - '0';
		else res += str[i] - 'a' + 10;
		//printf("res : %lld\n",res);
	}
	return res;
}

int main(void){
	ios::sync_with_stdio(false);
	string number, tmp;
	int n;
	vector<string> v;
	cin>>number;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	
	int tail = 0;
	for(auto s: v){
		if(s.compare(CHAR) == 0){
			printf("%lld ",getNumber(tail, CHAR_SIZE, number));
			tail += CHAR_SIZE;
		}else if(s.compare(INT) == 0){
			printf("%lld ",getNumber(tail, INT_SIZE, number));
			tail += INT_SIZE;
		}else{
			printf("%lld ",getNumber(tail, LONG_SIZE, number));
			tail += LONG_SIZE;
		}
	}
}