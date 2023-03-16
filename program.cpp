#include <iostream>
#include <string.h>
#include <list>
#define MAX 10
#define INFINITY INT_MAX

using namespace std;

void djikstra(int graph[MAX][MAX], int n, int start)
{
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
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
      printf("\nDistance from source to %d: %d", i, distance[i]);
}

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

// Enum
// https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-enum-bahasa-c-plus-plus/#:~:text=Format%20Penulisan%20Tipe%20Data%20Enum%20C%2B%2B&text=Format%20dasarnya%20adalah%20sebagai%20berikut,%2C%20kamis%2C%20jumat%2C%20sabtu%7D%3B
enum ObstacleType
{
  RIGHT_TRIANGLE,
  SQUARE,
  RECTANGLE
};
// Class Obstacle
class Obstacle
{
public:
  ObstacleType obstacleType;
  int width, length, startX, startY;
  int coordinat[4][4];
  Obstacle(ObstacleType obstacleType, int length, int width, int startX, int startY)
  {
    this->obstacleType = obstacleType;
    this->length = length;
    this->width = width;
    this->startX = startX;
    this->startY = startY;
    setDimension();
  }

private:
  void setDimension()
  {
    switch (this->obstacleType)
    {
    case RIGHT_TRIANGLE:
      coordinat[0][1] = startX;
      coordinat[0][2] = startY;
      coordinat[1][1] = startX;
      coordinat[0][2] = startY - width;
      coordinat[2][1] = startX + length;
      coordinat[2][2] = startY - width;
    case RECTANGLE:
      coordinat[0][1] = startX;
      coordinat[0][2] = startY;
      coordinat[1][1] = startX + length;
      coordinat[1][2] = startY;
      coordinat[2][1] = startX;
      coordinat[2][2] = startY - width;
      coordinat[3][1] = startX + length;
      coordinat[3][2] = startY - width;
    default:
      cout << "INVALID OBJECT ";
    }
  }
};

// Class Arena
class Arena
{
public:
  int xSource, ySource, xDestination, yDestination, xBoundary, yBoundary;
  list<Obstacle> obstacleList;
  Arena(list<Obstacle> obstacleList, int xBoundary, int yBoundary)
  {
    this->obstacleList = obstacleList;
    this->xSource = 0;
    this->ySource = yBoundary;
    this->xDestination = xBoundary;
    this->yDestination = 0;
    this->xBoundary = xBoundary;
    this->yBoundary = yBoundary;
  }
};

int main()
{
  int graph[MAX][MAX];
  fillArray(graph, MAX, INFINITY);

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
      if (graph[i][j] == INFINITY && graph[j][i] == INFINITY)
        scanf("%d", &graph[i][j]);
      else
      {
        graph[i][j] = graph[j][i];
        printf("%d\n", graph[i][j]);
      }
    }
  }

  List<Obstacle> obstacleList = new ArrayList<>();
  Obstacle obstacle1 = new Obstacle(ObstacleType.RECTANGLE, 150, 100, 50, 450);
  Obstacle obstacle2 = new Obstacle(ObstacleType.RECTANGLE, 100, 100, 50, 300);
  Obstacle obstacle3 = new Obstacle(ObstacleType.RIGHT_TRIANGLE, 100, 150, 250, 400);
  Obstacle obstacle4 = new Obstacle(ObstacleType.RECTANGLE, 150, 100, 200, 200);
  Obstacle obstacle5 = new Obstacle(ObstacleType.RECTANGLE, 50, 100, 400, 150);
  Obstacle obstacle6 = new Obstacle(ObstacleType.RECTANGLE, 100, 50, 350, 450);

  Integer xBoundary = 500;
  Integer yBoundary = 500;
  Arena arena = new Arena(obstacleList, xBoundary, yBoundary);

  return 0;
}
