# [Gold IV] UDP 스택 - 31719 

[문제 링크](https://www.acmicpc.net/problem/31719) 

### 성능 요약

메모리: 3136 KB, 시간: 44 ms

### 분류

자료 구조, 그리디 알고리즘, 구현, 시뮬레이션, 스택

### 제출 일자

2025년 1월 24일 04:56:20

### 문제 설명

<p>UDP 마을에는 세 개의 신비한 스택이 있다. 이를 차례로 U스택, D스택, P스택이라 하자. 이 스택들은 특별해서 스택의 바닥을 열고 닫을 수 있다. 바닥이 열려 있는 스택에 원소를 삽입하면 그 즉시 바닥 아래로 떨어지며, 바닥이 닫혀 있는 스택의 바닥을 열면 저장되어 있던 원소들이 모두 바닥 아래로 떨어진다. 이때, 스택의 바닥에 가까운 쪽의 원소들이 더 먼저 바닥으로 떨어진다. 초기에는 U스택의 바닥만이 열려 있으며, D스택과 P스택의 바닥은 닫혀 있다.</p>

<p>어느 날, UDP 마을에서 길이가 $N$인 순열 $A$가 발견되었다. 포닉스는 다음 두 연산만을 사용할 수 있다.</p>

<ul>
	<li>순열 $A$의 가장 앞 원소를 세 스택 중 하나에 삽입한 후 순열에서 삭제한다. 단, 이 연산은 순열 $A$가 비어있지 않을 때만 가능하다.</li>
	<li>현재 바닥이 열려 있는 스택을 닫은 후 바닥이 닫혀 있는 스택 중 하나를 골라 연다.</li>
</ul>

<p>포닉스는 순열 $A$와 세 스택이 모두 빌 때까지 연산을 반복한 후, 먼저 떨어진 것이 앞에 오도록 원소들을 나열할 것이다. 포닉스가 원소들을 오름차순으로 재배열할 수 있을지 판별하여라.</p>

### 입력 

 <p>첫째 줄에 테스트케이스의 개수 $T$가 주어진다. $(1 \le T \le 500\ 000)$</p>

<p>각 테스트케이스의 첫째 줄에 순열의 길이 $N$이 주어진다. $(1 \le N \le 200\ 000)$</p>

<p>각 테스트케이스의 둘째 줄에 순열 $A$의 원소 $A_1, A_2, \cdots, A_N$이 공백으로 구분되어 주어진다. $A_i$는 $1$ 이상 $N$ 이하의 서로 다른 정수이다.</p>

<p>모든 테스트케이스에 대해 $N$의 합이 $500\ 000$ 이하임이 보장된다.</p>

### 출력 

 <p>각 테스트케이스에 대해 포닉스가 원소들을 오름차순으로 재배열하는 것이 가능하면 <span style="color:#e74c3c;"><code>YES</code></span>, 아니면 <span style="color:#e74c3c;"><code>NO</code></span>를 한 줄에 하나씩 순서대로 출력하여라.</p>

