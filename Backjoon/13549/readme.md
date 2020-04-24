## 숨바꼮질 3
* 경로에 따라 가중치가 다르기 때문에 일반적인 BFS와 다르게 풀었다.
* `queue<pair<int, tin> >` 대신 `priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >` 를 사용하여 적은 가중치를 가진 경로먼저 탐색하도록 구현하였다.

[문제](https://www.acmicpc.net/problem/13549)
