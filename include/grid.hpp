#pragma once

#include <vector>

class Apple; // Forward declaration

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
  // The apple on the game grid
  std::vector<Apple> apples;

  // Add an apple to the game grid
  void addApple();
};
