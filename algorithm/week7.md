```c
#include <stdio.h>

int main(void)
{
  int n[10];
  //A=65
  int count = 1;
  for(int i = 0; count < 10; i++)
  {
    n[count] = 65+i;
    printf("%d %c\n", count, n[count]);
    count = count * 2;
  }
  
}
// 1 3 7 15 - 배열 최소 15+1은 잡아야함 <- 오른쪽 치우침

```
http://web.skhu.ac.kr/~mckim1/Lecture/DS/dna/class10/class10_03.html
