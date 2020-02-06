#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 100000
using namespace std;

typedef long long int int64;

int N;
int64 histogram[MAX_N + 1];
int64 divisionAndConquest(int left, int right){
	if(left == right) return histogram[left];
	if(left < 0 || N <= right) return 0;
	if(right < left) return 0;
	
	int mid = (left + right) / 2;
	int64 x = 1, y = histogram[mid];
	int64 res = divisionAndConquest(left, mid - 1);
	res = max(res, divisionAndConquest(mid + 1, right));
	res = max(res, x * y);
	
	int L = mid - 1, R = mid + 1;
	while(left <= L && R <= right){
		if(histogram[L] < histogram[R]){
			y = min(y, histogram[R++]);
		}else{
			y = min(y, histogram[L--]);
		}
		x++;
		res = max(res, x * y);
	}
	
	while(left <= L){
		y = min(y, histogram[L--]);
		x++;
		res = max(res, x * y);
	}
	
	while( R <= right){
		y = min(y, histogram[R++]);
		x++;
		res = max(res, x * y);
	}
	return res;
}

int main(void){
		scanf("%d",&N);
		for(int i = 0; i < N; i++) scanf("%lld", &histogram[i]);
		printf("%lld\n",divisionAndConquest(0, N - 1));
}