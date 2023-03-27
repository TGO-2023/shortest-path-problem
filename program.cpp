#include "arena.h"
#include <string>
#include <climits>

#define MAX 10
#define INFINITY 9999

void djikstra(int graph[MAX][MAX], int n, int start)
{
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = graph[i][j];

  for (i = 0; i < n; i++)
  {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1)
  {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i])
      {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i])
        {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  for (i = 0; i < n; i++)
    if (i != start)
    {
      printf("\nDistance from source to %d: %d", i, distance[i]);
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
  fillArray(graph, MAX, INFINITY);

  int n;
  // printf("\nTotal nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    // printf("\nNodes %d\n", i);
    for (int j = 0; j < n; j++)
    {
      // printf("Distance to Node %d: ", j);
      if (i == j)
        graph[i][j] = 0;
      if (graph[i][j] == INFINITY && graph[j][i] == INFINITY)
        scanf("%d", &graph[i][j]);
      else
      {
        graph[i][j] = graph[j][i];
        // printf("%d\n", graph[i][j]);
      }
    }
  }
  int startNode;
  // printf("\nStarting nodes: ");
  scanf("%d", &startNode);

  djikstra(graph, n, startNode);
  return 0;
}