## 미확인 도착지
* 'Dijkstra'알고리즘을 이용하여 시작점 부터 각 점까지 최단 비용을 구한다.
	- 이 때 **[h, g]**를 지나는 간선을 처리하기 위해
	``` c++
	if((preLocation[next] != now)&&(Cost[next] == -1 || nextCost <= Cost[next])){
				if((now == g && next == h)||(now == h && next == g)){
					pq.push(make_pair(nextCost - 1, make_pair(next, now)));
					Cost[next] = nextCost - 1;
					preLocation[next] = now;
				}
				else{
					pq.push(make_pair(nextCost, make_pair(next, now)));
					Cost[next] = nextCost;
					preLocation[next] = now;
				}
			}
	```
	- 위와 같이 최소 비용이  **[h, g]**를 지난다면 **nextCost**에 **-1** 을 더해 같은 비용의 다른 간선을 고려하지 않도록 한다.
	- 같은 간선을 중복 추가하지 않기 위해 `preLocation[next] != now`사용
* Dijkstra를 구한 뒤 최소 경로를 거슬러 올라가면서 **[h, g]**를 지나는지 확인한다.

[문제](https://www.acmicpc.net/problem/9370)