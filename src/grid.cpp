#include "../include/grid.hpp"

#include <vector>

#include "../include/apple.hpp"

GameGrid::GameGrid(int width, int height) {
  this->width = width;
  this->height = height;
  this->apples = std::vector<Apple>();
}

void GameGrid::addApple() { this->apples.push_back(Apple(this)); }

void GameGrid::removeApple(int x, int y) {
  for (int i = 0; i < this->apples.size(); ++i) {
    if (this->apples[i].x == x && this->apples[i].y == y) {
      this->apples.erase(this->apples.begin() + i);
      break;
    }
  }
}