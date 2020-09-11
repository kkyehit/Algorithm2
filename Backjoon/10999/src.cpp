#include <stdio.h>
#include <vector>
#include <iostream>

#define MAX_N 1000000
#define MAX_M 10000

using namespace std;

long long int n, m, k;
long long int s[MAX_N + 1];
long long int v[MAX_N * 4];
long long int lazy[MAX_N * 4];

long long int init(long long int node, long long int left,long long int right){
	if(left == right) return v[node] = s[left];
	
	v[node] = init(node*2, left, ((left + right)>>1) ) + init(node*2+1, ((left + right)>>1)+1, right);
	
	return v[node];
}

void laze_update(long long int node, long long int left, long long int right){
	if(lazy[node] == 0) return;
	v[node] += ( lazy[node] * ( right - left + 1) );
	if(left != right){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node]; 
	}
	lazy[node] = 0;
}

long long int update(long long int node, long long int left, long long int right, long long int val, long long int l, long long int r){
	laze_update(node, left, right);
	if(right < l || r < left) return v[node];
	
	if(l <= left && right <= r ) {
		lazy[node] += val;
		laze_update(node, left, right);
		return v[node];
	}
	
	return v[node] = update(node*2, left, ((left + right)>>1), val, l, r) + update(node*2+1, ((left + right)>>1)+1, right, val, l, r);
	
}

long long int getVal(long long int node, long long int left, long long int right, long long int l, long long int r){
	laze_update(node, left, right);
	
	if(l <= left && right <= r ) return v[node];
	
	if(right < l || r < left ) return 0;
	
	long long int res = getVal(node*2, left, ((left + right)>>1), l, r) + getVal(node*2+1, ((left + right)>>1)+1, right, l, r);
	return res;
}

int main(void){
	scanf("%lld %lld %lld", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);
		update(1,1,n,s[i],i,i);
	}
	
	long long int a, b, c, d;
	for(int i = 0; i < m + k; i++){
		scanf("%lld", &a);
		if( a == 1){
			scanf("%lld %lld %lld", &b, &c ,&d);
			update(1,1,n,d,b,c);
		}else{
			scanf("%lld %lld", &b, &c);
			printf("%lld\n",getVal(1,1,n,b,c));
		}
	}
	
}