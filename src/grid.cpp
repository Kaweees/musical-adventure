#include "../include/grid.hpp"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

GameGrid::GameGrid(int width, int height) {
  this->width = width;
  this->height = height;
}
