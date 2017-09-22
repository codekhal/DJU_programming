# 수업

243-4 표

### priority.c 245p
```c
// file: pritority.c
#include <stdio.h>

int main(void)
{
	int a = 4, b = 6;
	double x = 3.3, y = 4.7;

	printf("%d ", a + b > y && x < y); // 
	printf("%d ", a++ - --b * 2);
	printf("%f ", a > b ? x + 1 : y * 2);
	printf("%f ", x += 3 && y + 2);
	printf("%f\n", (x = x + 1, y = y + 1));

	return 0;
}
```

```
콤마연산자 : a, b 와 같은 수식이 있을 때 행동은 a 를 평가하고 그 결과를 "무시"하고
b 를 평가하는 식으로 동작
```

//246p 12, 19

//247p 수식 c표현변경

//숙제 -> 249p 3, 6, 8 목요일 밤 12시

//연산자 끝!

## 조건문

//258p structrure of source

//261p 21 3항연산자 -> printf안에 조건

//262p 순서

//264p 

### tworeal.c 266p

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

### 268P

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

### *siomplemaxof3.c* 283p (switch case)
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
### 289p enum <- 열거형상수(switch 조건보기편하게)
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
과제 291p 3, 8, 9

//조건문완료
## 반복문

### 1-100까지의 합
```c
#include <stdio.h>

int main(void)
{
  int i, sum;
  i = 0;
  
  while(i<=10)
  {
    sum += i;
    i++;
  }
  printf("%d", sum);
}
```
### 구구단
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
### 309p do while <- 메뉴보여줄경우

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
### 331-332p
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
338p별찍기해보기

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

### continue break 혼합
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

# 홀수의합
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
