 포인터 변수
 포인터 주소 변수
  
  1. int *p; - 주소 변수 선언
  int x;
  2. p = &x; -x 의 주소를 p에 연결
  3. *p - 주소 값 내용물 
## ppt 자료 

```c
#include <stdio.h>

int main(void)
{
  int i = 3000;
  int *p;
  p = &i;
  
  printf("i = %d\n", i);
  printf("&i = %d\n", &i);
  
  printf("p = %u\n", p);
  printf("*p = %d\n", *p);
  return 0;

}
```
```c
#include <stdio.h>

int main(void)
{
  int x = 10, y = 20;
  int *p;
  
  p = &x;
  printf("p = %d\n", p);
  printf("p = %d\n\n", *p);
  
  p = &y;
  printf("p = %d\n", p);
  printf("p = %d\n\n", *p);
  
  return 0;
}
```
```c
#include <stdio.h>

int main(void)
{
  int i =10;
  int *p;
  
  p = &i;
  printf("i = %d\n", i);
  
  *p = 20;
  printf("i = %d\n", i);
  return 0;
}
```
```c
#include <stdio.h>

int main(void)
{
  char *pc;
  int *pi;
  double *pd;
  // 주소를 같게 한 이유 -> 원래는 이렇게 하면 안되지만 결과의 차이를 확실하게 보기 위해서
  pc = (char *)10000;
  pi = (int *)10000;
  pd = (double *)10000;
  printf("증가 전 pc = %d, pi = %d, pd = %d\n", pc, pi, pd);
  
  pc++;
  pi++;
  pd++;
  printf("증가 후 pc = %d, pi = %d, pd = %d\n", pc, pi, pd);
  
  printf("pc+2 = %d, pi+2 = %d, pd+2 = %d\n", pc+2, pi+2, pd+2);
  
  return 0;
}
```
```c
//배열과 포인터를 연결함
#include <stdio.h>

int main(void)
{
  int a[] = {10, 20, 30, 40, 50};
  printf("&a[0]=%u\n", &a[0]);
  printf("&a[1]=%u\n", &a[1]);
  printf("&a[2]=%u\n", &a[2]);
  
  printf("a = %u\n", a);
  printf("a = %u\n", a+1);
  printf("a = %u\n", a+2);
  
  return 0;
}
```
```c
#include <stdio.h>

int main(void)
{
  int a[] = {10, 20, 30, 40, 50};
  
  printf("%d\n", *(a));
  printf("%d\n", *(a+1));
  printf("%d\n", *(a+2));
  printf("%d\n", *(a+3));
  printf("%d", *(a+4));
  
  return 0;
}
```
```c
// call by reference / call by value
#include <stdio.h>
void swap(int *px,int *py)
{
  int tmp;
  
  tmp = *px;
  *px = *py;
  *py = tmp;
  
}

int main(void)
{
  int a = 100;
  int b = 200;
  
  int *px = &a;
  int *py = &b;
  
  swap(&a, &b);
  printf("%d %d", a, b);
}
```
숙제 : 8장 9장 10장 읽은거 표시해오기
짧은 시간 내에 코드 풀어서 제출 테스트 -- ppt 자료 공부
