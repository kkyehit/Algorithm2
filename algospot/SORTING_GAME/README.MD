# Sorting Game
### SORTGAME
***
1. 첫번 째 시도 : src.cpp
	+ BFS를 이용하여 모든 경우 탐색한다.
	+ 현제 상태에서 뒤집을 수 있는 모든 경우를 고려하고 이를 반복한다.
	+ 만약 최초로 정렬이 되었다면 반복문을 나와 결과를 출력한다.
	+ 실패 이유 : 공간을 너무 낭비하였다.
		- RTE (SIGKILL: program was forcefully killed, probably memory limit exceeded)	
2. 두번 째 시도 : src2.cpp
	+ 수열의 값이 아닌 순서로 접근한다.	
	+ 주어진 배열이 정렬 되기 위해서 뒤집는 횟수는 정렬된 배열을 뒤집어서 주어진 배열을 만드는 횟수와 같다.
	+ map 자료구조를 이용하여 정렬된 배열에서 나올 수 있는 수열과 횟수를 미리 계산한다.
	+ 주어진 배열에서 순서를 의미하는 새로운 배열을 만들고 미리 계산한 map을 이용하여 값을 출력한다.
 	+ #647452
 ***
[문제](https://algospot.com/judge/problem/read/SORTGAME)
			 
