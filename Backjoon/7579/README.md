# 앱
### 7579
***
- dp
	- cache[index][cost] = index까지 만들 수 있는 cost에 대한 최대 memory를 저장한다.
		+ cache[i][c + cost[i]] = max(cache[i - 1][cost[i]] , cache[i - 1][c] + memory[i]);
	- 구현
		1. i - 1번째 까지 완성한 cache를 i번째 cache에 복사한다.
			- cache[i][j] = cache[i - 1][j];
		2. i - 1번째 cache중 비용이 -1이 아닌 것을 j 라고 하면 i번쨰 cache는 j + cost[i]에 대한 메모리를 계산할 수 있다.
			- cache[i][j + cost[i]] = max(cache[i][j + cost[i]], cache[i][j + cost[i]] + memory[i]);
		3. 1과 2를 통해 cache[i-1][j]를 cache[i][j]에 복사하고 최대값을 갱신 할 수 있다.
		4. 모든 탐색이 끝나고 m보다 큰 cache[i][j]에 대해 최소 j를 출력한다.
	
- 실패원인
	1. 처음에 부분합을 이용하여 해결하려 했으나 연속 되지 않은 값도 선택 할 수 있다는 것을 간과했다.
	2. dp를 구현할 떄 식을 코드로 구현하면서 cache[i - 1][cost[i]]를 고려하지 못하였다.
***
[문제](https://www.acmicpc.net/problem/7579)
			 
