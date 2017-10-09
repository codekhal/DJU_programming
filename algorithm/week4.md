# Algorithm 수업 3주차 과제

```
교수님이 원하는 것 : n을 테이터 개수로 바꿔가면서 나온 결과를 그래프형태로 표현한 후 시간차이가 나는 이유를 서술해야 함.
```
## 01. 각 정렬의 시간복잡도 시각화

<과정>

시간복잡도를 시각화 하기위해 아래와 같이 제 나름대로 코드를 수정하는 과정을 거쳤습니다.

입력된 데이터량에 따라 어느정도의 시간이 걸렸는지를 확인하기 위해서

교수님의 예제코드를 참고하여 

```
printf("Enter the number of numbers to generate: ");
scanf("%d", &n);

if(n<1||n>MAX_SIZE){
  fprintf(stderr, "Improper value of n\n");
  exit(1);
}
```

```
clock_t start, stop;
start = clock(); function(A, n); stop=clock();
```

위와같은 코드를 병합정렬, 퀵정렬에 적용하였습니다.

또한 정렬의 특성상 1. 주어진 범위의 수가 모두 있어야 하고 2. 수가 중복되면 안된다는 조건을 만족해야 했기 때문에

```
for(i=0; i<n;i++)
  a[i] = i+1;
```
```
void ShufflingNumber( )
{
    int A[n];
    for( int i=0; i < n; ++i )
        A[i] = i+1;

    // 셔플링(20번 섞는다)
    for( int i=0; i < 20; ++i )
    {
        int src = rand() % n;
        int dest = rand() % n;

        int temp = A[src];
        A[src] = A[dest];
        A[dest] = temp;
    }

    for(int i=0; i < n; ++i )
        printf( "%d ", A[i] );

    printf("\n");
}
출처: http://p7kell.wikidot.com/1-n-random-number-shuffling
```

와 같이 조건을 만족시킬 수 있는 코드를 삽입하였습니다.

코드가 제대로 작동한다는 것을 확인한 뒤

for문을 적용하여 결과값을 출력하는데 필요없는 printf를 주석처리하여 아래와 같은 결과를 얻었습니다.

![6 selection_sort](https://user-images.githubusercontent.com/16266103/31339323-7e694c20-ad3d-11e7-80f9-128feb8acdc1.PNG)
![7 bubble_sort](https://user-images.githubusercontent.com/16266103/31339324-7e969806-ad3d-11e7-8a5e-8c55642b6101.PNG)
![8 merge_sort](https://user-images.githubusercontent.com/16266103/31339325-7ed6b8a0-ad3d-11e7-8603-26b299e4dd1c.PNG)
![9 quick_sort](https://user-images.githubusercontent.com/16266103/31339387-ac8c96ac-ad3d-11e7-9ea3-bf005ecfedd6.PNG)
![0 data_of_sort](https://user-images.githubusercontent.com/16266103/31339416-c1500c4a-ad3d-11e7-83d0-8ce9c3170d63.PNG)

이를 그래프로 표현하면 아래와 같습니다.

![1 all_sort](https://user-images.githubusercontent.com/16266103/31339429-d06f76e8-ad3d-11e7-87c8-4c51c895545c.PNG)
![2 selection_sort](https://user-images.githubusercontent.com/16266103/31339428-d03cf146-ad3d-11e7-87eb-7ff570fa1eed.PNG)
![3 bubble_sort](https://user-images.githubusercontent.com/16266103/31339426-cfcfd1ce-ad3d-11e7-8add-d58a56a9b6e5.PNG)
![4 merge_sort](https://user-images.githubusercontent.com/16266103/31339427-cffc7cce-ad3d-11e7-84b9-176d6b7745b9.PNG)
![5 quick_sort](https://user-images.githubusercontent.com/16266103/31339505-0530b842-ad3e-11e7-93a5-2445206c1300.PNG)

!! mergeSort2와 insertion의 시간복잡도는 여러 시도를 해보았지만 다른 정렬이 측정가능한 범위에서 시간측정을 할 수 없었습니다. <-



### selectionSort.c
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
### 병합정렬.c
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
### 퀵정렬.c
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
## 
