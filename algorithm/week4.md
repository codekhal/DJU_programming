# Algorithm 수업 3주차 과제

```
교수님의  : n을 테이터 개수로 바꿔가면서 나온 결과를 그래프형태로 표현한 후 시간차이가 나는 이유를 서술해야 함.
```
## 01. 각 정렬의 시간복잡도 시각화

<과정>

시간복잡도를 시각화 하기위해 아래와 같이 제 나름대로 코드를 수정하는 과정을 거쳤습니다.

입력된 데이터량에 따라 어느정도의 시간이 걸렸는지를 확인하기 위해서

교수님의 예제코드를 참고하여 

```c
printf("Enter the number of numbers to generate: ");
scanf("%d", &n);

if(n<1||n>MAX_SIZE){
  fprintf(stderr, "Improper value of n\n");
  exit(1);
}
```

```c
clock_t start, stop;
start = clock(); function(A, n); stop=clock();
```

위와같은 코드를 병합정렬, 퀵정렬에 적용하였습니다.

또한 정렬의 특성상 

1. 주어진 범위의 수가 모두 있어야 하고 

2. 수가 중복되면 안된다는 조건을 만족해야 했기 때문에

```c
for(i=0; i<n;i++)
  a[i] = i+1;
```
```c
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

<!! mergeSort2와 insertion 정렬의 시간복잡도는 여러 시도를 해보았지만 다른 정렬이 측정가능한 범위에서 시간측정을 할 수 없었습니다. <->

## 02. 그래프 분석 및 이유 설명

### 선택정렬(Selection Sort)

앞의 그래프를 확인해보면 2차함수의 형태를 띄고 있는걸 알 수 있습니다. 

선택정렬은 현재 위치에 들어갈 값을 찾아 정렬하는 배열입니다. 알고리즘의 구조는

1. 정렬되지 않은 인덱스의 맨 앞에서 부터, 이를 포함한 그 이후의 배열값 중 가장 작은 값을 찾아간다
(정뎔되지 않은 인덱스의 맨 앞은, 초기 입력에서는 배열의 시작위치일 것이다.)
2. 가장 작은 값을 찾으면, 그 값을 현재 인덱스의 값과 바꿔준다.
3. 다음 인덱스에서 위 과정을 반복해준다.

이렇게 n-1개, n-2개, ..., 1개씩 비교를 반복하는 형식입니다.
다시말해 for문이 중첩되어 있는 형태와 같기 때문에 시간복잡도를 O(n^2)라 볼 수 있습니다.

### 버블정렬(Bubble Sort)

앞의 그래프를 확인해보면 2차함수의 형태를 띄고 있는걸 알 수 있습니다.

버블정렬은 연속된 두개의 인덱스를 비교하여, 정한 기준의 값을 뒤로 넘겨 정렬하는 방법입니다.

오름차순으로 정렬하고자 할 경우, 비교시마다 큰값이 뒤로 이동하도록 하면 됩니다

따라서 맨 마지막에 비교하는 수들 중 가장 큰 값이 저장되기 때문에

(전체배열크기 - 현재까지 순환한 바퀴수)만큼 반복해 주면 됩니다.

알고리즘의 구조는

1. 현제 인덱스 값과, 바로 이전의 인덱스 값을 비교한다.
2. 만약 이전 인덱스가 더 크면, 현재 인덱스와 바꿔준다.
3. 현재 인덱스가 더 크면, 교환하지 않고 다음 두 연속된 배열값을 비교한다.
4. 이를 (전체 배열의 크기 - 현재까지 순환한 바퀴수)만큼 반복한다.

이렇게 1부터 비교를 시작하여, n-1개, n-2개, ..., 1개씩 비교를 반복하는 형식입니다.

전체비교를 진행하는데 for문이 중첩된 것과 같으므로 시간복잡도는 O(n^2)라 볼 수 있습니다.

### 합병정렬(Merge Sort) <- 분할 정복(Divide and conquer)방식으로 설계됨

위의 그래프를 확인해 보면 그래프상으로는 선택정렬이나 버블정렬보다 기울기가 높아보이지만 

선택정렬, 버블정렬의 그래프는 걸린 시간의 축의 최대값이 6이고 합병정렬은 1.5이므로 실질적으론 기울기가 더 완만하다는걸 알 수 있습니다.

합병정렬은 입력으로 하나의 배열울 받고, 연산 중에 두개의 배열로 계속 쪼개 나간 뒤 하나로 합치게 됩니다.

합병을 하게되면 두 개의 배열을 비교하여, 기준에 맞는 값을 다른 배열에 저장해 나갑니다.

오름차순의 경우 배열 A, 배열 B를 비교하여 A에 있는 값이 더 작다면 새 배열에 저장해주고, A 인덱스를 증가시킨 후 A,B의 반복을 진행하게 됩니다.

이는 A나 B중 하나가 모든 배열값들을 새 배열에 저장할 때 까지 반복하며, 전부 다 저장하지 못한 배열의 값들은 모두 새 배열의 값에 저장해줍니다.

분할 과정의 알고리즘 구조는 아래와 같습니다.

1. 현재 배열을 반으로 쪼갠 뒤 배열의 시작위치와, 종료 위치를 입력받아 둘을 더한 후 2를 나눠 그 위치를 기준으로 나눈다.
2. 이를 쪼갠 배열의 크기가 0이거나 1일 때 까지 반복한다.

합병 과정의 알고리즘 구조는 아래와 같습니다.
1. 두 배열 A,B의 크기를 비교한다. 각각의 배열의 현재 인덱스를 i,j로 가정하자.
2. i에는 A배열의 시작 인덱스를 저장하고, j에는 B배열의 시작 주소를 저장한다.
3. A[i]와 B[j]를 비교한다. 오름차순의 경우 이중에 작은 값을 새 배열 C에 저장한다.
A[i]가 더 컸다면 A[i]의 값을 배열 C에 저장해주고, i의 값을 하나 증가시켜준다.
4. 이를 i나 j 둘 중 하나가 각자 배열의 끝에 도달할 때 까지 반복한다.
5. 끝까지 저장을 못한 배열의 값을, 순서대로 전부 다 C에 저장한다.
6. C 배열을 원래의 배열에 저장해준다.

이렇듯 분할과 합병과정이 나눠지게 됩니다.

합병과정은 두 배열 A,B를 정렬하기 때문에 A배열의 크기를 N1, B배열의 크기를 N2라고 할 경우 O(n1+n2)와 같습니다.
배열 A와 배열 B는 하나의 배열을 나눈 배열들이기 때문에 전체 배열의 길이가 N이라 할 경우
N = N1 + N2이므로 O(N)이라고 할 수 있습니다.

분할과정은 logN만큼 일어나는데, 이유는 간단합니다. 크기가 N인 배열을 분한할면, N/2 2개, 그다음으로 분할하면, N/4 4개처럼 매번 반씩 감소하므로 logN만큼 반복해야 크기가 1인 배열로 분할 할 수 있습니다.

각 분할별로 합병을 진행하므로, 합병정렬의 시간복잡도는 O(NlogN)입니다.

### 퀵소트(Quick sort) <- 분할정복(Divide and conquer)

퀵정렬은 pivot point라고 기준이 되는 값을 하나 설정하게 됩니다. 이 값을 기준으로 작은값은 왼쪽, 큰값은 오른쪽으로 옮기는 방식으로 정렬을 진행합니다.

이를 반복하여 분할된 배열의 크기가 1이되면 배열이 모두 정렬 된 것입니다.

퀵소트의 알고리즘 구조는 아래와 같습니다.

1. pivot point로 잡을 배열의 값 하나를 정합니다. 보통 맨 앞이나 맨 뒤, 혹은 전체 배열값 중 중간값이나 랜덤값으로 정합니다.
2. 분할을 진행하기에 앞서, 비교를 진행하기 위해 가장 왼쪽 배열의 인덱스를 저장하는 left 변수, 가장 오른쪽 배열의 인덱스를 저장한 right변수를 생성합니다.
3. right부터 비교를 진행하고 비교는 right가 left보다 클 때만 반복하며, 비교한 배열값이 pivot point보다 크면 right하나를 감소시키고 비교를 반복합니다.
4. 그 다음 left부터 비교를 진행합니다. 비교는 right가 left보다 클 때만 반복하며, 비교한 배열값이 pivot point보다 작으면 left를 하나 증가시키고 비교를 반복합니다.
5. left인덱스의 값과 right 인덱스의 값을 바꿔줍니다.
6. 3,4,5 과정을 left<right가 만족 할 때 까지 반복합니다.
7. 위 과정이 끝나면 left의 값과 pivot point를 바꿔줍니다.
8. 맨 왼쪽부터 left-1까지, left+1부터 맨 오른쪽까지로 나눠 퀵 정렬을 반복합니다.

퀵 정렬은 분할과 동시에 정렬을 진행하는 알고리즘 입니다.
각 정렬은 배열의 크기 N만큼 비교하여, 이를 총 분할 깊이인 logN만큼 진행하므로 총 비교횟수는 NlogN, 즉 시간복잡도는 O(NlogN)입니다.
다만 퀵 정렬에 worstcase가 존재하는데 이는 배열이 이미 정렬되어 있는 경우입니다. 이 경우 분할이 N만큼 일어나므로 시간복잡도는 O(N^2)입니다.

wortcase 때문에 합병 정렬보다 느린 알고리즘이라 생각하기 쉽지만, 발생하기 쉽지 않은 경우이고 일반적으로 퀵정렬이 합병정렬보다 20%이상 빠르다고 합니다.

!! NlogN의 시간복잡도를 가지는 정렬은 Count, Radix등이 있다.

## 03. 소스코드

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

## 04. 확인해보면 좋은 사이트

https://www.toptal.com/developers/sorting-algorithms/


