# 수들의 합
### 2003
***
- 투 포인터
	- 배열의 부분 합의 시작점, 끝점을 나타내는 포인터 2개를 사용한다.
	- 만약 현재 부분합의 크기가 주어진 M과 같으면 결과에 1을 추가하고 새로운 요소를 더한다.
	- 만약 다를 경우
	 	1. M보다 작은 경우 
			- end의 요소를 더한다.
		2. M보다 큰 경우
		 	- start의 요소를 뺀다.
	- 배열의 마지막에 0을 추가함으로써 모든 부분합을 탐색할 수 있도록 구현하였다.
***
[문제](https://www.acmicpc.net/problem/2003)
			 