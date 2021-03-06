# 하노이의 네 탑
### HANOI4
***
1. 첫번 째 시도 : src.cpp
	+ BFS를 이용하여 모든 경우 탐색한다.
	+ 현재 상태에서 움직일 수 있는 원반을 모두 옮겨 탐색한다.
	+ 현재 상태와 단계를 map을 이용하여 관리한다.
	+ 만약 map에 모든 원반이 오른쪽으로 이동한 상태와 단계가 저장되면 반복을 종료하고 출력한다.
	+ 실패 이유 : 공간을 너무 낭비하였다.
		- RTE (SIGKILL: program was forcefully killed, probably memory limit exceeded)	
2. 두번 째 시도 : src2.cpp
	+ BFS를 이용하여 양방향 탐색을 구현한다. 
	+ 상태를 관리하기 위해 배열을 사용하면 공간이 너무 많이 사용되므로 비트마스크를 이용하여 상태를 나타낸다.
	+ 각 원반이 위치한 고리를 비트마스크를 이용하여 표현한다.
	+ 각 고리는 00, 01, 10, 11 표현 가능하고 따라서 2 * N 의 비트마스크 공간이 필요하다.
	+ 상태에 대한 탐색 횟수를 저장하는 배열의 크기는 4 * ( 2 ^ (2 * N) ) 비트이다.
	+ 시작점에서 시작한 탐색 횟수는 양수, 끝에서 부터 탐색한 횟수는 음수로 저장한다.
	+ 중간에서 만난 경우 두 탐색 횟수의 절댓값을 더한 후 출력한다.
	+ #647897
 ***
[문제](https://algospot.com/judge/problem/read/HANOI4)
			 
