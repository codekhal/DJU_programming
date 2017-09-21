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
