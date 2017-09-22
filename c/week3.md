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

//246p 12, 19

//247p 수식 c표현변경

//숙제 -> 249p 3, 6, 8 목요일 밤 12시

//연산자 끝!

//258p structrure of source

//261p 21 3항연산자 -> printf안에 조건

//262p 순서

//264p 

# 266p

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

