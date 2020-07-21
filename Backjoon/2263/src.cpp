#include<stdio.h>
#include<cstring>

#define MAX_N 100000

using namespace std;

int n;
int inOrder[MAX_N+1], postOrder[MAX_N];

void dfs(int iStart, int iEnd, int pStart, int pEnd){
	if(iEnd < iStart || pEnd < pStart) return;
	
	int root = postOrder[pEnd];
	printf("%d ",root);
	
	//iStart ~ inOrder[root] - 1 	// pStart ~ pStart + inOrder[root] - 1 - iStart 
	dfs(iStart, inOrder[root] - 1, pStart, pStart + inOrder[root] - 1 - iStart );
	//inOrder[root] + 1 ~ iEnd 		// pStart + inOrder[root] - iStart  ~ pEnd - 1
	dfs(inOrder[root] + 1, iEnd, pStart + inOrder[root] - iStart, pEnd - 1);
}

int main(void){
	scanf("%d", &n);
	int a;
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		inOrder[a] = i;
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		postOrder[i] = a;
	}
	dfs(0, n-1, 0, n-1);
}