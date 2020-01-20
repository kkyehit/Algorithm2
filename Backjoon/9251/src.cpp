#include <stdio.h>
#include <iostream>
#include <cstring>

#define MAX_LENGTH 1000

using namespace std;

int cache[MAX_LENGTH + 1][MAX_LENGTH + 1];
string str1, str2;
int n, m;

int search(int a, int b){
	if(a >= n || b >= m ) return 0;
	
	int &ret = cache[a][b];
	if(ret != -1) return ret;
	
	if(str1[a] == str2[b]) return ret = 1 + search(a + 1, b + 1);
	else return ret = max(search(a + 1, b), search(a, b + 1));
}

int main(void){
	cin>>str1;
	cin>>str2;
	memset(cache, -1, sizeof(cache));
	n = str1.size(); m = str2.size();
	cout<<search(0, 0)<<endl;
}