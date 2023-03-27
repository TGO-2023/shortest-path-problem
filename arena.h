#include <list>
#include "obstacle.h"

class Arena
{
public:
  int xSource, ySource, xDestination, yDestination, xBoundary, yBoundary;
  std::list<Obstacle> obstacleList;
  Arena(std::list<Obstacle> obstacleList, int xBoundary, int yBoundary)
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