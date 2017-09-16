# Algorithm 수업 WEEK1 과제

## 1. 피보나치.c

```c

```

```
반복 알고리즘과 재귀 알고리즘의 성능차이를 연산량을 늘려가면서 걸린 시간의 측정으로 판단할 수 있다.
```

fiboByrepetition함수를 보면 변수에 자료형을 지정하고 값을 대입하는일 1번 worst case로써 조건과 맞는지 체크하고 맞으면 조건 안의 일을 하는 if문을 1번하고 이를 통과하면 for문을 돌리게 되는데 for문 자체는 O(n)로 돌리 수 있으나 repetition하지 않은 앞에 2번의 일은 constant한 값이므로 결국 O(n)의 시간복잡도를 가진다.

fiboByrecursion함수를 보면 재귀 알고리즘들이 항상 2번 호출되기 때문에 O(2^n)의 시간복잡도를 가진다.

피보나치.c의 출력결과는

<a href="url"><img src="http://blog.naver.com/PostView.nhn?blogId=chandong83&logNo=220812226888&parentCategoryNo=&categoryNo=30&viewDate=&isShowPopularPosts=false&from=postView#"></a>

![alt text](https://drive.google.com/open?id=0B4Q0BjjmlIe7ZlZXYTFHdEdiVGc)
이며 이를 그래프로 그려보면

![alt text](https://drive.google.com/open?id=0B4Q0BjjmlIe7NmNmbVYzUklfeWM "2")

와 같다. x축은 시간이며 y축은 데이터 량인데 이 경우 repetition한 함수가 월등히 높은 성능을 가진다는걸 볼 수 있다.

![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")

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
}

void multiplyMatrix(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rowNa, int colNb, int colNa){
  int i, j, k;
  for( i = 0; i < rowNa; i++)
    for (j = 0; j < colNb; j++) {
      c[i][j] = 0;
      for(k = 0; k< colNa; k++)
        c[i][j] += a[i][k] + b[k][j];
    }
}

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
  getchar();

  multiplyMatrix(a, b, c, 2, 2, 2);
  printMatrix(c, rowN, colN);
  getchar();
  return 0;
}

```

행렬덧셈.cpp 소스코드의 addMatrix함수를 살펴보면 중첩 반복문이 2개 들어가므로 n*n -> O(n^2)의 시간복잡도를 가진다.

소스코드의 multiplyMatrix 함수의 경우 중첩반복문이 3개 들어가므로 n*n*n -> O(n^3)의 시간복잡도를 가진다.

![alt text](https://drive.google.com/open?id=0B4Q0BjjmlIe7eE5mWTNKbWwyS00 "3")

## 3. 재귀.cpp

```c

```

재귀.cpp 소스코드의 repetitiveSum함수를 보면 피보나치.c에서 살펴봤듯 반복함수이므로 O(n)의 시간복잡도를 가진다.

![alt text](https://drive.google.com/file/d/0B4Q0BjjmlIe7Y1hUbDRDRmpwYUE/view?usp=sharing "4")

?소스코드의 recursiveSum함수는 bestcase든 worstcase든 꼭 1번 조건문을 실행하고 그 조건문 안에서 else의 경우 재귀를 하게 되므로 피보나치.c에서 알아본 것 처럼 항상 2번 호출되므로 O(2^n)의 시간복잡도를 가진다.

![alt text](https://drive.google.com/open?id=0B4Q0BjjmlIe7VWJ2WlhjRmlYdlk "5")

recursiveFastSum함수를 살펴보면 재귀함수이지만 recursiveFastSum의 n의값을 2로 나누므로 O(밑이 2인 로그의 n)의 시간복잡도를 가진다.

![alt text](https://drive.google.com/open?id=0B4Q0BjjmlIe7Xy1SNlFDOGVSVGM "6")


## 4. 다항식덧셈.c

```c

```

?다항식덧셈.c 소스코드의 addPolynomial함수를 살펴보면 변수의 선언과 초기화는 constant한 값이므로 제외하고 while문을 살펴보면 루프문은 O(log n)의 시간복잡도를 가지고

![alt text](https://drive.google.com/open?id=0B4Q0BjjmlIe7Y3BYQ0h2ZXB2Z1E "7")
