#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX_N 300

using namespace std;

int n, m, k1, k2;
vector<int> v1[MAX_N + 1];
vector<int> v2[MAX_N + 1];
bool check[MAX_N + 1];
int selected[MAX_N + 1];

int dfs(int index, vector<int> *v){
	if(index == -1) return true;
	
	for(int i = 0; i < v[index].size(); i++){
		int next = v[index][i];
		if(check[next]) continue;
		check[next] = true;
		
		if(dfs(selected[next], v)){
			selected[next] = index;
			return true;
		} 
	}
	return false;
}

int main(void){
	int a, b, cnt = 0;
	scanf("%d %d %d %d", &n, &m, &k1, &k2);
	for(int i = 0; i < k1; i++){
		scanf("%d %d",&a,&b);
		v1[a].push_back(b);
	}
	memset(selected, -1, sizeof(selected));
	for(int i = 1; i <= n; i++){
		memset(check, 0, sizeof(check));
		if(dfs(i, v1)) cnt++;
	}
	
	for(int i = 0; i < k2; i++){
		scanf("%d %d",&a,&b);
		v2[a].push_back(b);
	}
	
	memset(selected, -1, sizeof(selected));
	for(int i = 1; i <= n; i++){
		memset(check, 0, sizeof(check));
		if(dfs(i, v2)) {
			cnt--;
		}
	}
	printf("%s\n", (0 > cnt)? "네 다음 힐딱이" :"그만 알아보자");
}