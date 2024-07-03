#include "../include/grid.hpp"

#include <vector>

#include "../include/apple.hpp"

GameGrid::GameGrid(int width, int height) {
  this->width = width;
  this->height = height;
  this->apples = std::vector<Apple>();
}

void GameGrid::addApple() { this->apples.push_back(Apple(this)); }