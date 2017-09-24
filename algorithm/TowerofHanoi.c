#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

void TowerOfHanoi(int n, char x, char y, char z) {
	if (n > 0)
	{
		TowerOfHanoi(n - 1, x, z, y);
		printf("\n%d -> %c", x, y);
		TowerOfHanoi(n - 1, z, y, x);
	}
}

int main() {
	int n;
	printf("\nEnter number of plates: ");
	scanf("%d", &n);
	TowerOfHanoi(n, 'A', 'B', 'C');
	printf("\n");
	getchar();
	return 0;
}
