# 도미노 예측
### 17943
***
- 부분 합( prefix sum )응용
	- 부분 합 알고리즘에서 덧셈 대신 xor연산을 사용한다.
		+ record[x]를 x번째 도미노 숫자와 x + 1번째 도미노 숫자를 xor한 결과라고 하고 xorToN[x]를 record[1]^record[2]^...^record[x]라고 하자 그러면 xorToN[x]는 첫번째 도미노 숫자와 x + 1번째 도미노 숫자를 xor한 결과가 된다.
		+ 도미노 숫자를 A(i) 라고 하면 xorToN[x] = A(1) ^ A(x + 1) 이므로 x번째 도미노의 수와 y번째 도미노의 수를 XOR한 값은 xorToN[x - 1] ^ xorToN[y - 1] = A(1) ^ A(x) ^ A(1) ^ A(y) = A(x) ^ A(y)가 된다.
		+ x번째 도미노의 수가 d일 때, y번째 도미노의 수는 A(x)가 d라는 의미이다. 따라서 xorToN[x - 1] ^ xorToN[y - 1] = A(x) ^ A(y) = d ^ A(y)가 되고 여기에 d를 xor연산하게 되면 y번째 도미노의 수를 구할 수 있다. 즉 xorToN[x - 1] ^ xorToN[y - 1] ^ d =  A(y)

- 제6회 한양대학교 프로그래밍 경시대회 Advanced Division K번

***
[문제](https://www.acmicpc.net/problem/17943)
			 
