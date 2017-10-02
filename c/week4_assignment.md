# 344_345p
## 02
```c
#include <stdio.h>

int main(void)
{
  int i, j, k;
  for(i = 5; i>0; i--)
  {
    for(k = i; k > 0; k--)
      printf(" ");
    for(j = 6-i; j > 0; j--)
      printf("%d", j);
    printf("\n");
  }
  return 0;
}
```
## 03
```c
#include <stdio.h>

int main(void)
{
  int i, sum;
  sum = 0;
  scanf("%d", &i);
  for(int j = 1; j <= i; j++)
    sum += j;
  printf("%d", sum);
  return 0;
}
```
## 07 <- 
```c
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  char inp[10];
  int count = 0;
  int length = 0;
  scanf("%s", &inp);
  int i = 1;
  do{
    if (inp[i] == NULL)
      length += 1;
    else
      count += 1;
  }while(i < 10);
  //printf("%d %d", length, count);
  for(int j = 0; j < count+1; j++)
  {
    printf("%c", inp[count-j]);
  }
  return 0;
}
```
## 13
```c
#include <stdio.h>

int main(void)
{
  int sum = 0;
  int i;
  for(i = 1; i < 1000; i++)
    if (sum < 10000)
      sum += i;
    else
      break;
  printf("%d %d", i-1, sum-i);
}
```
