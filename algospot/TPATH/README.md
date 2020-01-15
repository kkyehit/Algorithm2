# 여행 경로 정하기
### TPATH
***
1. src.cpp
	- 크루스칼 알고리즘과 이분탐색으로 시도하였다.
	- 이분 탐색을 수행할 때 어떤 값 이상으로 경로를 완성 할 수 있는지 탐색한다.
	- 오답.
		+ 작성한 방법으로 알맞은 답을 찾기 힘들다.
			* mid값 이상이고 경로가 존재하면 left값을 mid로 변경한다.
			* left 값을 변경 한 후 또다시 경로가 존재하면 left와 mid 사이의 값은 탐색하지 않는다.
			* 하지만 left와 mid 사이에 차이를 최소로 하는 값이 존재할 수 있다.
	
1. src2.cpp
	- 크루스칼 알고리즘으로 해결한다.
	- 탐색을 수행할 때 어떤 값 이상으로 경로를 완성 할 수 있는지 탐색한다.
		+ src.cpp는 0 ~ 1000 사이의 값에서 이분탐색하고 
		src2.cpp는 어떤 간선이 0 에서 V - 1 까지
		완성 시킬수 있고 차이를 최소로 만드는지 탐색한다.
	- #650526
	
***
[문제](https://algospot.com/judge/problem/read/TPATH)
			 