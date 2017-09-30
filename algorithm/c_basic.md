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
# 02 포인터

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
## example_9 <- fix
```c
#include <stdio.h>

int main(void)
{
  char string1[30] = "Dreams come true!";
  int *ptr1;
  ptr1 = &string1;
  printf("string1의 주소 = %d\tptr 1 = %d\n", &string1, ptr);
  printf("string1 = %s\n", string1);
  printf("ptr1 = %s\n\n", *ptr1);
  printf("")
  return 0;
}
````
## example_10  <- fix(2/3입력가능하도록)
```c
#include <stdio.h>

int main(void)
{
  char input[4][10];
  for(int i = 0; i < 4; i++)
    scanf("%s", input[i]);
  puts("");
  for(int j = 0; j < 4; j++)
    printf("%s\n", input[j]);
  return 0;
}
```

## example_11 - pointer array fix..
```c
#include <stdio.h>

int main(void)
{
  char ptrptr[2];
  char *ptrArray[2] ={{"Korea"}, {"Soeul"}}; 
  
  printf("ptrArray[0]의 주소(&ptrArray[0]) = %d\n", &ptrArray[0]);
  printf("ptrArray[0]의 값 (ptrArray[0])= %d\n", ptrArray[0]);
  printf("ptrArray[0]의 참조값 (*ptrArray[0]) = %c\n",*ptrArray[0]);
  //printf("ptrArray[0]의 참조 문자열 (*ptrArray[0]) = %s\n\n", *ptrArray);
  printf("ptrArray[1]의 주소 (&ptrArray[1] = %d\n", &ptrArray[1]);
  printf("ptrArray[1]의 값 (ptrArray[1]) = %d\n", ptrArray[1]);
  printf("ptrArray[1]의 참조값 (*ptrArray[1]) = %c\n", *ptrArray[1]);
  //printf("ptrArray[1]의 참조 문자열 (*ptrArray[1]) = %s\n\n", *ptrArray);
  printf("ptrptr의 주소 (&ptrptr) = %d", )
}
```
# 03 구조체

## example_12 - structure
```c
#include <stdio.h>

int main(void)
{
  struct employee {
    char name[10];
    int year;
    int pay;
  };
  struct employee A = { "이진호", 2014, 4200};
  struct employee B = { "이한영", 2015, 3300};
  struct employee C = { "이상원", 2015, 3500};
  struct employee D = { "이상범", 2016, 2900};
  printf("이름: %s\n입사: %d\n연봉: %d\n\n", A.name, A.year, A.pay);
  printf("이름: %s\n입사: %d\n연봉: %d\n\n", B.name, B.year, B.pay);
  printf("이름: %s\n입사: %d\n연봉: %d\n\n", C.name, C.year, C.pay);
  printf("이름: %s\n입사: %d\n연봉: %d\n\n", D.name, D.year, D.pay);
  return 0;
}
```
## example_13 - 화살표 연산자 -- fix Sptr->name
```c
#include <stdio.h>

int main(void)
{
  
  struct employee {
    char name[10];
    int year;
    int pay;
  };
  
  struct employee A;
  struct employee *Sptr = &A;
  //Sptr->name = "이순신";
  Sptr->year = 2015;
  Sptr->pay = 5900;
  
  printf("이름: %s\n입사: %d\n연봉: %d\n\n", Sptr->name, Sptr->year, Sptr->pay);
  return 0;
}
```
# 04 동적메모리 할당

## example_14
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *pi;
  
  pi = (int*)malloc(sizeof(int));
  
  if(pi == NULL)
  {
    printf("동적 메모리 할당 오류\n");
    exit(1);
  }
  *pi = 100;
  printf("%d\n", *pi);
  
  free(pi);
  return 0;
}
```
## 중간 점검
- 프로그램의 실행 도중에 메모리를 할당받아서 사용하는것을 동적할당 이라고 한다.

- 동적으로 메모리를 할당받을 때 사용하는 대표적인 함수는 malloc이다.

- 동적으로 할당된 메모리를 해제하는 함수는 free 이다.

- 동적 메모리 함수의 원형은 헤더파일 stdlib.h에 정의되어 있다.

## example_15
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *pc = NULL;
  
  pc = (char *)malloc( sizeof(char));
  if(pc == NULL)
  {
    printf("메모리 할당 오류\n");
    exit(1);
  }
  *pc ='m';
  printf("*pc = %c\n", *pc);
  free(pc);
  
  return 0;
}
```
## example_16 - fix
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *pc = NULL;
  int i =0;
  pc = (char *)malloc(100*sizeof(char));
  if(pc == NULL)
  {
    printf("메모리 할당 오류\n");
    exit(1);
  }
  for(i =0;i<2;i++)
  {
    *(pc+i)='a'+i;
  }
  *(pc+i)=0;
  
  printf("%s\n", pc);
  free(pc);
  return 0;
}
```
## example_17
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *pi;
  
  pi = (int *)malloc(5 * sizeof(int));
  
  if(pi == NULL){
    printf("메모리 할당 오류\n");
    exit(1);
  }
  
  pi[0] = 100;
  pi[1] = 200;
  pi[2] = 300;
  pi[3] = 400;
  pi[4] = 500;
  
  free(pi);
  return 0;
}
```
## example_18 ---- fix
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  struct Book *p;
  p = (struct Book *)malloc(2 * sizeof(struct Book));
  
  if(p == NULL){
    printf("메모리 할당 오류\n");
    exit(1);
  }
  
  p->number = 1;
  strcpy(p->title,"C Programming");
  (p+1)->number = 2;
  strcpy((p+1)->title,"Data Structure");
  
  free(p);
  return 0;
}
```
## 중간 점검

- 동적 할당 후에 메모리 블록을 초기화하여 넘겨주는 함수는 calloc이다.

- 할당되었던 동적 메모리의 크기를 변경하는 함수는 realloc이다.

- 동적 메모리 할당에서의 단위는 byte이다.

- malloc()이 반호나하는 자료형은 int 이다.
# 05 재귀호출
## example_19
```c
//#iifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
#include <stdio.h>
#include <stdlib.h>

void TowerOfHanoi(int n, char x, char y, char z) {
  if (n>0)
  {
    TowerOfHanoi(n-1, x, z, y);
    printf("\n%c -> %c", x, y);
    TowerOfHanoi(n-1, z, y, x);
  }
}
int main(){
  int n;
  printf("\nEnter number of plates: ");
  scanf("%d", &n);
  TowerOfHanoi(n, 'A', 'B', 'C');
  printf("\n");
  getchar();
  return 0;
}
```
