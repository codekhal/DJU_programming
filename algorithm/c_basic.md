# 01 배열

## example_1
```c
#include <stdio.h>

int main(void)
{
  char c[100];
  int i[100];
  short s[100];
  float f[100];
  long l[100];
  printf("char c 크기 = %d : char c_array 크기 = %d\n", sizeof(c[0]), sizeof(c));
  printf("int i 크기 = %d : int i_array 크기 = %d\n", sizeof(i[0]), sizeof(i));
  printf("short s 크기 = %d : short s_array 크기 = %d\n", sizeof(s[0]), sizeof(s));
  printf("float f 크기 = %d : float f_array 크기 = %d\n", sizeof(f[0]), sizeof(f));
  printf("long l 크기 = %d : long l_array 크기 = %d", sizeof(l[0]), sizeof(l));
  return 0;
}
```

## example_2
```c
#include <stdio.h>

int main(void)
{
  int a[3];
  a[0] = 91;
  a[1] = 86;
  a[2] = 97;
  printf("*** 학년별 취득 학점 ***\n\n");
  for (int i =1; i <= 3; i++)
  {
    printf("%d학년 : 총점 %d, 등급 = %s\n",i, a[i-1], (a[i-1] > 90) ? "A" : "B");
  }
  return 0; 
}
```

## example_3
```c
#include <stdio.h>

int main(void)
{
  int by[9];
  int input;
  for (int i = 1; i<=9; i++)
    by[i] = i;
  printf("1~9의 정수를 입력하세요 : ");
  scanf("%d", &input);
  printf("\n");
  for (int j = 1; j <=9; j++)
    printf("%d * %d = %d\n", input, j, j * input);
  return 0;
}
```
## example_4
```c
#include <stdio.h>

int main(void)
{
  char str[15] = "Data Structure!";
  int i;
  for (i = 0; i < 15; i++)
    printf("%c", str[i]);
  return 0;
}
```
## example_5 <- fix..
```c
#include <stdio.h>

int main()
{
    char str[10];    
    int length = 0;
    printf("문자열을 입력하세요: ");
    scanf("%s", str);     // 표준 입력을 받아서 배열 형태의 문자열에 저장
  
    printf("입력된 문자열은\n\"%s\"\n입니다.\n", str);  // 문자열의 내용을 출력
    for (int i=0; i<10; i++)
    {
      if (str[i] == NULL)
      {
        length = length;
      }
      else
        length += 1;
    }
    printf("입력된 문자열의 길이 = %d", length);

    return 0;
}
```
## example_6 - 다차원배열
```c
#include <stdio.h>

int main(void)
{
  int array[2][3][4];
  int a,b,c;
  int mean = 0;
  for (a=0; a<2;a++)
    for(b=0; b<3; b++)
      for(c=0; c<4; c++)
        {
        mean = mean + 1;
        array[a][b][c] = mean;
        }
  for (a=0; a<2;a++)
    for(b=0; b<3; b++)
      for(c=0; c<4; c++)
        printf("array[%d][%d][%d] = %d\n", a, b, c, array[a][b][c]);
  return 0;
}
```
## example_7 - 
```c
#include <stdio.h>

int main(void)
{
  char stu1[3][20]={ "Hong Gil Dong",
                     "Computer Electronic",
                     "201600101"};
  printf("학생 1의 이름: %s\n", stu1[0]);
  printf("학생 1의 학과: %s\n", stu1[1]);
  printf("학생 1의 학번: %s\n\n", stu1[2]);
  printf("학생 1\n\t%s\n\t%s\n\t%s\n\n", stu1[0], stu1[1], stu1[2]);
  printf("학생 2\n\t%s\n\t%s\n\t%s\n\n", stu1[0], stu1[1], stu1[2]);
  return 0;
}
```
## example_8 - pointer
```c
#include <stdio.h>

int main(void)
{
  int i = 10;
  int j = 20;
  int *ptr_i;
  int *ptr_j;
  ptr_i = &i;
  ptr_j = &j;
  printf("i의 값 = %d\n", i);
  printf("j의 값 = %d\n", j);
  printf("i의 메모리 주소(&i) = %d\n", &i);
  printf("j의 메모리 주소(&j) = %d\n", &j);
  printf("\n<< ptr=&i 실행>>\n");
  printf("ptr의 메모리 주소(&ptf) = %d\n", &ptr_i);
  printf("ptr의 값(ptr) = %d\n", ptr_i);
  printf("ptr의 참조값(*ptr) = %d\n\n", *ptr_i);
  printf("<< ptr=&j 실행 >>\n");
  printf("ptr의 메모리 주소(&ptr) = %d\n", &ptr_j);
  printf("ptr의 값(ptr) = %d\n", ptr_j);
  printf("ptr의 참조값(*ptr) = %d\n\n", *ptr_j);
  printf("<< i=*ptr 실행 >>\n");
  i = *ptr_j;
  printf("i의 값 = %d", *ptr_j);
  return 0; 
}
```
## examper_9
```c

# 02 포인터
# 03 구조체
# 04 동적메모리할당
# 05 재귀호출
