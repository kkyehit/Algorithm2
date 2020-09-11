#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAX_X 1000000000
#define MAX_N 200000

using namespace std;

int n, c;
int h[MAX_N];

int main(void){
	scanf("%d %d", &n, &c);
	for(int i =0 ; i < n; i++) scanf("%d",&h[i]);
	sort(h, h + n);
	
	//가장 인접한 공유기 사이 거리  == mid
	int left = 0, right = MAX_X, mid, d;
	while(left < right ){
		mid = (left + right ) >> 1;
		
		int pivot = h[0], cnt = 1;
		int dis = 2123456789;
		for(int i = 0; i < n; i++){
			if(pivot + mid <= h[i]){
				dis = min(dis, h[i] - pivot);
				cnt++;
				pivot = h[i];
			}
		}
		if(c <= cnt) left = mid + 1;
		else right = mid;
	}
	printf("%d\n",left - 1);
}