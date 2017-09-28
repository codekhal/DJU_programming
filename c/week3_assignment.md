# 02
```c
#include <stdio.h>

int main(void)
{
  float input, pound;
  scanf("%f", &input);
  printf("%.3f", 0.53592*input);
}
```
# 03
```c
#include <stdio.h>

int main(void)
{
  float i;
  scanf("%f", &i);
  printf("%.3f", 30.48*i);
}
```

# 06

# 08
```c
#include <stdio.h>

int main(void)
{
  int i , j ,k;
  scanf("%d %d %d", &i, &j, &k);
  if (i > j)
  {
    printf("%d", (i > k) ? i : k); 
  }
  else
  {
    printf("%d", (j > k) ? j : k);
  }
}
```

# 292p

## 08

#include <stdio.h>
#include <stdlib.h>
//int by(int i);
/*
int main(void)
{
  //int* arr;
  //input = (int*)malloc(arr);
  int arr[8];
  int input;
  scanf("%d", &input);
  for (int i = 0;  i < 8; i++)
  {
    arr[i] = input - (input % by(i));
  }
  for (int i = 1; i < 5; i++)
  {
    printf("%d\n", arr[i]);
  }
  
}
*/
int by(int i)
{
  int i;
  int by;
  by = 1;
  scanf("%d", &i);
  for(int j = 0; j < i; j++)
  {
    by = 10* by;
  }
  return by;
}
