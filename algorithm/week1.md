# Algorithm 수업 1주차 과제

## 1. 피보나치.c

### 개요

```
반복 알고리즘과 재귀 알고리즘의 성능차이를 연산량을 늘려가면서 걸린 시간의 측정으로 판단할 수 있다.
```

```c
//***Fibonacci Series***
//------------------------
// Method 1: Repetition Algorithm Usage
// Method 2: Recursion Algorithm Usage
// -----------------------

#include <stdio.h>
#include <conio.h>
#include <time.h>

int fiboByRepetition(int n) 
{
	int fn_1 = 0, fn_2 = 1, fn, i;
	if (n <= 1) return 1;
	for (i = 2; i <= n; i++)
	{
		fn = fn_1 + fn_2;
		fn_1 = fn_2;
		fn_2 = fn;
	}
	return fn;
}// 

int fiboByRecursion(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fiboByRecursion(n - 1) + fiboByRecursion(n - 2);
}// 재귀함수 

int main() {
	int fibo;
	clock_t start, stop;//clock_t는 time.h에 포함되어 있는 데이터형 중 하나
	double duration, total;

	printf("enter the no. of terms here: ");
	scanf("%d", &n1);// 처리 할 데이터 량 입력

	printf("the fibonacci series(repetition): \n");
	start = clock();    fibo = fiboByRepetition(n1); stop = clock();
	total = ((double)(stop - start)) / CLK_TCK;
	printf("%d(%3d, %f)\n", fibo, n1, total);
	getchar();// 데이터량에 따른 반복의 걸린 시간

	printf("the fibonacci series(recursion): \n");
	start = clock();   fibo = fiboByRecursion(n1); stop = clock();
	total = ((double)(stop - start)) / CLK_TCK;
	printf("%d(%3d, %f)\n", fibo, n1, total);
	getchar();// 데이터량에 따른 재귀의 건린 시간

	return 0;
}
```

### 실행결과

![1_recursion_repetition_result](https://user-images.githubusercontent.com/16266103/30514036-f648d1cc-9b48-11e7-9137-795cc66573ff.png)

### 소스분석

fiboByrepetition함수를 보면 변수에 자료형을 지정하고 값을 대입하는일 1번 worst case로써 조건과 맞는지 체크하고 맞으면 조건 안의 일을 하는 if문을 1번하고 이를 통과하면 for문을 돌리게 되는데 for문 자체는 O(n)로 돌리 수 있으나 repetition하지 않은 앞에 2번의 일은 constant한 값이므로 결국 O(n)의 시간복잡도를 가진다.

fiboByrecursion함수를 보면 재귀 알고리즘들이 항상 2번 호출되기 때문에 O(2^n)의 시간복잡도를 가진다.

이며 이를 그래프로 그려보면

<img width="477" alt="1_recursion_repetition" src="https://user-images.githubusercontent.com/16266103/30514050-15d19c04-9b49-11e7-8709-e45eb79b86d2.png">

와 같다. x축은 시간이며 y축은 데이터 량인데 이 경우 repetition한 함수가 월등히 높은 성능을 가진다는걸 볼 수 있다.

![kakaotalk_photo_2017-09-17-01-58-13](https://user-images.githubusercontent.com/16266103/30514228-b111662a-9b4b-11e7-8b00-12c007ad392d.jpeg)

그러나 위와같은 그래프의 경우 일정 구간동안 recursion이 repetition한 것 보다 성능이 뛰어난 경우가 있다는것을 확인할 수 있다.

## 2. matrix_add

```c

#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 2

void addMatrix(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rowN, int colN) {
  int i, j;
  for (i = 0; i < rowN; i++)
    for ( i = 0; i < colN; i++)
      c[i][j] = a[i][j] + b[i][j];
}// 2차행렬 <- 중첩반복문 2개가 들어가므로 n * n = O(n^2)

void multiplyMatrix(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rowNa, int colNb, int colNa){
  int i, j, k;
  for( i = 0; i < rowNa; i++)
    for (j = 0; j < colNb; j++) {
      c[i][j] = 0;
      for(k = 0; k< colNa; k++)
        c[i][j] += a[i][k] + b[k][j];
    }
}// 3차행렬 <- 중첩반복문 3개가 들어가므로 n * n * n  = O(n^3)

void printMatrix(int mat[][MAX_SIZE], int rowN, int colN){
  for (int i = 0; i < rowN; i++) {
    for(int j = 0; j< colN; j++)
      cout << mat[i][j] << "\t";
    cout << "\n";
  }
}

int main() {
  int a[][MAX_SIZE] = {{1,2}, {4,5}}, b[][MAX_SIZE]= {{1,2},{-4,-5}},c[2][MAX_SIZE];
  int rowN=2, colN=2;

  addMatrix(a, b, c, rowN, colN);
  printMatrix(c, rowN, colN);
  getchar();// 

  multiplyMatrix(a, b, c, 2, 2, 2);
  printMatrix(c, rowN, colN);
  getchar();
  return 0;
}

```

### 실행결과

![1formatrix](https://user-images.githubusercontent.com/16266103/30514056-359c2676-9b49-11e7-94f3-efd64fbaf552.PNG)

### 소스분석

행렬덧셈.cpp 소스코드의 addMatrix함수를 살펴보면 중첩 반복문이 2개 들어가므로 n*n -> O(n^2)의 시간복잡도를 가진다.

소스코드의 multiplyMatrix 함수의 경우 중첩반복문이 3개 들어가므로 n*n*n -> O(n^3)의 시간복잡도를 가진다.

### 질문

코드의 결고과 의미하는 바를 모르겠고 시간복잡도 측정을 위해 어떤 코드가 삽입되어야 하는지 궁금하다. 

## 3. 재귀.cpp

```c
#include <iostream>
#include <vector>
using namespace std;

int repetitiveSum(int n) {
	int ret = 0;
	static int count = 0;
	for (int i = 1; i < (n + 1); i++) {
		cout << ++count << "\t";
		ret += i;
	}

	cout << endl;
	return ret;
}// 반복형태의 덧셈

int recursiveSum(int n) {
	static int count = 0;
	if (n == 1) {
		cout << ++count << "\n";
		return 1; //base case for all
	}
	else {
		cout << ++count << "\t";
		return (n + recursiveSum(n - 1));
	}
}// 재귀 형태의 덧셈

int recursiveFastSum(int n) {
	static int count = 0;
	if (n == 1) { cout << ++count << "\t"; return 1; }
	if (n % 2 == 1) { cout << ++count << "\t"; return recursiveFastSum(n - 1) + n; }
	cout << ++count << "\t"; return 2 * recursiveFastSum(n / 2) + (n / 2) * (n / 2);
}// 기존 재귀의 역 형태의 덧셈

int main() {
	int num = 1024, summation = 0;

	summation = repetitiveSum(num);
	cout << "repetitive sum = " << summation << endl;
	getchar();

	summation = recursiveSum(num);
	cout << "recursive sum = " << summation << endl;
	getchar();

	summation = recursiveFastSum(num);
	cout << "recursive fast sum = " << summation << endl;
	getchar();

	return 0;
}
```

### 실행결과

#### >> repetitiveSum

![2forrecandrev_repetitivesum](https://user-images.githubusercontent.com/16266103/30514066-6290e784-9b49-11e7-8bd4-c58787794bd7.PNG)

#### >> recursiveSum

![3forrecandrev_recursivesum](https://user-images.githubusercontent.com/16266103/30514069-70399ec6-9b49-11e7-90b9-027d940d63f1.PNG)

#### >> recursiveFastSum

![4forrecandrev_recursivefastsum](https://user-images.githubusercontent.com/16266103/30514083-98db6b48-9b49-11e7-90a0-d415329676fd.PNG)

### 소스분석

재귀.cpp 소스코드의 repetitiveSum함수를 보면 피보나치.c에서 살펴봤듯 반복함수이므로 O(n)의 시간복잡도를 가진다.

?소스코드의 recursiveSum함수는 bestcase든 worstcase든 꼭 1번 조건문을 실행하고 그 조건문 안에서 else의 경우 재귀를 하게 되므로 피보나치.c에서 알아본 것 처럼 항상 2번 호출되므로 O(2^n)의 시간복잡도를 가진다.

recursiveFastSum함수를 살펴보면 재귀함수이지만 recursiveFastSum의 n의값을 2로 나누므로 O(밑이 2인 로그의 n)의 시간복잡도를 가진다.

### 질문

'cout << ++count << "\t"; return 2 * recursiveFastSum(n / 2) + (n / 2) * (n / 2);' 라는 코드의 해석(why 홀수 짝수?)
why recursiveFastSum이 기존 재귀의 역의 형태를 가지는지.

## 4. 다항식덧셈.c

```c
#include <stdlib.h>
#include <stdio.h>
#define MAX(a, b) ((a > b) ? a : b)
#define MAX_DEGREE 50
//-------------------------------

typedef struct { int degree; float coef[MAX_DEGREE]; } polynomial;
polynomial addPolynomial(polynomial, polynomial);
void printPolynomial(polynomial);

int main() {
	polynomial A = { 3,{ 4, 3, 5, 0 } }, B = { 4,{ 3, 1, 0, 2, 1 } }, C;
	C = addPolynomial(A, B);

	printf("\n A(x) = \t"); printPolynomial(A);
	printf("\n B(x) = \t"); printPolynomial(B);
	printf("\n C(x) = \t"); printPolynomial(C);
	getchar();
	return 0;
}

polynomial addPolynomial(polynomial A, polynomial B) {
	polynomial C;
	int A_i = 0, B_i = 0, C_i = 0;
	int A_deg = A.degree, B_deg = B.degree;
	C.degree = MAX(A.degree, B.degree);
	while (A_i <= A.degree && B_i <= B.degree) {
		if (A_deg > B_deg) {
			C.coef[C_i++] = A.coef[A_i++];
			A_deg--;
		}
		else if (A_deg == B_deg) {
			C.coef[C_i++] = A.coef[A_i++] + B.coef[B_i++];
			A_deg--, B_deg--;
		}
		else {
			C.coef[C_i++] = B.coef[B_i++];
			B_deg--;
		}
	}
	return C;
}

void printPolynomial(polynomial P) {
	int i, degree = P.degree;
	for (i = 0; i <= P.degree; i++) {
		printf("%3.0fx^%2d", P.coef[i], degree--);
		if (i < P.degree) printf(" + ");
	}
	printf("\n");
}

```

### 실행결과

![5forpolynomials_add](https://user-images.githubusercontent.com/16266103/30514094-ae678a96-9b49-11e7-87bd-95d487c1e533.PNG)

### 소스분석

다항식덧셈.c 소스코드의 addPolynomial함수를 살펴보면 변수의 선언과 초기화는 constant한 값이므로 제외하고 while문을 살펴보면 루프문(반복)은 O(n)의 시간복잡도를 가지게 된다.
 
### 질문

while문 안의 if, else문의 경우 어떤 시간복잡도를 갖는지. 

# 수업 복습

![1](https://user-images.githubusercontent.com/16266103/30526906-58ca408c-9c5d-11e7-8fe1-0d141aa0c013.jpg)

// O(logn)인 경우 n이 어떤 값으로 나눈다는 것만 사용

## 점근적 표기법
