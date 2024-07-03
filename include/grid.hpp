#pragma once

#include <stdbool.h>

class GameGrid {
  public:
  // Constructor to initialize memory
  GameGrid(int width, int height);

  // Destructor to free the memory allocated
  ~GameGrid() = default;

  // The width of the game grid
  int width;
  // The height of the game grid
  int height;
};
