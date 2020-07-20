## 트리의 가중치
***
- 깊이 우선 탐색(DFS)
	* dfs()는 서브 트리의 최하위 노드 까지의 가중치 합을 반환한다.
 	* dfs()의 결과에 해당 서브 트리 까지의 가중치를 곱하면 현재 노드에서 해당 서브 트리의 최하위 노드 까지의 가중치 합을 구할 수 있다.
	* 각 서브트리 까지의 가중치 합을 곱하면 트리의 가중치를 구할 수 있다.
	

  	    1
	    a  b
	   2     3
  	c        d
 	4          5


	4 -> 1 리턴 total = 0
	2 -> c + 1 리턴 total = c
	5 -> 1 리턴 total = c
	3 -> d + 1리턴 total = c + d

	1 -> total = c + d + ( ac + a ) + ( db + b )
   		==> total = a + b + c + d + ac + db

			
			  
  
 [문제](https://www.acmicpc.net/problem/1289)
  