#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30

typedef struct graphType {
    int n;
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

void createGraph(graphType *g) {
  int i, j;
  g->n = 0;
  for (i = 0; i < MAX_VERTEX; i++) {
    for (j = 0; j < MAX_VERTEX; j++)
      g->adjMatrix[i][j] = 0;
  }
}

void insertVertex(graphType *g, int v) {
  if (((g->n) + 1) > MAX_VERTEX) {
    printf("그래프 정점의 개수를 초과하였습니다!\n");
    return;
  }
  g->n++;
}

void insertEdge(graphType *g, int u, int v) {
  if (u >= g->n || v >= g->n) {
    printf("그래프에 없는 정점입니다!\n");
    return;
  }
  g->adjMatrix[u][v] = 1;
  g->adjMatrix[v][u] = 1;
}

void print_adjMatrix(graphType *g) {
  int i, j;
  for (i = 0; i < g->n; i++) {
    printf("\n\t\t");
    for (j = 0; j < g->n; j++)
      printf("%d ", g->adjMatrix[i][j]);
  }
}

int main() {
  int i;
  graphType *G;
  G = (graphType *) malloc(sizeof(graphType));

  createGraph(G);

  for (i = 0; i < 8; i++) {
    insertVertex(G, i);
  }
  insertEdge(G, 0, 1);
  insertEdge(G, 0, 2);
  insertEdge(G, 1, 0);
  insertEdge(G, 1, 3);
  insertEdge(G, 1, 4);
  insertEdge(G, 2, 0);
  insertEdge(G, 2, 5);
  insertEdge(G, 2, 6);
  insertEdge(G, 3, 1);
  insertEdge(G, 3, 7);
  insertEdge(G, 4, 1);
  insertEdge(G, 4, 7);
  insertEdge(G, 5, 2);
  insertEdge(G, 5, 7);
  insertEdge(G, 6, 2);
  insertEdge(G, 6, 7);
  insertEdge(G, 7, 3);
  insertEdge(G, 7, 4);
  insertEdge(G, 7, 5);
  insertEdge(G, 7, 6);

  printf("\nG의 인접 행렬");
  print_adjMatrix(G);

  return 0;
}
