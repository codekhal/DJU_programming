# week4


## 함수로 최대값 구하기

```c
#include <stdio.h>
int get_max(int x, int y);

int main(void)
{
  int i, j;
  scanf("%d %d", &i, &j);
  printf("max number = %d", get_max(i, j));
  return 0;
}

int get_max(int x, int y)
{
  if(x > y) return(x);
  else return(y);
}
```

347p project may will give assighnmet when professor want

## 저장 유형 지정자 static -> 지역변수가 "정적변수"로 된다

```c
#include <stdio.h>
void sub(vodi);

int main(void)
{
  int i;
  for ( i= 0; i < 3; i ++)
    sub();
  return 0;
}
void sub(void)
{
  int auto_count = 0;
  static int static_count = 0;
  
  auto_count++;
  static_count++;
  printf("auto_count=%d\n", auto_count);
  printf("static_count=%d\n", static_count);
}
```
## 저장 유형 지정자 register

## 저장 유형 지정자 extern -> 변수가 현재 번위가 아닌 다른 곳에서 선언되었다는 것을 알림.

```c
#include <stdio.h>
int all_files;
extern void sub(void);

int main(void)
{
	sub();
	printf("%d\n", all_files);
	return 0;
}
```

```c
extern int all_files;
void sub(void)
{
	all_files = 10;
}
```
## 순환함수 -> recursion

```c
팩토리얼
```

## 배열-> 변수쓰듯이 써라(연이어져있음)

```c
#include <stdio.h>
#define STUDENTS 5
int main(void)
{
  int stu[STUDENTS];
  int sum, average;
  for (int i =0; i < STUDENTS; i++)
  {
    scanf("%d", &stu[i]);
  }
  for (int i = 0; i < STUDENTS; i++)
    sum += stu[i];
  average = sum / STUDENTS;
  printf("%d", average);
}
```
배열의 개수 -> 배열의 크기 / size of // sizeof(x) / sizeof(int)
## 최소값 탐색
```c
#include <stdio.h>
#define STUDENTS 5
int main(void)
{
  int grade[STUDENTS];
  int min;
  
  for (int i = 0; i < STUDENTS; i++)
    scanf("%d", &grade[i]);
  
  min = grade[0];
  for (int i = 1; i < STUDENTS; i++)
    if ( min > grade[i])
      min = grade[i];
  printf("%d", min);
}
```
#include <stdio.h>
#define CLASSES 3
#define STUDENTS 5


int main(void)
{
  int s[CLASSES][STUDENTS] = {
    [0, 1, 2, 3, 4],
    [10, 11, 12, 13, 14];
    [20. 21, 22, 23, 24];
  };
  int clas, student, total, subtotal;
  for(clas = 0; clas< CLASSES; clas++);
    subtotal = 0;
    for(student = 0; student<STUDENTS; studnet++);
      subtotal += s[clas][students];
    printf9"%d", clas, subtoatal/STUDENTS);
    total += subtotal;
  
  printf9"%d", total/(CLASSES*STUDENTS);
  return 0;
    
}
시험범위 - 배열까지 / 금요일 3교시(11시)

과제 - 347~356 5가지 프로젝트중 1개 택해서 하기
