#include "../include/grid.hpp"
#include "../include/apple.hpp"

#include <vector>

GameGrid::GameGrid(int width, int height) {
  this->width = width;
  this->height = height;
  this->apples = std::vector<Apple>();
}

void GameGrid::addApple() {
  this->apples.push_back(Apple(this));
}