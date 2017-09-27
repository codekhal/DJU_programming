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
