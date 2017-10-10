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

int main(void)
{
  char inp[100];
  int nu;
   char tmp;
   scanf("%d", &nu);
   scanf("%s", inp);
   
   /*
   int rev = nu - 1;

   for(int j = 0; j < nu; j++)
   {
         tmp = inp[j];
         inp[j] = inp[rev];
         inp[rev] = tmp;
         rev--;
   }
*/

   for(int k = nu-1; k >=0; k--)
      printf("%c", inp[k]);


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
# 프로젝트
## 01
```c
#include <stdio.h>
//#include <stdlib.h>
int main(void)
{
  int unit_in, unit_out;
  float value;
  char unit[4] = {'m', 'i','f', 'y'};
  float calc[4][4] ={ {1, 39.3701, 3.28084, 1.09361}, {0.0254, 1, 0.0833333, 0.0277778},
  {0.3048, 12, 1, 0.333333}, {0.9144, 36, 3, 1}}; 

  do{
    do{
      printf("1.m / 2.in / 3.ft / 4.yd");
      scanf("%d", &unit_in); 
      if(unit_in == 0)
        return 0;
    }while(unit_in > 4 || unit_in < 1);
    do{
      printf("1.m / 2.in / 3.ft / 4.yd");
      scanf("%d", &unit_out);
      if(unit_out == 0)
        return 0;
    }while(unit_out > 4 || unit_out < 1);
    printf("plz input value data: ");
    scanf("%f", &value);
    if(value == 0)
      break;
    for(int i = 1; i < 5; i ++)
    {
      if(unit_in == i)
      {
        if(unit_out == 1)
          printf("%c -> m: %f\n", unit[i-1], value*calc[i][1]);
        else if(unit_out == 2)
          printf("%c -> in: %f\n", unit[i-1], value*calc[i][2]);
        else if(unit_out == 3)
          printf("%c -> ft: %f\n", unit[i-1], value*calc[i][3]);
        else if(unit_out == 4)
          printf("%c -> yd: %f\n", unit[i-1], value*calc[i][4]);
      }
    }
  }while(1);
  return 0;
}
```
