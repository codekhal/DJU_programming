#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

int binarySearch_Rep(int A[], int left, int right, int X) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (X == A[mid]) {
			return mid;
		}
		else if (X < A[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return 0;
}

int binarySearch_Rec(int A[], int left, int right, int X) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (X == A[mid]) {
			return mid;
		}
		else if (X < A[mid]) {
			return binarySearch_Rec(A, left, mid - 1, X);
		}
		else {
			return binarySearch_Rec(A, mid + 1, right, X);
		}
		return 0;
	}
}

int main() {
	int A[] = { 1, 3, 7, 9, 11, 13, 15, 17, 19, 21, 23 }, X = 15;
	int posX;

	posX = binarySearch_Rep(A, 0, 10, X);
	printf("repetition: position(%d) = %d\n", X, posX);
	getchar();

	posX = binarySearch_Rec(A, 0, 10, X);
	printf("recursion: position(%d) = %d\n", X, posX);
	getchar();

	return 0;
}

