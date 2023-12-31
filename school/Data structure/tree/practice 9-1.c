#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TNode {
    int data;
    struct TNode *left;
    struct TNode *right;
} TNode;

#define MAX_QUEUE_SIZE 100
typedef TNode *element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void error(char *message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}

void init_queue(Queue *q) {
  q->front = q->rear = 0;
}

int is_empty(Queue *q) {
  return (q->front == q->rear);
}

int is_full(Queue *q) {
  return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, element item) {
  if (is_full(q)) printf("queue is full\n");
  else {
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
  }
}

element dequeue(Queue *q) {
  if (is_empty(q)) printf("queue is empty\n");
  else {
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
  }
}

void level_order(TNode *ptr) {
  // 큐 생성 후 초기화
  Queue q;
  init_queue(&q);
  if (ptr == NULL) return;
  // 큐에 ptr 삽입
  enqueue(&q, ptr);
  // 큐가 비어있지 않을 때 반복
  while (!is_empty(&q)) {
    // 큐에서 꺼낸 노드를 ptr에 대입하여 데이터 출력
    TNode *current = dequeue(&q);
    printf(" [%d] ", current->data);

    // 노트 ptr의 왼쪽 노드와 오른쪽 노드가 있으면 각각을 큐에 삽입
    if (current->left != NULL)
      enqueue(&q, current->left);
    if (current->right != NULL)
      enqueue(&q, current->right);
  }
}

TNode n1 = {1, NULL, NULL};
TNode n2 = {4, &n1, NULL};
TNode n3 = {16, NULL, NULL};
TNode n4 = {25, NULL, NULL};
TNode n5 = {20, &n3, &n4};
TNode n6 = {15, &n2, &n5};
TNode *root = &n6;

int main() {
  printf("레벨 순회 = ");
  level_order(root);
  printf("\n");

  return 0;
}

