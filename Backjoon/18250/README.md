# 철도여행
### 18250
***
- 한 붓 그리기( euler trail )를 이용하여 푼다.
	- euler circuit : 시작 점과 끝 점이 같다.
		+ 두 개의 정점만 홀수개의 간선을 가진다.
	- euler trail : 시작 점과 끝 점에 대한 조건이 없다.
		+ 모든 정점이 짝수개의 간선을 가진다.
	- 풀이과정
		1. 몇 개의 분리된 그래프로 존재하는지 확인한다. (union find)
 		2. 각 그래프 마다 짝수개의 정점과 홀수개의 정점의 수를 찾고 경우의 수를 구한다.
			+ 간선이 존재하지 않는다면 0, 모든 정점에 대하여 짝수개가 존재하면 1,
			홀수개가 존재한다면 ( 간선의 개수 / 2 ) 개의 euler trail을 만들 수 있다.

- 시간 초과
	+ groupRank를 이용하여 더 낮은 Rank를 루트로 선택하도록 구현하였다.
	+ 검색 시 마다 Root를 갱신 하도록 구현하여 해결하였다.
- Good Bye, BOJ 2019! > D
***
[문제](https://www.acmicpc.net/problem/18250)
			 
