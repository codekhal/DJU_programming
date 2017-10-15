# Algorithm 수업 6주차 과제


> 교수님의 요구사항 : 1. getfirst / 2. get last / 3. next node / 4. get count

## 1. 첫번째 노드 구하기(Get First)
```c
void getfirst(linkedList *L){
  linkedNode *curr;
  curr = L->head;
  for(int i = 0; i<1; i++){
    printf("**  get first 연결리스트: %p[%s, %p]\n", curr, curr->data, curr->link);
    curr = curr->link;
  }
}
```
## 2. 마지막 노드 구하기(Get Last)
```c
void getlast(linkedList *L){
  linkedNode *preN, *lastN;
  linkedNode *curr;
  //curr = L->head;
  if(L->head == NULL)
    printf("Empty List\n");
  else if (L->head->link == NULL)
    L->head = NULL;
  else {
    preN = L->head, lastN = preN->link;;
    while(lastN->link != NULL)
      preN = preN->link, lastN = preN->link;
    printf("**  get last  연결리스트: %p[%s, %p]\n", lastN, lastN, lastN->link);
  }
}
```
## 3. 현재의 다음 노드 구하기(Next Node)
```c
void nextnode(linkedList *L){
  linkedNode *curr;
  curr = L->head;
  int count = 0;
  int count_ = 0;
  int input;
  printf("*   노드의 값을 입력해 주세요(1 ~ last)   *");
  while(curr != NULL) {
    //printf("연결리스트: %p[%s, %p]\n", curr, curr->data, curr->link);
    curr = curr->link;
    count++;
  }
  curr = L->head;
  do{
  scanf("%d", &input);
  }while(input > count && input < 0);
  while(curr != NULL) {
    if(input == count_)
      printf("**  %d 번째의 다음 node: %p[%s, %p]\n", input, curr, curr->data, curr->link);
    curr = curr->link;
    count_++;
  }
  printf("\n");
}
```
## 4. 노드의 수 구하기(Get Count)
```c
void getCount(linkedList *L){
  linkedNode *curr;
  curr = L->head;
  int count = 0;
  while(curr != NULL) {
    //printf("연결리스트: %p[%s, %p]\n", curr, curr->data, curr->link);
    curr = curr->link;
    count++;
  }
  printf("**  get count of 연결리스트: %d\n", count);
}
```
## 원본코드.c
```c
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct Node {
	char data[4];
	struct Node *link;
} linkedNode;
typedef struct LinkedList {
	linkedNode *head;
} linkedList;

linkedList *createLinkedList() {
	linkedList *listInstance;
	listInstance = (linkedList *)malloc(sizeof(linkedList));
	listInstance->head = NULL;

	return listInstance;
}
linkedNode *createListNode(char s[]){
	linkedNode *nodeInstance;
	nodeInstance = (linkedNode *)malloc(sizeof(linkedNode));
	strcpy_s(nodeInstance->data, (strlen(s) + 1), s);
	nodeInstance->link = NULL;

	return nodeInstance;
}
//void insertFirstNode(linkedList *L, char s[]){}
void insertLastNode(linkedList *L, char s[]){
  linkedNode *lastN;
  linkedNode *n = (linkedNode *)malloc(sizeof(linkedNode));
  strcpy_s(n->data, (strlen(s) + 1), s);
  n->link = NULL;
  if (L->head==NULL)
    L->head = n;
  else {
    lastN = L->head;
    while(lastN->link != NULL) lastN = lastN->link;
    lastN->link = n;
  }
}
//void deleteFirstNode(linkedList *L) {}
void deleteLastNode(linkedList *L){
  linkedNode *preN, *lastN;
  if(L->head == NULL)
    printf("Empty List\n");
  else if (L->head->link == NULL)
    L->head = NULL;
  else {
    preN = L->head, lastN = preN->link;;
    while(lastN->link != NULL)
      preN = preN->link, lastN = preN->link;
    preN->link = NULL;
  }
}
void reverseLinkedList(linkedList *L){
  linkedNode *prev, *temp, *curr;
  curr = L->head, prev = NULL;
  while(curr != NULL) {
    temp = curr->link;
    curr->link = prev;
    prev = curr;
    curr = temp;
  }
  L->head = prev;
}
void printLinkedList(linkedList *L) {
  linkedNode *curr;
  curr = L->head;
  while(curr != NULL) {
    printf("연결리스트: %p[%s, %p]\n", curr, curr->data, curr->link);
    curr = curr->link;
  }
  printf("\n");
}
int main(){
  //연결리스트 인스턴스(list1) 생성하기
  linkedList *list1 = createLinkedList();
  //리스트(list1)에 노드(n1, n2, n3) 삽입(insert)하기
  insertLastNode(list1, "월");
  insertLastNode(list1, "화");
  insertLastNode(list1, "수");
  insertLastNode(list1, "목");
  insertLastNode(list1, "금");
  insertLastNode(list1, "토");
  insertLastNode(list1, "일");
  //연결리스트 출력하기
  printLinkedList(list1);
  //리버싱 후 출력하기
  reverseLinkedList(list1);
  printLinkedList(list1);
  //연결리스트 삭제하기->출력하기
  for (; list1->head;){
    deleteLastNode(list1);
    printLinkedList(list1);
  }
  getchar();
  return 0;
}
```
## 수정한 코드.c
```c
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct Node {
	char data[4];
	struct Node *link;
} linkedNode;
typedef struct LinkedList {
	linkedNode *head;
} linkedList;

linkedList *createLinkedList() {
	linkedList *listInstance;
	listInstance = (linkedList *)malloc(sizeof(linkedList));
	listInstance->head = NULL;

	return listInstance;
}
linkedNode *createListNode(char s[]){
	linkedNode *nodeInstance;
	nodeInstance = (linkedNode *)malloc(sizeof(linkedNode));
	//strcpy_s(nodeInstance->data, (strlen(s) + 1), s);
	strcpy(nodeInstance->data, s);
	nodeInstance->link = NULL;

	return nodeInstance;
}
//void insertFirstNode(linkedList *L, char s[]){}
void insertLastNode(linkedList *L, char s[]){
  linkedNode *lastN;
  linkedNode *n = (linkedNode *)malloc(sizeof(linkedNode));
  //strcpy_s(n->data, (strlen(s) + 1), s);
  strcpy(n->data, s);
  n->link = NULL;
  if (L->head==NULL)
    L->head = n;
  else {
    lastN = L->head;
    while(lastN->link != NULL) lastN = lastN->link;
    lastN->link = n;
  }
}
//void deleteFirstNode(linkedList *L) {}
void deleteLastNode(linkedList *L){
  linkedNode *preN, *lastN;
  if(L->head == NULL)
    printf("Empty List\n");
  else if (L->head->link == NULL)
    L->head = NULL;
  else {
    preN = L->head, lastN = preN->link;;
    while(lastN->link != NULL)
      preN = preN->link, lastN = preN->link;
    preN->link = NULL;
  }
}
void reverseLinkedList(linkedList *L){
  linkedNode *prev, *temp, *curr;
  curr = L->head, prev = NULL;
  while(curr != NULL) {
    temp = curr->link;
    curr->link = prev;
    prev = curr;
    curr = temp;
  }
  L->head = prev;
}
void printLinkedList(linkedList *L) {
  linkedNode *curr;
  curr = L->head;
  while(curr != NULL) {
    printf("연결리스트: %p[%s, %p]\n", curr, curr->data, curr->link);
    curr = curr->link;
  }
  printf("\n");
}
void getfirst(linkedList *L){
  linkedNode *curr;
  curr = L->head;
  for(int i = 0; i<1; i++){
    printf("**  get first 연결리스트: %p[%s, %p]\n", curr, curr->data, curr->link);
    curr = curr->link;
  }
}
void getlast(linkedList *L){
  linkedNode *preN, *lastN;
  linkedNode *curr;
  //curr = L->head;
  if(L->head == NULL)
    printf("Empty List\n");
  else if (L->head->link == NULL)
    L->head = NULL;
  else {
    preN = L->head, lastN = preN->link;;
    while(lastN->link != NULL)
      preN = preN->link, lastN = preN->link;
    printf("**  get last  연결리스트: %p[%s, %p]\n", lastN, lastN, lastN->link);
  }
}
void nextnode(linkedList *L){
  linkedNode *curr;
  curr = L->head;
  int count = 0;
  int count_ = 0;
  int input;
  printf("*   노드의 값을 입력해 주세요(1 ~ last)   *");
  while(curr != NULL) {
    //printf("연결리스트: %p[%s, %p]\n", curr, curr->data, curr->link);
    curr = curr->link;
    count++;
  }
  curr = L->head;
  do{
  scanf("%d", &input);
  }while(input > count && input < 0);
  while(curr != NULL) {
    if(input == count_)
      printf("**  %d 번째의 다음 node: %p[%s, %p]\n", input, curr, curr->data, curr->link);
    curr = curr->link;
    count_++;
  }
  printf("\n");
}
void getCount(linkedList *L){
  linkedNode *curr;
  curr = L->head;
  int count = 0;
  while(curr != NULL) {
    //printf("연결리스트: %p[%s, %p]\n", curr, curr->data, curr->link);
    curr = curr->link;
    count++;
  }
  printf("**  get count of 연결리스트: %d\n", count);
}
  
int main(){
  //연결리스트 인스턴스(list1) 생성하기
  linkedList *list1 = createLinkedList();
  //리스트(list1)에 노드(n1, n2, n3) 삽입(insert)하기
  insertLastNode(list1, "월");
  insertLastNode(list1, "화");
  insertLastNode(list1, "수");
  insertLastNode(list1, "목");
  insertLastNode(list1, "금");
  insertLastNode(list1, "토");
  insertLastNode(list1, "일");
  //과제 4가지
  getfirst(list1);
  getlast(list1);
  nextnode(list1);
  getCount(list1);
  
  //연결리스트 출력하기
  printLinkedList(list1);
  //리버싱 후 출력하기
  reverseLinkedList(list1);
  printLinkedList(list1);
  //연결리스트 삭제하기->출력하기
  for (; list1->head;){
    deleteLastNode(list1);
    printLinkedList(list1);
  }
  getchar();
  return 0;
}
```
