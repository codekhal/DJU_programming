#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void merge(int a[], int left, int mid, int right) {
	int sorted[MAX_SIZE];
	int left1 = left, left2 = mid + 1;
	int i = left, j;
	while (left1 <= mid && left2 <= right) {
		if (a[left1] <= a[left2]) {
			sorted[i] = a[left1];
			i++, left1++;
		}
		else {
			sorted[i] = a[left2];
			i++, left2++;
		}
	}
	if (i <= right) {
		if (left <= mid) {
			for (j = left1; j <= mid; j++) {
				sorted[i] = a[j];
				i++;
			}
		}
		else if (left2 <= right) {
			for (j = left2; j <= right; j++) {
				sorted[i] = a[j];
				i++;
			}
		}
	}
	for (i = left; i <= right; i++) a[i] = sorted[i];
}

void merge_sort(int a[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

int arr_size(int a[]) {
	int i = 0, count = 0;
	while (a[i] != 0) {
		count++;	 i++;
	}
	return count;
}
int main() {
	int a[MAX_SIZE] = { 15, 21, 3, 12, 15, 7, 32, 4, 25, 9, 18, 1, 2, 5, 100, 150 };	
	int i, arrN;
	arrN = arr_size(a);
	printf("before..");
	for (i = 0; i < arrN; i++) printf("%d\t", a[i]);
	printf("\n\n\n");
	printf("after ..mergeSort");
	merge_sort(a, 1, arrN - 1);
	for (i = 0; i < arrN; i++) printf("%d\t", a[i]);
	printf("\n\n\n");
	getchar();
	
	return 0;
}
