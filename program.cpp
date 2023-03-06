#include <iostream>
#include <string.h>

#define MAX 10
#define INFINITY INT_MAX
#define MINUS_INFINITY INT_MIN

using namespace std;

void printSolution(int graph[MAX][MAX], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%d ", graph[i][j]);
    printf("\n");
  }
}

void fillArray(int graph[MAX][MAX], int n, int value)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      graph[i][j] = value;
}

int main()
{
  int graph[MAX][MAX];
  fillArray(graph, MAX, MINUS_INFINITY);

  int n;
  printf("\nTotal nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("\nNodes %d\n", i);
    for (int j = 0; j < n; j++)
    {
      printf("Distance to Node %d: ", j);
      if (i == j)
        graph[i][j] = 0;
      if (graph[i][j] == MINUS_INFINITY && graph[j][i] == MINUS_INFINITY)
        scanf("%d", &graph[i][j]);
      else
      {
        graph[i][j] = graph[j][i];
        printf("%d\n", graph[i][j]);
      }
    }
  }

  printSolution(graph, n);
  return 0;
}
