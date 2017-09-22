# 수업

243-4 표

## priority.c 245p
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

//258p structrure of source

//261p 21 3항연산자 -> printf안에 조건

//262p 순서

//264p 

## tworeal.c 266p

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

268P

```
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

## *283p switch case*
```
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
      printf("최대값: %d, \n", ((x > y) ? x : y));
      break;
  }
  return 0;
}
```
