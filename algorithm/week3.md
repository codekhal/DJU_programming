# Algorithm 수업 3주차 과제

## 1. 이진탐색.c

```c
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

int binarySearch_Rep(int A[], int left, int right, int X) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (X == A[mid]) {
			return mid;
		}
		else if (X < A[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return 0;
}

int binarySearch_Rec(int A[], int left, int right, int X) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (X == A[mid]) {
			return mid;
		}
		else if (X < A[mid]) {
			return binarySearch_Rec(A, left, mid - 1, X);
		}
		else {
			return binarySearch_Rec(A, mid + 1, right, X);
		}
		return 0;
	}
}

int main() {
	int A[] = { 1, 3, 7, 9, 11, 13, 15, 17, 19, 21, 23 }, X = 15;
	int posX;

	posX = binarySearch_Rep(A, 0, 10, X);
	printf("repetition: position(%d) = %d\n", X, posX);
	getchar();

	posX = binarySearch_Rec(A, 0, 10, X);
	printf("recursion: position(%d) = %d\n", X, posX);
	getchar();

	return 0;
}
```
### 분석

이진탐색 알고리즘의 T(n)함수는 T(n) = 1 for n = 1 and T(n) = T(n/2) + O(1) for n>=1

The binary search algorithm's T(n) function is as follows : T(n) = 1 for n = 1 and T(n) = T(n/2) + O(1) for n >= 1

then to assimilate the Master's Theorem into the case, we shall get that log 1 with the base of 2 from T(n/2), in other words, the h(n) of the function.

log 1 with the base 2 is 0

since 0 is less than 1 (g(n)), then we use case 2

with k equals to 0

then we get that the expression becomes T = Theta((n^log 1 with base 2) * (log n) ^ k + 1 = 0 + 1) = theta(log n).

## 2. TowerofHanoi
```c
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

void TowerOfHanoi(int n, char x, char y, char z) {
	if (n > 0)
	{
		TowerOfHanoi(n - 1, x, z, y);
		printf("\n%d -> %c", x, y);
		TowerOfHanoi(n - 1, z, y, x);
	}
}

int main() {
	int n;
	printf("\nEnter number of plates: ");
	scanf("%d", &n);
	TowerOfHanoi(n, 'A', 'B', 'C');
	printf("\n");
	getchar();
	return 0;
}
```

## 3. 재귀 호출 알고리즘의 시간 복잡도 분석

(1) 시간복잡도 함수의 순환방정식(recurrence equation, 점화식)

T(n) = c	n=1 일 때

aT(n/b) + d(n) + c(n)	n > 1 일 때

설명: d(n)은 문제를 분할하는 데 걸리는 시간, c(n)은 부분문제들의 해를 결합하여 원래 문제의 해를 만드는 데 걸리는 시간임.

(2) 예제들

1. T(n) = 1 		n = 1 일 때

T(n/2) + 1 		n > 1 일 때

풀이: 

2. T(n) = 0		n = 1 일 때

2T(n/2) + 1		n > 1 일 때

풀이: 0

3. T(n) = 0		n = 1 일 때

2T(n/2) + (n - 1) 	n > 1 일 때

풀이: -1

4. T(n) = 1		n = 1 일 때

2T(n-1) + 1		n > 1 일 때

풀이: 12

(3) 특정 알고리즘의 시간복잡도 분석

1. 배열의 덧셈(재귀, 분할정복)

```c
int sum {int a[], int left, int right) {
	int mid, sum_left, sum_right;
	if (left == right) return a[left];
	else {
		mid = (left + right)/2;
		sum_left = sum(a, left, mid);
		sum_right = sum(a, mid+1, right);
		return sum_left + sum_right;
	}
}
```

* 순환 방정식: T(n) = 2T(n/2) + c

2. 이진 탐색(분할 정복)

```c
int binary_search(int a[], int left, int right, int x) {
	int mid;
	if(left <= right) {
		mid = (left + right)/2;
		else if(x == a[mid]) return binary_search(a, left, mid-1, x);
			else return binary_search(a, mid+1, right, x);
	}
	return 0;
}
```

* 순환 방정식: T(n) = T(n/2) + c


3. 병학 정렬(분할 정복)

```c
void merge_sort(int a[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right)/2;
		merge_sort(a, left, mid);
		merge_sort(a, mid+1, right);
		merge(a, left, mid, right);
	}
}
```

* 순환 방정식: T(n) = 2T(n/2) + c	

//c -> (n-1)(?)

```
시간 복잡도 표현(Notation)

Big O - O(N) : 실행 시간 상한 표현 (가장 많이 쓰임) - 최악의 시간 계산 

Ω      - Ω(N) : 실행 시간 하한 표현                         - 운좋을때 걸리는시간

Θ      - Θ(N) : 실행 시간 평균 표현

```

T(n)=T(divide)+T(conquer)+T(merge)
