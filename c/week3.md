# 05 연산자

## 243-4 표
![c](https://user-images.githubusercontent.com/16266103/31728902-87d6ed8a-b468-11e7-80ab-c96c9df7c30d.jpg)

> ++a, --a, !, ~, sizeof, -, +, &, * // 우에서 좌로

> *, /, % // 좌에서 우로

> +, - // 좌에서 우로

> <, >, <=, >= // 좌에서 우로

> ==, != // 좌에서 우로

> && // 좌에서 우로

> || // 좌에서 우로

> 콤마 < 대입 < 조건(삼항) < 논리 < 관계 < 산술 < 단항 < 괄호와 대괄호 // 논리 < 관계 < 산술 -> 이항연산자

## priority.c 245p

```c
// file: pritority.c
// 기본적으로 소수점 아래 6자리까지만 표현함
// 논리 < 관계 < 산술
// 중요한건 계산순서
#include <stdio.h>

int main(void)
{
	int a = 4, b = 6;
	double x = 3.3, y = 4.7;

	printf("%d ", a + b > y && x < y); // 
	printf("%d ", a++ - --b * 2);
	printf("%f ", a > b ? x + 1 : y * 2);
	printf("%f ", x += 3 && y + 2); // **
	printf("%f\n", (x = x + 1, y = y + 1)); //콤마연산자->여러개 연산은 되지만 맨끝값 출력

	return 0;
}
// &&와 || 우선순위 알아놓기
```

```
콤마연산자 : a, b 와 같은 수식이 있을 때 행동은 a 를 평가하고 그 결과를 "무시"하고
b 를 평가하는 식으로 동작
```

## //246p 12, 19

```c
#include <stdio.h>

int main(void)
{
  int m = 5, n = 10;
  
  //우측에서 좌측으로 결합
  printf("%d ", n += m /= 3);
  m = 5; n = 10;
  printf("%d\n", (n += (m /= 3)));//**
  
  printf("%d ", 10 * 3 / 2);//**좌측에서 우측으로 결합
  printf("%d\n", 10 * (3 / 2));//**우측에서 좌측으로 결합
  
  //우측에서 좌측으로 결합
  printf("%d ", 3>4 ? 3-4 : 3>4 ? 3+4 : 3*4);//**조건연산자는 결합성이 오른쪽에서 왼쪽으로
  printf("%d\n", 3>4 ? 3-4 : (3>4 ? 3+4 : 3*4))//**
  
  return 0;
}
```

## //247p 수식 c표현변경

> (a + b) * (x + y) * (x + y)

> 4*x*x*x + 3*x*x - 5*x + 10

> (a + b) / (a - b)

> (5.0 / 9) * (F - 32)

> 9.0 / 5 * C + 32

> (1 - x) / (x * x)

> (-b + sqrt(b*b - 4*a*c)) / 2*a // sqrt(x) 제곱근을 구하는 함수


//숙제 -> 249p 3, 6, 8 목요일 밤 12시

//연산자 끝!

# 06 조건문 // enum is the most careful part of our exam

## //258p structrure of source
```c
//#define _CRT_SECURE_NO_WARNINS
#include <stdio.h>

int main(void)
{
  double temperature;
  
  printf("현재 온도 입력: ");
  scanf("%lf", &temperature);
  
  if (temperature >= 32.0)
  {
    printf("폭염 주의보를 발령합니다.\n");
    printf("건강에 유의하세요.\n");
  }
  printf("현재 온도는 섭씨 %.2f 입니다.\n", temperature);
  
  return 0;
}
```

## //261p 21 3항연산자 -> printf안에 조건
```c
// file: ifelse.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
  int n;
  
  printf("정수 입력: ");
  scanf("%d", &n);
  
  if (n % 2)
    printf("홀수");
  else
    printf("짝수");
  
  printf("입니다.\n");
  
  //조건연산자 이용
  (n % 2) ? printf("홀수") : printf("짝수"); // ** 3항연산자
  printf("입니다.\n");
  
  return 0;
}
```

## //262p 순서
```c
#include <stdio.h>

int main(void)
{
  int n;
  
  printf("정수 입력: ");
  scanf("%d", &n);
  
  if(n % 3)
  {
    printf("입력된 %d는 3의 배수가 아닙니다.\n", n);
  }
  else 
  {
    printf("입력된 %d는 3의 배수입니다.\n", n, n % 3);
  }
  printf("조건식 %d %% 3의 결과는 %d입니다.\n", n, n % 3);
  return 0;
}

}
```

## //264p < double -> %lf / && -> 둘다만족
```c
#include <stdio.h>

int main(void)
{
  double gpa;
  
  printf("평균평점 입력: ");
  scanf("%lf", &gpa);
  
  if (gpa >= 4.3)
    printf("성적이 최고 우수한 학생입니다.\n");
  else if(gpa >= 3.8)
    printf("성적이 매우 우수한 학생입니다.\n");
  else if(gpa >= 3.0)
    printf("성적이 우수한 학생입니다.\n");
  else
    printf("성적이 3.0 미만인 학생입니다.\n");
    
  return 0;
}
```

## lab tworeal.c 266p

```c
#include <stdio.h>

int main(void)
{
  double x= 0, y = 0, result = 0;
  
  printf("두 실수를 입력: ");
  scanf("%lf %lf", &x, &y);
  
  if (x >y)
  {
    result = x / y;
  }
  else if (x == y)
  {
    result = x * y;
  }
  else
  {
    result = x + y;
  }
  printf("연산 결과: %.2f\n", result);
}
```

## lab 268P

```c
#include <stdio.h>

int main(void)
{
  int i, j;
  
  printf("취득하시려는 운전면허가 1종이면 1 2종이면 2를 입력해 주세요 ^^: ");
  scanf("%d", &i);
  printf("점수를 입력해 주세요: ");
  scanf("%d", j);
  
  if (i == 1)
  {
    if (j < 70)
    {
      printf("%d종 불합격 입니다.", i);
    }
    else if(j >= 70)
    {
      printf("%d종 합격 입니다.", i);
    }
  }
  else if(i == 2)
  {
    if (j < 70)
    {
      printf("%d종 불합격 입니다.", i);
    }
    else if(j >- 70)
    {
      printf("%d종 합격 입니다.", i);
    }
  }
}
```

## lab *siomplemaxof3.c* 283p (switch case)
```c
#include <stdio.h>

int main(void)
{
  int x, y, z;
  
  printf("세 정수를 입력: ");
  scanf("%d %d %d", &x, &y, &z);
  
  switch ((x > y))
  {
    case 0:
      printf("최대값: %d, \n", ((y > z) ? y : z));
      break;
    case 1:
      printf("최대값: %d, \n", ((x > z) ? x : z));
      break;
  }
  return 0;
}
```
## ** lab 289p enum <- 열거형상수(switch 조건보기편하게) (enum 155p)
```c
#include <stdio.h>

int main(void)
{
  enum color { RED, GREEN, BLUE };
  int input;
  
  printf("세 정수(R[0], G[1], B[2]) 중의 하나를 입력: ");
  scanf("%d", &input);
  
  switch (input) {
    case RED:
      printf("Red\n");
      break;
    case GREEN:
      printf("Green\n");
      break;
    case BLUE:
      printf("Blue\n");
      break;
      
    default:
      printf("잘못된 입력\n");
  }
  
  return 0;
}
```
//과제 291p 3, 8, 9

//조건문완료
# 07 반복문

## 1-100까지의 합
```c
#include <stdio.h>

int main(void)
{
  int i, sum;
  i = 1;
  
  while(i<=10)
  {
    sum += i;
    i++;
  }
  printf("%d", sum);
}
```
## 구구단
```c
#include <stdio.h>

int main(void)
{
  int i, j;
  
  scanf("%d", &j);
  i = 1;
  
  while(i<=9)
  {
    printf("%d * %d = %d\n", j, i, j * i);
    i++;
  }
}
```
## 309p do while <- 메뉴보여줄경우(입력 후에 검사를 진행하는 처리 과정으로 do while 문으로 구현이 적합)

```c
#include <stdio.h>

int main(void)
{
  int input;
  
  do
  {
    printf("정수 또는 0(종료)을 입력: ");
    scanf("%d", &input);
  }while(input != 0);
  
  puts("종료합니다.");
  
  return 0;
}
```

316p
```c
#include <stdio.h>

int main(void)
{
  
  int i, j, sum;
  sum = 1;
  scanf("%d", &i);
  for(j = 1; j <= i; j++)
  {
    sum = sum * j;
  }
  printf("%d", sum);
}
```
## 322
```c
#include <stdio.h>

int main(void)
{
  int i, sum;
  
  for(i = 1, sum = 0; i <= 10; i++)
    sum += i;
  printf("1에서 10까지 합: %3d\n", sum);
  
  for(i = 1, sum = 0; i <= 10; )
    sum+= i++;
  printf("1에서 10까지 합: %3d\n", sum);
  
  for(i = 0, sum = 0; i <= 9;)//****
    sum+= ++i;
  printf("1에서 10까지 합: %3d\n", sum);
  
  for(i = 1, sum =0; i<= 10; sum+= i++);//****
  printf("1에서 10까지의 합:%3d\n", sum);
  
  return 0;
}
```
## 330-332p
```c
#include <stdio.h>

int main(void)
{
  const int MAX = 15;
  
  printf("1에서 %d까지 정수 중에서 3으로 나누어 떨어지지 않는 수\n", MAX);
  for(int i = 1; i <= MAX; i++)
  {
    if (i % 3 == 0)
      continue;
    printf("%3d", i);
  }
  puts("");
  
  return 0;
}
```
```c
#include <stdio.h>

int main(void)
{
  int count = 1;
loop :
  printf("%3d", count);
  if(++count <= 10)
    goto loop;
  
  printf("\n프로그램을 종료합니다.\n");
  
  return 0;
}
```
```c
#include <stdio.h>

int main(void)
{
  int input;
  
  do {
    printf("\t [1] 한식\n");
    printf("\t [2] 양식\n");
    printf("\t [3] 분식\n");
    printf("\t [4] 기타\n");
    printf("메뉴 번호 선택 후 [Enter] : ");
    scanf("%d", &input);
    printf("선택 메뉴 %d\n", input);
    if (input <= 4 && input >= 1)
      break;
  } while(1);
  
  return 0;
  
}
```

## 338p별찍기해보기
```c
#include <stdio.h>

int main(void)
{
  int a = 5;
  for(int i = 1 ; i <= a; i++)
  {
    for (int j = 1; j <= i; j++)
      printf("*");
    puts("");
  }
  
  return 0;
}
```

### 342p 구구단
```c
#include <stdio.h>
#define MAX 9
int main(void)
{
  printf("===구구단 출력====\n");
  for (int i =1; i <= MAX; i++)
  {
    printf("%6d단 출력\n", i);
    for(int j = 2; j <= MAX; j++)
      printf("%d x %d = %d   ", i, j, i*j);
    
  }
  return 0;
}
```

while문 <- continue <= inf loop when you lose 증감

## continue break 혼합
```c
#include <stdio.h>'

int main(void)
{
  char letter;
  while(1)
  {
    printf("소문자를 입력하시오: ");
    fflush(stdin);
    scanf(" %c",&letter);
    
    if(letter=='Q')
      break;
    if(letter <'a'||letter>'z')
      continue;
    letter -= 32;
    printf("변환된 대문자는 %c입니다.\n", letter);
    
  }
  return 0;
}
```

## 홀수의합
```c
#include <stdio.h>

int main(void)
{
  int i, sum;
  i = 1;
  sum = 0;
  char letter;
  while(i <= 5)
  {
    if (i % 2 == 0)
    {
      i++;
      continue;
    }
    sum += i;
    i++;
  }
  printf("%d", sum);

  return 0;  
}
```

## 334p 해보기
```c
#include <stdio.h>

int main(void)
{
  const int MAX = 15;
  
  printf("1에서 %d까지 정수 주에서 5로 나누어 떨어지지 않는 수\n", MAX);
  for(int i = 1; i<=MAX; i++)
  {
    if(i%5)
      continue;
    printf("%3d", i);
  }
  puts("");
  
  return 0;
}
```
