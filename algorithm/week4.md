## selectionSort.c
```c
//1.selectionSort.c
//Sorting Algorithms(selection, bubble, insertion) - O(n^2)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 10001
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define TRUE 1
#define FALSE 0
void selectionSort(int[], int);
void bubbleSort1(int[], int);
void bubbleSort2(int[], int);
void insertionSort(int[], int);

int main(void)
{
  int i, n;
  clock_t start, stop;
  double duration;
  int A[MAX_SIZE];
  printf("Enter the number of numbers to generate: ");
  scanf("%d", &n);
  if(n<1||n>MAX_SIZE){
    fprintf(stderr, "Improper value of n\n");
    exit(1);
  }
  start = clock();
  selectionSort(A,n);stop=clock();
  duration = ((double)(stop-start))/CLK_TCK;
  printf("\n Sorted Array:\n");
  for(i=0;i<n;i++)
    printf(" %d", A[i]);
  printf("\n");printf("time elapsed in selection sorting: %f\n", duration);
  getchar(); getchar();
  start = clock(); bubbleSort1(A, n); stop=clock();
  duration = ((double)(stop - start)) / CLK_TCK;
  printf("\n Sorted Array:\n");
  for(i = 0; i<n; i++)
    printf(" %d", A[i]);
  printf("\n"); printf("time elapsed in bubble sorting 1: %f\n", duration);
  getchar();
  start = clock(); bubbleSort2(A,n); stop=clock();
  duration = ((double)(stop-start))/CLK_TCK;
  printf("\n Sroted Array:\n");
  for(i = 0; i <n; i++)
    printf(" %d", A[i]);
  printf("\n"); printf("time elapsed in bubble sorting 2: %f\n", duration);
  getchar();
  
  start = clock(); insertionSort(A, n); stop = clock();
  duraton=((double)(stop-start))/CLK_TCK;
  printf("\n Sorted Array:\n");
  for(i = 0; i<n; i++)
    printf(" %d", A[i]);
  printf("\n");  printf("time elapsed in insertion sorting: %f\n", duration);
  getchar();
  return 0;
}
void selectionSort(int A[], int n){
  int i, j, max, temp;
  for(i = n-1; i>0; i--){
    max = i;
    for(j = 0; j<i; j++){
      if(A[j] >A[max])
        max = j;
    }
    SWAP(A[i], A[max], temp);
  }
}
void bubbleSort1(int A[], int n){
  int i, j, temp;
  for(i = n-1; i>0; i--){
    for(j = 0; j <i; j++){
      if(A[j] >A[j+1]){
        SWAP(A[j],A[j+1], temp);
      }
    }
  }
}
void bubbleSort2(int A[], int n){
  int i, j, temp, sorted;
  for(i = n-1; i>0;i--){
    sorted = TRUE;
    for(j = 0; j<i; j++){
      if(A[j]>A[j+1]){
        SWAP(A[j],A[j+1],temp);
        sorted = FALSE;
      }
    }
    if(sorted = TRUE)
    return ;
  }
}
void insertionSort(int A[], int n){
  int i, loc, newItem;
  for(i=1;i<n;i++){
    loc = i-1;
    newItem = A[i];
    while(loc>=0&&newItem<A[loc]){
      A[loc+1]=A[loc];
      loc--;
    }
    A[loc+1]=newItem;
  }
}
```
## 병합정렬.c
```c
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void merge(int a[], int left, int mid, int right){
  int sorted[MAX_SIZE];
  int left1 = left, left2 = mid + 1;
  int i = left, j;
  while (left1 <= mid && left2<= right) {
    if(a[left1] <= a[left2]){
      sorted[i] = a[left1];
      i++, left1++;
    }
    else{
      sorted[i] = a[left2];
      i++, left2++;
    }
  }
  if(i<=right){
    if(left1<=mid){
      for(j = left1; j<=mid; j++){
        sorted[i] = a[j];
        i++;
      }
    }
    else if(left2 <= right){
      for(j = left2; j<=right; j++){
        sorted[i] = a[j];
        i++;
      }
    }
  }
  for(i = left; i<= right; i++) a[i] = sorted[i];
}
void merge_sort(int a[], int left, int right){
  int mid;
  if(left<right) {
    mid = (left + right) /2;
    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    merge(a, left, mid, right);
  }
}
int arr_size(int a[]){
  int i =0, count =0;
  while(a[i] != 0){
    count++; i++;
  }
  return count;
}
int main(){
  int a[MAX_SIZE] = {15,21,3,12,15,7,32,4,25,9,18,1,2,5,100,150};
  int i, arrN;
  arrN = arr_size(a);
  printf("before..");
  for(i = 0; i < arrN; i++) printf("%d\t", a[i]);
  printf("\n\n\n");
  printf("after..mergeSort");
  merge_sort(a, 1, arrN -1);
  for(i=0;i<arrN;i++)printf("%d\t", a[i]);
  printf("\n\n\n");
  getchar();
  return 0;
}
```
## 퀵정렬.c
```c
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void swap(int *n1, int *n2){
  int t;
  t = *n1;
  *n1 = *n2;
  *n2 = t;
}
void partition(int a[], int left, int right, int *pivot_index){
  int pivot = a[left];
  int i = left +1, j = right;
  do{
    while(i<=right&&a[i]<pivot)i++;
    while(j>=left&&a[j]>pivot)j--;
    if(i<j)swap(&a[i],&a[j]);
  }while(i<j);
  swap(&a[left],&a[j]);
  *pivot_index = j;
}
void quick_sort(int a[], int left, int right){
  int pivot_index =0;
  if(right > left){
    partition(a, left, right, &pivot_index);
    quick_sort(a, left, pivot_index - 1);
    quick_sort(a, pivot_index + 1, right);
  }
}
int arr_size(int a[]){
  int i = 0, count = 0;
  while(a[i] != 0){
    count++; i++;
  }
  return count;
}
int main(){
  int a[MAX_SIZE] = {15, 21, 3, 12, 15, 7, 32, 4, 25, 9, 18, 1, 2, 5, 100, 150};
  int i, arrN;
  arrN = arr_size(a);
  printf("before..");
  for(i=0;i<arrN;i++)printf("%d\t",a[i]);
  printf("\n\n\n");
  printf("after..quickSort");
  quick_sort(a,1,arrN-1);
  for(i=0;i<arrN;i++)printf("%d\t",a[i]);
  printf("\n\n\n");
  getchar();
  return 0;
}
```
