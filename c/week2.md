# 연습문제 풀이 162p

# 02
```c
#include <stdio.h>

int main(void)
{
	printf("%x\n", 47);
	printf("%d\n", 0x3df);
}
```

# 06
```c
#include <stdio.h>

int main()
{
	int p_1 = 95;
	int p_2 = 84;
	int total = 0;

	total = p_1 + p_2;
	printf("%d",total);
    return 0;
}

```

# 07
```c
#include <stdio.h>

int main(void)
{
	int p_1 = 95;
	int p_2 = 84;
	int total=0;
	int avg_1 = 0;
	float avg_2 = 0;
	total = p_1 + p_2;
	printf("ÇÕ:%d\n", total);
	avg = total/2;
	avg2 =total/2.0;
	printf("Á¤¼ö Æò±Õ:%d\n", avg_1);
	printf("½Ç¼ö Æò±Õ:%f\n", avg_22);
}
```

# 09
```c
#include <stdio.h>
#define PI 3.14

int main(void)
{
	double input = 7.58;
	printf("¸éÀû:%lf\n", input*input*PI);
	printf("µÑ·¹°ø½Ä:%lf\n", 2 * PI*input);

}
```

# 11
```c
#include <stdio.h>

int main(void)
{
	int i;	//순환 변수
	int input[4] = { 10,50,80,100};	//책에 있던입력값
	int output=0;
	for (i = 0; i < 4; i++)
	{
		output = 5.0 / 9.0*(input[i] - 32.0);
		printf("%d 의 섭씨온도는:%d입니다.\n",input[i],output);
	}

}
```

# 13
```c
#include<stdio.h>

int main(void)
{
	printf("\a");	//비프음 발생
	printf("수업시간입니다.\n");
}
```
