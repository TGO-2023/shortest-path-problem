#include <iostream>
#include "obstacle-type.h"

class Obstacle
{
public:
  enums::ObstacleType obstacleType;
  int width, length, startX, startY;
  int coordinat[4][4];
  void initObject(enums::ObstacleType obstacleType, int length, int width, int startX, int startY);

private:
  void setDimension();
};