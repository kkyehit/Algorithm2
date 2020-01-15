# 근거리 네트워크
### LAN
***
1. src.cpp
	- 크루스칼 알고리즘을 이용하여 해결하였다.
	- 크루스칼 알고리즘을 구현할 때 트리에 추가할 간선이 원을 만들지 않도록 구현하기 위해 그룹을 
	저장하기 위한 구조체 사용한다.
	- 구조체는 각 원소가 해당하는 트리의 루트 번호를 저장하는 배열과 순위를 나타내기 위한 배열을 
	가지고 있다. 순위를 나타내는 배열은 높이가 더 낮은 트리를 더 높은 트리 하위에 추가하기 위해
	사용한다.
	- vector에는 가중치와 두 건물 번호를 저장하여 가중치가 낮은 순으로 정렬한다. 저장할 때 모든
	건물의 조합을 추가하며 이미 연결되어 있다면 가중치를 0으로 하여 추가한다.
	- 크루스칼 알고리즘을 이용하여 가중치가 낮은 요소먼저 이용하여 트리를 만든다. 이 때 group
	구조체를 이용하여 트리의 형태를 유지하도록 한다. 만약 추가가 될 수 있다면 두 도시가 같은 그룹에 
	추가하고 가중치를 모두 더한 값을 추가한다.
	- #650478
	
***
[문제](https://algospot.com/judge/problem/read/LAN)
			 