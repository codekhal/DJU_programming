# 249p
## 02
```c
#include <stdio.h>

int main(void)
{
  float input, pound;
  scanf("%f", &input);
  printf("%.3f", 0.53592*input);
}
```
## 03
```c
#include <stdio.h>

int main(void)
{
  float i;
  scanf("%f", &i);
  printf("%.3f", 30.48*i);
}
```

## 06
```c
#include <stdio.h>

int main(void)
{
  int inn, cal1, cal2, cal3, cal4, cal5;
  scanf("%d", &inn);
  cal1 = (inn - inn % 10000) / 10000;
  printf("%d만\n", cal1);
  
  cal2 = ((inn % 10000) - inn % 100)/1000;// - (inn - inn % 1000);  
  printf("%d천", cal2);
  cal3 = ((inn % 1000) - inn % 10)/ 100;
  printf("%d백", cal3);
  cal4 = ((inn % 100) - inn % 1) / 10;
  printf("%d십", cal4);
  cal5 = inn % 10;
  printf("%d입니다", cal5);
  //cal3 = (cal2*1000 - (inn - inn % 100)) / 100;
  //printf("%d백", cal3);
  
}
```

## 08
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

## 03
```c
#include <stdio.h>

int main(void)
{
  float bmi, kg, m;
  scanf("%f %f", &kg, &m);
 
  m = m/100;
  bmi = m * m;
  bmi = bmi / kg;
  printf("%.1f", bmi* 1000);
}
```

## 08
```c
#include <stdio.h>

int main(void)
{
  int i, j;
  scanf("%d %d ", &i, &j);
  if (i > 0)
  {
    if ( j > 0)
    {
      printf("%d", i + j);
    }
    else if( j <= 0)
      printf("%d", i - j);
  }
  else if(i <= 0)
  {
    if(j > 0)
    
        {
            printf("%d", -i + j);
        }
    else if ( j <= 0)
        {
        printf("%d", -i - j);
        }
    
  }
}
```

# 09
```c
#include <stdio.h>

int main(void)
{
  int i;
  scanf("%d", &i);
  if( 0 < i < 4)
    printf("1사분기");
  else if( 3< i < 7)
    printf("2사분기");
  else if( 6< i < 10)
    printf("3사분기");
  else if( 9< i<13)
    printf("4사분기");
}
```
