#include "obstacle.h"

using namespace std;

void Obstacle::initObject(enums::ObstacleType obstacleType, int length, int width, int startX, int startY)
{
  this->obstacleType = obstacleType;
  this->length = length;
  this->width = width;
  this->startX = startX;
  this->startY = startY;
  setDimension();
}

void Obstacle::setDimension()
{
  switch (this->obstacleType)
  {
  case enums::RIGHT_TRIANGLE:
    coordinat[0][1] = startX;
    coordinat[0][2] = startY;
    coordinat[1][1] = startX;
    coordinat[0][2] = startY - width;
    coordinat[2][1] = startX + length;
    coordinat[2][2] = startY - width;
  case enums::RECTANGLE:
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