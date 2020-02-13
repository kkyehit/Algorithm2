# 섬의 개수
### 4963
***
- BFS
	+ 이어진 섬을 BFS로 찾으면서 새로운 섬을 찾으면 결과에 값을 추가한다.
	+ isVisited[i][j] = (i,j)가 이미 다른 섬에 포함 되어 있는지 여부
	+ 풀이
		1. 입력을 받을 때 1이 위치를 배열에 저장한다. (queue를 이용하여 저장하였다)
		2. 배열의 처음부터 1의 위치 하나를 queue에 저장한다.
			+ isVisited[][]값이 true라면 저장하지 않고 (이미 다른 섬에 포함되는 점이다.) isVisited[][]값이 false인 다른 점을 queue에 저장한다. 
			+ 하나를 저장하면서 결과값을 1증가시킨다. (새로운 섬을 의미)
		3. queue의 top에 존재하는 점을 빼서 해당 점으로 부터 상, 하, 좌, 우 및 대각선중 isVisited[][]값이 false이면서 섬인 점을 queue에 추가한다.
			+ queue에 추가하면서 isVisited[][]를 true로 변경한다.
		4. queue가 빌 때 까지 (3)를 반복한다.
		5. 배열의 모든 점을 탐색하면서 (2) ~(4)룰 반복한다.
		
- 실패원인
	+ 메모리 초과
		- isVisited[][]값을 queue에 추가 할 때가 아닌 queue에서 pop할 때 갱신하였는데 이는 중복된 값을 계속해서 queue에 넣을 수 있어 계속 반복되고 메모리 초과가 발생할 수 있다.

***
[문제](https://www.acmicpc.net/problem/4963)
			 