# 흩날리는 시험지 속에서 내 평점이 느껴진거야
### 17951
***
1. 다이나믹 프로그래밍으로 접근하였다.
	- 공간이 너무 많이 필요하다. (10000 * 10000 byte)  
	- A(i,j) = min(SUM(i, k), A( k + 1, j - 1))	
		+ i번째 위치에서 j개의 그룹을 선택할 때의 값은 i번째 위치에서 K번째 값까지 합과
		K + 1번째 위치에서 j - 1개의 그룹을 선택하는 것의 값의 최소값 이다. ( i + 1 <= k <= n - j)
		+ 이 식의 최대값을 반환한다.
	
2. 이진 탐색으로 해결하였다.
	- 최소값으로 선택 할 수 있는 값을 찾는다.
		+ 최소값을 선택 할 수 있다는 것은 이 값과 같거나 큰 그룹이 K개 이상이라는 것과 같다.
	- 최소값으로 선택 할 수 있는 값중 최대값을 출력한다.
***
[문제](https://www.acmicpc.net/problem/17951)	 
