# 바이러스
### 7575
***
- KMP
	+ KMP 알고리즘을 이용하여 프로그램1의 부분 수열중 길이가 K인 수열이 다른 프로그램에도 존재하는지 확인한다.
	+ 시간복잡도 O((N + M)*(M - K + 1))
		* 프로그램1의 길이가 K인 부분 수열은 M - K + 1개
		* KMP 알고리즘 O(N + M);
- 실패원인
	+ K와 프로그램의 길이가 같은 경우를 생각하지 못함.
***
[문제](https://www.acmicpc.net/problem/7575)
	
***
### KMP
***
	vector<int> getPi(string str){
		int size = str.size();
		vector<int> pi(size, 0);
	
		int begin = 1, matched = 0;
		while(begin + matched < size){
			if(str[begin + matched] == str[matched]){
				matched++;	
				pi[begin + matched - 1] = matched;
			}else{	
				if(matched == 0) begin++;
				else{
					begin += matched - pi[matched - 1];	
					matched = pi[matched - 1];
				}
			}
		}
		return pi;
	}

	int kmp(string str1, string st2){
		int n = str1.size(), m = str2.size();
		vector<int> pi = getPi(str1);
	
		int begin = 0, matched = 0, res = 0;
		while(begin + m <= n){
			if(matched < m && str1[begin + matched] == str2[matched]){
				matched++;
				if(matched == m) res++;
			}else{
				if(matched == 0) begin++;
				else{
					begin = begin + matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		return res;
	}
