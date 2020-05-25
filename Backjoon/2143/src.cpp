#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 1000

using namespace std;

typedef long long int int64;

int64 t, n, m;
int64 a[MAX_N], b[MAX_N];
int main(void){
	scanf("%lld", &t);
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	scanf("%lld", &m);
	for(int i = 0; i < m; i++) scanf("%lld", &b[i]);
	
	vector<int64> va;
	vector<int64> vb;
	
	for(int i = 0; i < n; i++) {
		int64 sum = 0;
		for(int j = i; j < n; j++){
			sum += a[j];
			va.push_back(sum);
		}
	}
	
	for(int i = 0; i < m; i++) {
		int64 sum = 0;
		for(int j = i; j < m; j++){
			sum += b[j];
			vb.push_back(sum);
		}
	}
	
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	
	int64 left = 0, right = vb.size() -1;
	int64 res = 0;
	while(left < va.size() && right >= 0){
		int64 sum = va[left] + vb[right];
		
		if(sum < t) left++;
		else if(t == sum){
			int64 A = 1, B = 1;

			while (left < va.size() - 1 && va[left] == va[left + 1]) {
				++left, ++A;
			}
			while (right >= 1 && vb[right] == vb[right - 1]) {
				--right, ++B;
			}
			res += A * B;
			++left;
		}else right--;
	}
	printf("%lld\n",res);
}