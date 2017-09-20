#include <stdio.h>
#define PI 3.14

int main(void)
{
	double input = 7.58;
	printf("면적:%lf\n", input*input*PI);
	printf("둘레공식:%lf\n", 2 * PI*input);

}